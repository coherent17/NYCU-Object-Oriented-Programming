// Queue.h
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
};
