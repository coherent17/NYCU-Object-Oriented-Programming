#ifndef _LIST_H_
#define _LIST_H_

#include "AbstractContainer.hpp"
#include "Node.h"

#include<bits/stdc++.h>
using namespace std;

template <class T>
class List : virtual public AbstractContainer<T> {
public:
    List();
    List(int size, const T& value);
    List(const List<T>& other);
    List(const T* arr, int size);
    virtual ~List();

    void insert(int position, const T& element) override;
    void erase(int position) override;
    int size() const override;
    bool empty() const override;
    void clear() override;
    int begin() const override;
    int end() const override;
    void display() const override;
protected:
    Node<T> *head;
    Node<T> *tail;
};

template <class T>
List<T>::List() : AbstractContainer<T>(), head(nullptr), tail(nullptr) {}

template <class T>
List<T>::List(int size, const T& value) : AbstractContainer<T>(size), head(nullptr), tail(nullptr) {
    for (int i = 0; i < size; i++) {
        insert(i, value);
    }
}

template <class T>
List<T>::List(const List<T>& other) : AbstractContainer<T>(other.len), head(nullptr), tail(nullptr) {
    Node<T>* curr = other.head;
    for (int i = 0; i < other.len; i++) {
        insert(i, curr->data);
        curr = curr->next;
    }
}

template <class T>
List<T>::List(const T* arr, int size) : AbstractContainer<T>(size), head(nullptr), tail(nullptr) {
    cout << AbstractContainer<T>::len << endl;
    for (int i = 0; i < size; i++) {
        insert(i, arr[i]);
    }
}

template <class T>
List<T>::~List() {
    clear();
}

template <class T>
void List<T>::insert(int position, const T& element) {
    if (position < 0 || position > size()) {
        return;
    }

    Node<T>* newNode = new Node<T>;
    newNode->data = element;

    if (position == 0) {
        cout << "here" << endl;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    } else if (position == size()) {
        newNode->prev = tail;
        newNode->next = nullptr;
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
    } else {
        Node<T>* curr = head;
        for (int i = 0; i < position - 1; i++) {
            curr = curr->next;
        }
        newNode->prev = curr;
        newNode->next = curr->next;
        curr->next->prev = newNode;
        curr->next = newNode;
    }

    AbstractContainer<T>::len++;
}


template <class T>
void List<T>::erase(int position) {
    if (position < 0 || position >= AbstractContainer<T>::len) {
        return;
    }

    if (position == 0) {
        Node<T>* curr = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete curr;
        if (head == nullptr) {
            tail = nullptr;
        }
    } else if (position == AbstractContainer<T>::len - 1) {
        Node<T>* curr = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete curr;
    } else {
        Node<T>* curr = head;
        for (int i = 0; i < position; i++) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    }

    AbstractContainer<T>::len--;
}

template <class T>
int List<T>::size() const {
    return AbstractContainer<T>::len;
}

template <class T>
bool List<T>::empty() const {
    return AbstractContainer<T>::len == 0;
}

template <class T>
void List<T>::clear() {
    Node<T>* curr = head;
    while (curr != nullptr) {
        Node<T>* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }

    head = nullptr;
    tail = nullptr;
    AbstractContainer<T>::len = 0;
}

template <class T>
int List<T>::begin() const {
    return 0;
}

template <class T>
int List<T>::end() const {
    return AbstractContainer<T>::len - 1;
}

template <class T>
void List<T>::display() const {
    Node<T>* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

#endif
