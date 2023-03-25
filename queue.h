#include<iostream>
using namespace std;

#ifndef queue_h
#define queue_h

template <class X>
class queue
{
    X *arr;         // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      //points to the front element of the queue 
    int rear;       //points to the end/back of the queue
    int count;      // current size of the queue
 
public:
    queue(int size=0); //default class contructor 
    X pop();      //dequeues element from the front of the queue 
    void push(X x);  //enqueues element to the end of the queue 
    bool isEmpty();  //returns true if the queue is empty, false otherwise 
    bool isFull();   //returns false if the queue is full, fasle otherwise 
};
 
#endif
