
#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H

class StackLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* dau;
    int soLuong;

public:
    StackLinkedList();
    ~StackLinkedList();

    bool isEmpty();
    void push(int item);
    int pop();
    int size();
    int top();
};

#endif

