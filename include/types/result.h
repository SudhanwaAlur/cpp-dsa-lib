#ifndef RESULT_H
#define RESULT_H

#include "errorcodes.h"
namespace types
{
    template<typename T>
    class Result
    {
        public:
            Result(T val, bool b, int e):res(val), hasValue(b), errorCode(e){}

            T Value(){
                return res;
            }

            int ErrorCode(){
                return errorCode;
            }

            static Result FromValue(T val){
                return Result(val, true,-1);
            }

            static Result FromError(int err){
                return Result(-1, false, err);
            }

            bool HasValue(){
                return hasValue;
            }
        private:
            T res;
            bool hasValue;
            int errorCode;

    };
}


#endif