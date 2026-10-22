#ifndef QUEUELIST_H
#define QUEUELIST_H

#include "List.h"

class QueueList {
private:
    List danhSach;

public:
    QueueList() : danhSach(10) {}

    bool isEmpty();
    void enqueue(int item);
    int dequeue();
    int front();
    int size();
};

#endif
