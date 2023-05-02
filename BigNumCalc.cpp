#include "BigNumCalc.h"
#include <iostream>
#include <list>

BigNumCalc::BigNumCalc()
{
}
BigNumCalc::~BigNumCalc()
{
}

std::list<int> BigNumCalc::buildBigNum(std::string numString)
{
    std::list<int> numList;

    for (unsigned int i = 0; i < numString.size(); i++)
        {
            int charInt = numString.at(i) - 48;
            numList.push_back(charInt);
        }

    return numList;
}
std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2)
{
    std::list<int> result;
    int carry = 0;
    while (!num1.empty() || !num2.empty() || carry)
    {
        int sum = carry;
        if (!num1.empty())
        {
            sum += num1.back();
            num1.pop_back();
        }
        if (!num2.empty())
        {
            sum += num2.back();
            num2.pop_back();
        }
        result.push_front(sum % 10);
        carry = sum / 10;
    }
    return result;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2)
{
    std::list<int> result;
    int borrow = 0;
    while (!num1.empty() || !num2.empty())
    {
        int sub = borrow;
        if (!num1.empty())
        {
            sub += num1.back();
            num1.pop_back();
        }
        if (!num2.empty())
        {
            sub -= num2.back();
            num2.pop_back();
        }
        if (sub < 0)
        {
            sub += 10;
            borrow = -1;
        }
        else
        {
            borrow = 0;
        }
        result.push_front(sub);
    }
    while (!result.empty() && result.front() == 0)
    {
        result.pop_front();
    }
    return result;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2)
{
    int mul = num2.front();
    std::list<int> total;
    std::list<int> powTen;
    powTen.push_front(0);

    while (!num1.empty())
    {
        int amount = 0;
        if (!num1.empty())
        {
            amount += (num1.back() * mul);
            num1.pop_back();
        }

        total.push_front(amount % 10);
        powTen.push_front(amount / 10);
    }

    return add(total, powTen);
}