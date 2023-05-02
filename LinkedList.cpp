#include "LinkedList.h"
#include <iostream>
#include <limits>

LinkedList::LinkedList()
{
    this->head = nullptr;
}

LinkedList::LinkedList(int *array, int len)
{
    Node *tailNode = new Node(array[len - 1], nullptr);
    Node *prevNode = tailNode;

    for (int i = len - 2; i > 0; i--)
    {
        Node *newNode = new Node(array[i], prevNode);
        prevNode = newNode;
    }

    Node *headNode = new Node(array[0], prevNode);
    head = headNode;
}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        deletePosition(1);
    }
}

void LinkedList::insertPosition(int pos, int newNum)
{
    if (pos <= 1)
    {
        Node *newNode = new Node(newNum, head);
        head = newNode;
        return;
    }
    else if (pos >= listSize())
    {
        Node *prevNode = getNode(listSize());
        Node *newNode = new Node(newNum, prevNode->getLink());
        prevNode->setLink(newNode);
        return;
    }
    else
    {
        Node *prevNode = getNode(pos - 1);
        Node *newNode = new Node(newNum, prevNode->getLink());
        prevNode->setLink(newNode);
        return;
    }
}

bool LinkedList::deletePosition(int pos)
{
    if (!validPos(pos))
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

    Node *targetNode = getNode(pos);
    Node *prevNode = getNode(pos - 1);
    prevNode->setLink(targetNode->getLink());
    delete targetNode;
    return true;
}

int LinkedList::get(int pos)
{
    if (!validPos(pos))
    {
        return std::numeric_limits<int>::max();
    }

    return getNode(pos)->getData();
}

int LinkedList::search(int target)
{
    int currentPos = 0;
    Node *currentNode = head;

    while (currentNode != nullptr && currentNode->getData() != target)
    {
        currentNode = currentNode->getLink();
        currentPos++;
    }
    if (currentNode == nullptr)
    {
        return -1;
    }
    return currentPos;
}

void LinkedList::printList()
{
    if (listSize() == 0)
    {
        return;
    }

    Node *currentNode = head;
    int currentPos = 1;
    std::cout << '[';
    while (currentNode != nullptr && currentPos < listSize())
    {
        std::cout << currentNode->getData();
        std::cout << ' ';
        currentNode = currentNode->getLink();
        currentPos++;
    }
    std::cout << currentNode->getData();
    std::cout << ']';
}

////////////////////////////////////////////////////

Node *LinkedList::getNode(int pos)
{
    int currentPos = 1;
    Node *currentNode = head;

    while (currentNode != nullptr && currentPos < pos)
    {
        currentNode = currentNode->getLink();
        currentPos++;
    }
    return currentNode;
}

int LinkedList::listSize()
{
    int length = 0;
    Node *currentNode = head;

    while (currentNode != nullptr)
    {
        currentNode = currentNode->getLink();
        length++;
    }

    return length;
}

bool LinkedList::validPos(int pos)
{

    if (pos <= 0 || pos > listSize())
    {
        return false;
    }
    return true;
}