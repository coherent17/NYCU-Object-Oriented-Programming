// Queue.h
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<bits/stdc++.h>
using namespace std;

template <typename S>
struct node{
    S data;
    node<S> *link;
};

template <class T>
class Queue
{
private:
    int len;
    node<T> *head;
    node<T> *tail;
public:
    Queue();
    // please add necessary function members
    void push(const T& element);
    void pop();
    T& front();
    T& back();
    int size();
    bool empty();
};

template <class T>
Queue<T>::Queue() : len(0), head(nullptr), tail(nullptr) {}

template <class T>
void Queue<T>::push(const T& element) {
    node<T> *newNode = new node<T>;
    newNode->data = element;
    newNode->link = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->link = newNode;
        tail = newNode;
    }

    len++;
}

template <class T>
void Queue<T>::pop() {
    if (head == nullptr) {
        return;
    }

    node<T> *temp = head;
    head = head->link;
    delete temp;
    len--;

    if (head == nullptr) {
        tail = nullptr;
    }
}

template <class T>
T& Queue<T>::front() {
    return head->data;
}

template <class T>
T& Queue<T>::back() {
    return tail->data;
}

template <class T>
int Queue<T>::size() {
    return len;
}

template <class T>
bool Queue<T>::empty() {
    return len == 0;
}

#endif
