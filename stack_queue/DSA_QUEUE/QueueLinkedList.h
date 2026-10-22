#ifndef QUEUELINKEDLIST_H
#define QUEUELINKEDLIST_H

struct QueueNode {
    int data;
    QueueNode* next;
};

class QueueLinkedList {
private:
    QueueNode* dau;
    QueueNode* cuoi;
    int soLuong;

public:
    QueueLinkedList();
    ~QueueLinkedList();

    bool isEmpty();
    void enqueue(int item);
    int dequeue();
    int front();
    int size();
};

#endif
