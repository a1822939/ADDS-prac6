#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int *array, int len)
{
    this->head = nullptr;
    for (int i = 0; i < len; i++)
    {
        insertPosition(i + 1, array[i]);
    }
}

LinkedList::~LinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current-> getLink();
        delete current;
        current = next;
    }
}

void LinkedList::insertPosition(int pos, int newNum)
{
    if (pos <= 1)
    {
        head = new Node(newNum, head);
        return;
    }

    Node *current = head;
    for (int i = 1; i < pos - 1 && current != nullptr; i++)
    {
        current = current->getLink();
    }

    if (current == nullptr)
    {
        return;
    }

    current->setLink(new Node(newNum, current->getLink()));
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
        head = head->  getLink();
        delete temp;
        return true;
    }

    Node *current = head;
    for (int i = 1; i < pos - 1 && current != nullptr; i++)
    {
        current = current->getLink();
    }

    if (current == nullptr || current->getLink() == nullptr)
    {
        return false;
    }

    Node *temp = current-> getLink();
    current->setLink(temp-> getLink());
    delete temp;

    return true;
}

int LinkedList::get(int pos)
{
    if (pos < 1 || head == nullptr)
    {
        return std::numeric_limits<int>::max();
    }

    Node *current = head;
    for (int i = 1; i < pos && current != nullptr; i++)
    {
        current = current->getLink();
    }

    if (current == nullptr)
    {
        return std::numeric_limits<int>::max();
    }

    return current->getData();
}

int LinkedList::search(int target)
{
    Node *current = head;
    int index = 1;

    while (current != nullptr && current->getData() != target)
    {
        index++;
        current = current->getLink();
    }

    if (current == nullptr)
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
    for (Node *current = head; current != nullptr; current = current-> getLink())
    {
        std::cout << current->getData();
        if (current->  getLink() != nullptr)
        {
            std::cout << ' ';
        }
    }
    std::cout << ']';
}