#include "C:\DSA_BTVN\stack_queue\DSA_QUEUE\QueueList.h"
#include <stdexcept>

bool QueueList::isEmpty() {
    return danhSach.getSize() == 0;
}

void QueueList::enqueue(int item) {
    danhSach.themCuoi(item);
}

int QueueList::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue rong");
    }

    int item = danhSach.layViTri(0);
    danhSach.xoaDau();

    return item;
}

int QueueList::front() {
    if (isEmpty()) {
        throw std::out_of_range("Queue rong");
    }

    return danhSach.layViTri(0);
}

int QueueList::size() {
    return danhSach.getSize();
}
