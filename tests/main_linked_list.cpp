#include "dsa/linked_list.h"
#include <iostream>

template<typename T>
void printAllElements(std::vector<T> elements){
    std::cout<<"Elements of the Linked List are: "<<std::endl;
    for(auto tmp:elements){
        std::cout<<tmp<<"\t";
    }
    std::cout<<std::endl;
}

int main(){
    dsa::LinkedList<int> o_LinkedList;
    o_LinkedList.pushBack(10);
    o_LinkedList.pushBack(20);
    o_LinkedList.pushBack(30);
    printAllElements(o_LinkedList.getAllElements());

    o_LinkedList.insert(50,4);
    printAllElements(o_LinkedList.getAllElements());

    o_LinkedList.insert(60,2);
    printAllElements(o_LinkedList.getAllElements());

    o_LinkedList.insert(75,1);
    printAllElements(o_LinkedList.getAllElements());


    std::cout<<"Element at position 4 is: "<<o_LinkedList.getElementAt(4).Value()<<std::endl;

    if(o_LinkedList.removeElementAt(4).HasValue()){
        if(o_LinkedList.removeElementAt(1).HasValue()){
            if(o_LinkedList.removeElementAt(4).HasValue()){
                printAllElements(o_LinkedList.getAllElements());
            }
        }
    }

    o_LinkedList.popFront();
    o_LinkedList.popLast();
    printAllElements(o_LinkedList.getAllElements());

    o_LinkedList.pushBack(79);
    o_LinkedList.pushBack(68);
    o_LinkedList.pushBack(92);
    printAllElements(o_LinkedList.getAllElements());

    auto res = o_LinkedList.search(92);
    if(res.HasValue()){
        std::cout<<"Element 92 found at pos: "<<res.Value()<<std::endl;
        res = o_LinkedList.search(79);
        if(res.HasValue()){
            std::cout<<"Element 79 found at pos: "<<res.Value()<<std::endl;
            res = o_LinkedList.search(110);
            if(!res.HasValue()){
                std::cout<<"Element 110 not found. ErrorCode: "<<res.ErrorCode()<<std::endl;
            }
        }
    }

        
    return 0;
}