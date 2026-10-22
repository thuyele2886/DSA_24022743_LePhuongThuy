
#include <iostream>
#include "C:/DSA_BTVN/StackList.h"
#include "C:/DSA_BTVN/stack_queue/DSA_Stack_Queue/StackLinkedList.h"


using namespace std;

int main() {
    StackList stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top: " << stack.top() << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout << "Size: " << stack.size() << endl;

    cout << "Top after pop: " << stack.top() << endl;

    cout << "\n--- dung Linked List ---" << endl;

    StackLinkedList stack2;

    stack2.push(10);
    stack2.push(20);
    stack2.push(30);

    cout << "Top: " << stack2.top() << endl;
    cout << "Pop: " << stack2.pop() << endl;
    cout << "Size: " << stack2.size() << endl;
    cout << "Top after pop: " << stack2.top() << endl;


    return 0;
}
