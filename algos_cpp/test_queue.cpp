#include <iostream>
#include <queue>

using namespace std;

/*
IntQueue : A queue of integers
*/

class IntQueue {
    int *element;
    int max_size;
    int head;
    int tail;

public:
    IntQueue(int s) {
        max_size = s;
        head = -1;
        tail = -1;
        element = new int[s];
    }

    ~IntQueue() {
        delete[] element;
    }

    void enqueue(int x) {
        if (tail == max_size-1)
            throw std::runtime_error("queue full");
        else {
            tail++;
            element[tail] = x;
        }
    }

    int dequeue() {
        if (head == tail)
            throw std::runtime_error("queue empty");
        else {
           head++;
           return element[head];
        }
    }

    bool empty() {
        return (head = tail);
    }
};

int main() {
   IntQueue myQueue(10);
   myQueue.enqueue(10);
   myQueue.enqueue(15);
   myQueue.enqueue(20);
   cout << "i.dequeue():" << myQueue.dequeue() << endl;
   cout << "i.dequeue():" << myQueue.dequeue() << endl;
   cout << "i.dequeue():" << myQueue.dequeue() << endl;
   cout << boolalpha << myQueue.empty() << endl;
}
