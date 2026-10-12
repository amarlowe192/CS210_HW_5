
#include <iostream>
using namespace std;




/*
 * TIME COMPLEXITY
 *
 * array stack
 * push:       O(1)
 * pop:        O(1)
 * peek:       O(1)
 * print:      O(n)
 *
 * LL stack
 * push:       O(1)
 * pop:        O(1)
 * peek:       O(1)
 * print:      O(n)
 *
 * arr queue
 * enqueue:    O(1)
 * dequeue:    O(1)
 * peek:       O(1)
 * print:      O(n)
 *
 * The array queue uses circular indexing. If elements were
 * shifted after every removal instead, dequeue would be O(n).
 *
 * linked queue
 * enqueue:    O(1)
 * dequeue:    O(1)
 * peek:       O(1)
 * print:      O(n)
 *
 * A rear pointer allows insertion without traversing the list.
 * Without a rear pointer, enqueue would be O(n).
 *
 * arr deque
 * pushFront:  O(1)
 * pushBack:   O(1)
 * popFront:   O(1)
 * popBack:    O(1)
 * peekFront:  O(1)
 * peekBack:   O(1)
 * print:      O(n)
 *
 * Circular indexing prevents array elements from needing
 * to be shifted.
 *
 * linked deque
 * pushFront:  O(1)
 * pushBack:   O(1)
 * popFront:   O(1)
 * popBack:    O(1)
 * peekFront:  O(1)
 * peekBack:   O(1)
 * print:      O(n)
 *
 * The linked deque is doubly linked. The previous pointer
 * allows removal from the rear in O(1). With a singly linked
 * list, removing from the rear would require traversal and
 * would therefore be O(n).
 */


class ArrayStack {
private:
    static const int size = 100;

    int data[size];
    int top;

public:

    // Constructor
    ArrayStack() {
        top = -1;
    }


    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }


    // Check if stack is full
    bool isFull() {
        return top == size - 1;
    }


    // Add item to top
    void push(int value) {

        if (isFull()) {
            cout << "Stack is full." << endl;
            return;
        }

        top++;

        data[top] = value;
    }


    // Remove item from top
    int pop() {

        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }

        int value = data[top];

        top--;

        return value;
    }


    // Look at top item without removing it
    int peek() {

        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return data[top];
    }


    // Print stack
    void printStack() {

        cout << "Stack: ";

        for (int i = top; i >= 0; i--) {
            cout << data[i] << " ";
        }

        cout << endl;
    }
};



struct StackNode {
    int data;
    StackNode* next;

    StackNode(int value) {
        data = value;
        next = nullptr;
    }
};



class LinkedStack {
private:
    StackNode* top;

public:

    LinkedStack() {
        top = nullptr;
    }


    bool isEmpty() {
        return top == nullptr;
    }


    void push(int value) {

        StackNode* newNode = new StackNode(value);

        newNode->next = top;

        top = newNode;
    }


    int pop() {

        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }

        StackNode* temp = top;

        int value = top->data;

        top = top->next;

        delete temp;

        return value;
    }


    int peek() {

        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return top->data;
    }


    void printStack() {

        cout << "Stack: ";

        StackNode* temp = top;

        while (temp != nullptr) {

            cout << temp->data << " ";

            temp = temp->next;
        }

        cout << endl;
    }


    ~LinkedStack() {

        while (!isEmpty()) {
            pop();
        }
    }
};


class ArrayQueue {
private:
    static const int SIZE = 100;

    int data[SIZE];

    int front;
    int rear;
    int count;

public:

    ArrayQueue() {
        front = 0;
        rear = 0;
        count = 0;
    }


    bool isEmpty() {
        return count == 0;
    }


    bool isFull() {
        return count == SIZE;
    }


    void enqueue(int value) {

        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }

        data[rear] = value;

        rear = (rear + 1) % SIZE;

        count++;
    }


    int dequeue() {

        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        int value = data[front];

        front = (front + 1) % SIZE;

        count--;

        return value;
    }


    int peek() {

        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return data[front];
    }


    void printQueue() {

        cout << "Queue: ";

        for (int i = 0; i < count; i++) {

            int index = (front + i) % SIZE;

            cout << data[index] << " ";
        }

        cout << endl;
    }
};



struct QueueNode {
    int data;
    QueueNode* next;

    QueueNode(int value) {
        data = value;
        next = nullptr;
    }
};


class LinkedQueue {
private:
    QueueNode* front;
    QueueNode* rear;

public:

    LinkedQueue() {
        front = nullptr;
        rear = nullptr;
    }


    bool isEmpty() {
        return front == nullptr;
    }


    void enqueue(int value) {

        QueueNode* newNode = new QueueNode(value);

        if (isEmpty()) {

            front = newNode;
            rear = newNode;

            return;
        }

        rear->next = newNode;

        rear = newNode;
    }


    int dequeue() {

        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        QueueNode* temp = front;

        int value = front->data;

        front = front->next;

        delete temp;


        // Queue became empty
        if (front == nullptr) {
            rear = nullptr;
        }

        return value;
    }


    int peek() {

        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        return front->data;
    }


    void printQueue() {

        cout << "Queue: ";

        QueueNode* temp = front;

        while (temp != nullptr) {

            cout << temp->data << " ";

            temp = temp->next;
        }

        cout << endl;
    }


    ~LinkedQueue() {

        while (!isEmpty()) {
            dequeue();
        }
    }
};



class ArrayDeque {
private:
    static const int SIZE = 100;

    int data[SIZE];

    int front;
    int rear;
    int count;

public:

    ArrayDeque() {
        front = 0;
        rear = 0;
        count = 0;
    }


    bool isEmpty() {
        return count == 0;
    }


    bool isFull() {
        return count == SIZE;
    }


    void pushBack(int value) {

        if (isFull()) {
            cout << "Deque is full." << endl;
            return;
        }

        data[rear] = value;

        rear = (rear + 1) % SIZE;

        count++;
    }


    void pushFront(int value) {

        if (isFull()) {
            cout << "Deque is full." << endl;
            return;
        }

        front = (front - 1 + SIZE) % SIZE;

        data[front] = value;

        count++;
    }


    int popFront() {

        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return -1;
        }

        int value = data[front];

        front = (front + 1) % SIZE;

        count--;

        return value;
    }


    int popBack() {

        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return -1;
        }

        rear = (rear - 1 + SIZE) % SIZE;

        int value = data[rear];

        count--;

        return value;
    }


    int peekFront() {

        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return -1;
        }

        return data[front];
    }


    int peekBack() {

        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return -1;
        }

        int index = (rear - 1 + SIZE) % SIZE;

        return data[index];
    }


    void printDeque() {

        cout << "Deque: ";

        for (int i = 0; i < count; i++) {

            int index = (front + i) % SIZE;

            cout << data[index] << " ";
        }

        cout << endl;
    }
};


struct DequeNode {
    int data;

    DequeNode* next;
    DequeNode* previous;

    DequeNode(int value) {
        data = value;
        next = nullptr;
        previous = nullptr;
    }
};


class LinkedDeque {
private:
    DequeNode* front;
    DequeNode* rear;

public:

    LinkedDeque() {
        front = nullptr;
        rear = nullptr;
    }


    bool isEmpty() {
        return front == nullptr;
    }


    void pushFront(int value) {

        DequeNode* newNode = new DequeNode(value);

        if (isEmpty()) {

            front = newNode;
            rear = newNode;

            return;
        }

        newNode->next = front;

        front->previous = newNode;

        front = newNode;
    }


    void pushBack(int value) {

        DequeNode* newNode = new DequeNode(value);

        if (isEmpty()) {

            front = newNode;
            rear = newNode;

            return;
        }

        newNode->previous = rear;

        rear->next = newNode;

        rear = newNode;
    }


    int popFront() {

        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return -1;
        }

        DequeNode* temp = front;

        int value = front->data;

        front = front->next;


        if (front == nullptr) {

            rear = nullptr;
        }
        else {

            front->previous = nullptr;
        }


        delete temp;

        return value;
    }


    int popBack() {

        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return -1;
        }

        DequeNode* temp = rear;

        int value = rear->data;

        rear = rear->previous;


        if (rear == nullptr) {

            front = nullptr;
        }
        else {

            rear->next = nullptr;
        }


        delete temp;

        return value;
    }


    int peekFront() {

        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return -1;
        }

        return front->data;
    }


    int peekBack() {

        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return -1;
        }

        return rear->data;
    }


    void printDeque() {

        cout << "Deque: ";

        DequeNode* temp = front;

        while (temp != nullptr) {

            cout << temp->data << " ";

            temp = temp->next;
        }

        cout << endl;
    }


    ~LinkedDeque() {

        while (!isEmpty()) {
            popFront();
        }
    }
};



void testArrayStack() {

    cout << "\n_____________________" << endl;
    cout << "Array Version Test Stack" << endl;
    cout << "_____________________" << endl;

    ArrayStack stack;


    // 1
    cout << "\n1. Push 10" << endl;
    stack.push(10);
    stack.printStack();


    // 2
    cout << "\n2. Push 20" << endl;
    stack.push(20);
    stack.printStack();


    // 3
    cout << "\n3. Push 30" << endl;
    stack.push(30);
    stack.printStack();


    // 4
    cout << "\n4. Push 40" << endl;
    stack.push(40);
    stack.printStack();


    // 5
    cout << "\n5. Peek" << endl;
    cout << "Top: " << stack.peek() << endl;


    // 6
    cout << "\n6. Pop" << endl;
    cout << "Removed: " << stack.pop() << endl;
    stack.printStack();


    // 7
    cout << "\n7. Pop" << endl;
    cout << "Removed: " << stack.pop() << endl;
    stack.printStack();


    // 8
    cout << "\n8. Push 50" << endl;
    stack.push(50);
    stack.printStack();


    // 9
    cout << "\n9. Pop" << endl;
    cout << "Removed: " << stack.pop() << endl;
    stack.printStack();


    // 10
    cout << "\n10. Pop" << endl;
    cout << "Removed: " << stack.pop() << endl;
    stack.printStack();


    // 11
    cout << "\n11. Pop" << endl;
    cout << "Removed: " << stack.pop() << endl;
    stack.printStack();


    // 12 - test empty handling
    cout << "\n12. Attempt pop from empty stack" << endl;
    stack.pop();
}

void testLinkedStack() {

    cout << "\n_____________________" << endl;
    cout << "LinkedList Version Stack Test" << endl;
    cout << "_____________________" << endl;

    LinkedStack stack;

    cout << "\n1. Push 10" << endl;
    stack.push(10);

    cout << "2. Push 20" << endl;
    stack.push(20);

    cout << "3. Push 30" << endl;
    stack.push(30);

    cout << "4. Push 40" << endl;
    stack.push(40);

    cout << "5. Print" << endl;
    stack.printStack();

    cout << "6. Peek: " << stack.peek() << endl;

    cout << "7. Pop: " << stack.pop() << endl;

    cout << "8. Pop: " << stack.pop() << endl;

    cout << "9. Push 50" << endl;
    stack.push(50);

    cout << "10. Pop: " << stack.pop() << endl;

    cout << "11. Pop: " << stack.pop() << endl;

    cout << "12. Pop: " << stack.pop() << endl;

    cout << "13. Attempt empty pop:" << endl;
    stack.pop();
}

void testArrayQueue() {

    cout << "\n_____________________" << endl;
    cout << "Array Version Test Queue" << endl;
    cout << "_____________________" << endl;


    ArrayQueue queue;

    cout << "\n1. Enqueue 10" << endl;
    queue.enqueue(10);

    cout << "2. Enqueue 20" << endl;
    queue.enqueue(20);

    cout << "3. Enqueue 30" << endl;
    queue.enqueue(30);

    cout << "4. Enqueue 40" << endl;
    queue.enqueue(40);

    cout << "5. Print" << endl;
    queue.printQueue();

    cout << "6. Peek: " << queue.peek() << endl;

    cout << "7. Dequeue: " << queue.dequeue() << endl;

    cout << "8. Dequeue: " << queue.dequeue() << endl;

    cout << "9. Enqueue 50" << endl;
    queue.enqueue(50);

    cout << "10. Dequeue: " << queue.dequeue() << endl;

    cout << "11. Dequeue: " << queue.dequeue() << endl;

    cout << "12. Dequeue: " << queue.dequeue() << endl;

    cout << "13. Attempt empty dequeue:" << endl;
    queue.dequeue();
}

void testLinkedQueue() {

    cout << "\n_____________________" << endl;
    cout << "LinkedList Version Test Queue" << endl;
    cout << "_____________________" << endl;


    LinkedQueue queue;

    cout << "\n1. Enqueue 10" << endl;
    queue.enqueue(10);

    cout << "2. Enqueue 20" << endl;
    queue.enqueue(20);

    cout << "3. Enqueue 30" << endl;
    queue.enqueue(30);

    cout << "4. Enqueue 40" << endl;
    queue.enqueue(40);

    cout << "5. Print" << endl;
    queue.printQueue();

    cout << "6. Peek: " << queue.peek() << endl;

    cout << "7. Dequeue: " << queue.dequeue() << endl;

    cout << "8. Dequeue: " << queue.dequeue() << endl;

    cout << "9. Enqueue 50" << endl;
    queue.enqueue(50);

    cout << "10. Dequeue: " << queue.dequeue() << endl;

    cout << "11. Dequeue: " << queue.dequeue() << endl;

    cout << "12. Dequeue: " << queue.dequeue() << endl;

    cout << "13. Attempt empty dequeue:" << endl;
    queue.dequeue();
}

void testArrayDeque() {

    cout << "\n_____________________" << endl;
    cout << "Array deque test" << endl;
    cout << "_____________________" << endl;


    ArrayDeque deque;

    cout << "\n1. Push back 10" << endl;
    deque.pushBack(10);

    cout << "2. Push back 20" << endl;
    deque.pushBack(20);

    cout << "3. Push front 5" << endl;
    deque.pushFront(5);

    cout << "4. Push back 30" << endl;
    deque.pushBack(30);

    cout << "5. Print" << endl;
    deque.printDeque();

    cout << "6. Front: " << deque.peekFront() << endl;

    cout << "7. Back: " << deque.peekBack() << endl;

    cout << "8. Pop front: "
         << deque.popFront() << endl;

    cout << "9. Pop back: "
         << deque.popBack() << endl;

    cout << "10. Push front 1" << endl;
    deque.pushFront(1);

    cout << "11. Pop front: "
         << deque.popFront() << endl;

    cout << "12. Pop front: "
         << deque.popFront() << endl;

    cout << "13. Pop front: "
         << deque.popFront() << endl;

    cout << "14. Attempt empty pop:" << endl;
    deque.popFront();
}

void testLinkedDeque() {

    cout << "\n_____________________" << endl;
    cout << "LinkedList Deque Test" << endl;
    cout << "_____________________" << endl;

    LinkedDeque deque;

    cout << "\n1. Push back 10" << endl;
    deque.pushBack(10);

    cout << "2. Push back 20" << endl;
    deque.pushBack(20);

    cout << "3. Push front 5" << endl;
    deque.pushFront(5);

    cout << "4. Push back 30" << endl;
    deque.pushBack(30);

    cout << "5. Print" << endl;
    deque.printDeque();

    cout << "6. Front: "
         << deque.peekFront() << endl;

    cout << "7. Back: "
         << deque.peekBack() << endl;

    cout << "8. Pop front: "
         << deque.popFront() << endl;

    cout << "9. Pop back: "
         << deque.popBack() << endl;

    cout << "10. Push front 1" << endl;
    deque.pushFront(1);

    cout << "11. Pop front: "
         << deque.popFront() << endl;

    cout << "12. Pop back: "
         << deque.popBack() << endl;

    cout << "13. Pop back: "
         << deque.popBack() << endl;

    cout << "14. Attempt empty pop:" << endl;
    deque.popBack();
}

int main() {

    testArrayStack();

    testLinkedStack();

    testArrayQueue();

    testLinkedQueue();

    testArrayDeque();

    testLinkedDeque();

    return 0;
}