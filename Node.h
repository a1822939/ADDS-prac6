#ifndef NODE_H
#define NODE_H

class Node
{
private:
    int data;
    Node *link;

public:
    Node();
    Node(int data);
    Node(int data, Node *link);
    int getData();
    Node *getLink();
    void setData(int data);
    void setLink(Node *link);
    ~Node();
};

#endif