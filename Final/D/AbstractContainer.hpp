#ifndef _ABSTRACT_CONTAINER_H_
#define _ABSTRACT_CONTAINER_H_

template <class T>
class AbstractContainer {
protected:
    T *arr;
    int len;

public:
    AbstractContainer();
    AbstractContainer(int size);
    virtual ~AbstractContainer();

    virtual void insert(int position, const T& element) = 0;
    virtual void erase(int position) = 0;
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual void clear() = 0;
    virtual int begin() const = 0;
    virtual int end() const = 0;
    virtual void display() const = 0;
};

template <class T>
AbstractContainer<T>::AbstractContainer() : arr(nullptr), len(0) {}

template <class T>
AbstractContainer<T>::AbstractContainer(int size) : len(size) {
    arr = new T[len];
}

template <class T>
AbstractContainer<T>::~AbstractContainer() {
    delete[] arr;
}

#endif
