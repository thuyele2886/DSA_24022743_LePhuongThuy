#include "C:\DSA_BTVN\stack_queue\DSA_QUEUE\QueueLinkedList.h"
#include <stdexcept>

QueueLinkedList::QueueLinkedList() {
    dau = NULL;
    cuoi = NULL;
    soLuong = 0;
}

QueueLinkedList::~QueueLinkedList() {
    while (dau != NULL) {
        QueueNode* p = dau;
        dau = dau->next;
        delete p;
    }

    cuoi = NULL;
    soLuong = 0;
}

bool QueueLinkedList::isEmpty() {
    return dau == NULL;
}

void QueueLinkedList::enqueue(int item) {
    QueueNode* p = new QueueNode;

    p->data = item;
    p->next = NULL;

    if (dau == NULL) {
        dau = p;
        cuoi = p;
    } else {
        cuoi->next = p;
        cuoi = p;
    }

    soLuong++;
}

int QueueLinkedList::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue rong");
    }

    QueueNode* p = dau;
    int item = p->data;

    dau = dau->next;
    delete p;

    soLuong--;

    if (dau == NULL) {
        cuoi = NULL;
    }

    return item;
}

int QueueLinkedList::front() {
    if (isEmpty()) {
        throw std::out_of_range("Queue rong");
    }

    return dau->data;
}

int QueueLinkedList::size() {
    return soLuong;
}
