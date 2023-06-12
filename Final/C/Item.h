#ifndef ITEM_H
#define ITEM_H

template <class T>
class Item {
private:
    int id;
    std::string name;

public:
    Item(int id, std::string name);
    int getId();
    std::string getName();
    virtual void printInfo() = 0;
};

template <class T>
Item<T>::Item(int id, std::string name) : id(id), name(name) {}

template <class T>
int Item<T>::getId() {
    return id;
}

template <class T>
std::string Item<T>::getName() {
    return name;
}

#endif  // ITEM_H
