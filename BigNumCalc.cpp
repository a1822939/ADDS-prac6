#include "BigNumCalc.h"
#include <string>


    BigNumCalc::BigNumCalc(){

    }
    BigNumCalc::~BigNumCalc(){

    }

    std::list<int> BigNumCalc::buildBigNum(std::string numString){
        std::list<int> numList;
        
        for (int i = 0; i < numString.size(); i++)
        {
            int charInt = numString.at(i)-48;
            numList.push_back(charInt);
        }

        return numList;
    }
    std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2){
        
        
    }
    std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2){

    }
    std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){

    }