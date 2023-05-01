#include "Node.h"

Node::Node()
{
    this->data = 0;
    this->link = nullptr;
}

Node::Node(int data, Node *link)
{
    this->data = data;
    this->link = link;
}
Node::Node(int data)
{
    this->data = data;
}

int Node::getData()
{
    return data;
}
Node *Node::getLink()
{
    return link;
}
void Node::setData(int data)
{
    this->data = data;
}
void Node::setLink(Node *link)
{
    this->link = link;
}

Node::~Node() {}