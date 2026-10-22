#include <iostream>
#include "C:\DSA_BTVN\stack_queue\DSA_QUEUE\QueueList.h"
#include "C:\DSA_BTVN\stack_queue\DSA_QUEUE\QueueLinkedList.h"
using namespace std;

int main() {
    QueueList queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
cout << "Queue dung List" << endl;
    cout << "Front: " << queue.front() << endl;
    cout << "Dequeue: " << queue.dequeue() << endl;
    cout << "Front after dequeue: " << queue.front() << endl;
    cout << "Size: " << queue.size() << endl;

    cout << endl;

    cout << "Queue dung Linked List" << endl;

    QueueLinkedList queueLinkedList;

    queueLinkedList.enqueue(10);
    queueLinkedList.enqueue(20);
    queueLinkedList.enqueue(30);

    cout << "Front: " << queueLinkedList.front() << endl;
    cout << "Dequeue: " << queueLinkedList.dequeue() << endl;
    cout << "Front after dequeue: "
         << queueLinkedList.front() << endl;
    cout << "Size: " << queueLinkedList.size() << endl;


    return 0;
}



