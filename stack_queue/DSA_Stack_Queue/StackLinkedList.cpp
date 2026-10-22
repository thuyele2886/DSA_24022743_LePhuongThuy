
#include "StackLinkedList.h"
#include <stdexcept>

using namespace std;

StackLinkedList::StackLinkedList() {
    dau = NULL;
    soLuong = 0;
}

StackLinkedList::~StackLinkedList() {
    while (dau != NULL) {
        Node* p = dau;
        dau = dau->next;
        delete p;
    }
}

bool StackLinkedList::isEmpty() {
    return dau == NULL;
}

void StackLinkedList::push(int item) {
    Node* p = new Node;

    p->data = item;
    p->next = dau;

    dau = p;
    soLuong++;
}

int StackLinkedList::pop() {
    if (isEmpty()) {
        throw out_of_range("Stack rong");
    }

    Node* p = dau;
    int item = p->data;

    dau = dau->next;
    delete p;

    soLuong--;

    return item;
}

int StackLinkedList::size() {
    return soLuong;
}

int StackLinkedList::top() {
    if (isEmpty()) {
        throw out_of_range("Stack rong");
    }

    return dau->data;
}

