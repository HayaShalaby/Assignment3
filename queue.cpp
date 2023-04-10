#include "customer.h"
#include "queue.h"


template <class X>
queue<X>::queue(int size)
{
    arr = new X[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
 

template <class X>
X queue<X>::pop()
{   if(isEmpty())
        cout << "The queue is empty." <<endl;
    else{
//         cout << "Removing " << arr[front] << endl;
        front = (front + 1) % capacity;
        count--;
        X x = arr[front];
        return x;
    }
} 

 

template <class X>
void queue<X>::push(X item)
{
    if (isFull())
        cout << "The queue is full.";
    else{
//         cout << "Inserting " << item << endl;
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }
}

 

template <class X>
bool queue<X>::isEmpty() {
    if(count)
        return false;
    else 
        return true;
}
 

template <class X>
bool queue<X>::isFull() {
    if(count < capacity)
        return false;
    else 
        return true;
}

template class queue<Customers>; 
