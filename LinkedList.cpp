#include "LinkedList.h"
#include <limits>
#include <iostream>

LinkedList::LinkedList()
{
    head = nullptr;
}
LinkedList::LinkedList(int *array, int len)
{

    for (int i = 0; i < len; i++)
    {
    }
}
LinkedList::~LinkedList()
{
    Node *tempNode = head;
    while (tempNode != nullptr)
    {
        Node *next = tempNode->getLink();
        delete tempNode;
        tempNode = next;
    }
}

void LinkedList::insertPosition(int pos, int newNum)
{
    if (pos <= 1)
    {
        Node *headNode = new Node(newNum, head);
        return;
    }

    Node *tempNode = head;
    for (int i = 1; i < pos - 1; i++)
    {
        if (tempNode == nullptr)
        {
            return;
        }
        tempNode = tempNode->getLink();
    }

    tempNode->setLink(new Node(newNum, tempNode->getLink()));
}
bool LinkedList::deletePosition(int pos)
{
    if (pos < 1 || head == nullptr)
    {
        return false;
    }

    if (pos == 1)
    {
        Node *temp = head;
        head = head->getLink();
        delete temp;
        return true;
    }

    Node *tempNode = head;
    for (int i = 1; i < pos - 1 && tempNode != nullptr; i++)
    {
        tempNode = tempNode->getLink();
    }

    if (tempNode == nullptr || tempNode->getLink() == nullptr)
    {
        return false;
    }

    Node *temp = tempNode->getLink();
    tempNode->setLink(temp->getLink());
    delete temp;

    return true;
}

int LinkedList::get(int pos)
{
    if (pos < 1 || head == nullptr)
    {
        return std::numeric_limits<int>::max();
    }

    Node *tempNode = head;
    for (int i = 1; i < pos && tempNode != nullptr; i++)
    {
        tempNode = tempNode->getLink();
    }

    if (tempNode == nullptr)
    {
        return std::numeric_limits<int>::max();
    }

    return tempNode->getData();
}

int LinkedList::search(int target)
{
    Node *tempNode = head;
    int index = 1;

    while (tempNode != nullptr && tempNode->getData() != target)
    {
        index++;
        tempNode = tempNode->getLink();
    }

    if (tempNode == nullptr)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

void LinkedList::printList()
{
    std::cout << '[';
    for (Node *tempNode = head; tempNode != nullptr; tempNode = tempNode->getLink())
    {
        std::cout << tempNode->getData();
        if (tempNode->getLink() != nullptr)
        {
            std::cout << ' ';
        }
    }
    std::cout << ']';
}