#ifndef LINKED_LIST_H
#define LINKED_LIST_H 
#include <memory>
#include <vector>
#include "types/result.h"
namespace dsa
{
    template<typename T>
    class LinkedList
    {
        public:
            LinkedList() = default;
            ~LinkedList() = default;

            void pushBack(T value){
                auto newNode = std::make_unique<Node>(value);
                if(head == nullptr){
                    head = std::move(newNode);
                    return;
                }

                Node* current = head.get();
                while(current->next){
                    current = current->next.get();
                }
                current->next = std::move(newNode); 
            }

            types::Result<T> insert(T value, int pos){
                if(pos == 1){
                    auto newNode = std::make_unique<Node>(value);
                    newNode->next = std::move(head);
                    head = std::move(newNode);
                    return types::Result<T>::FromValue(head->data);
                }
                Node* current = head.get();
                Node* previous = nullptr;
                int count = 1;    
                while(current->next){
                    if(count == pos){
                        auto newNode = std::make_unique<Node>(value);
                        newNode->next = std::move(previous->next);
                        previous->next = std::move(newNode);
                        return types::Result<T>::FromValue(previous->next->data);
                    }
                    previous = current;
                    current = current->next.get();
                    count++;
                }
                if(count +1 == pos){
                    auto newNode = std::make_unique<Node>(value);
                    current->next = std::move(newNode);
                    return types::Result<T>::FromValue(current->next->data);
                }
                return types::Result<T>::FromError(errorcodes::kRequestedPositionOutOfRange);
            }

            types::Result<T> getElementAt(int pos){
                Node* current = head.get();
                if(pos == 1){
                    return types::Result<T>::FromValue(current->data);
                }
                int count = 1;
                while(current->next){
                    if(count == pos){
                        return types::Result<T>::FromValue(current->data);
                    }
                    current = current->next.get();
                    count++;
                }
                return types::Result<T>::FromError(errorcodes::kRequestedPositionOutOfRange);
            }

            std::vector<T> getAllElements(){
                std::vector<T> tmp;
                Node* current = head.get();
                while(current->next){
                    tmp.push_back(current->data);
                    current = current->next.get();
                }
                tmp.push_back(current->data);
                return tmp;
            }

            types::Result<int> removeElementAt(int pos){
                if(pos == 1){
                    auto newHead = std::move(head->next);
                    head.reset();
                    head=std::move(newHead);
                    return types::Result<T>::FromValue(true);
                }
                Node* current = head.get();
                Node* previous = nullptr;
                int count = 1;    
                while(current->next){
                    if(count == pos){
                        previous->next = std::move(current->next);
                        return types::Result<T>::FromValue(true);
                    }
                    previous = current;
                    current = current->next.get();
                    count++;
                }
                if(count == pos){
                    previous->next.reset();
                    return types::Result<T>::FromValue(true);
                }
                return types::Result<T>::FromError(errorcodes::kRequestedPositionOutOfRange);
            }

            void popFront(){
                auto newHead = std::move(head->next);
                head.reset();
                head=std::move(newHead);
            }

            void popLast(){
                Node* current = head.get();
                Node* previous = nullptr;  
                while(current->next){
                    previous = current;
                    current = current->next.get();
                }
                previous->next.reset();
            }

            types::Result<int> search(T element){
                Node* current = head.get();
                int count =1;
                while(current->next){
                    if(current->data == element){
                        return types::Result<int>::FromValue(count);
                    }
                    count++;
                    current = current->next.get();
                }
                if(current->data == element){
                    return types::Result<int>::FromValue(count);
                }
                return types::Result<int>::FromError(errorcodes::kSearchElementNotFound);
            }


        private:
            struct Node{
                Node() = default;
                Node(T value):data(value),next(nullptr){}
                std::unique_ptr<Node> next;
                T data;
            };

            std::unique_ptr<Node> head;


    };

} // namespace dsa
#endif