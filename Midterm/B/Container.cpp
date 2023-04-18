#include "Container.h"

using namespace std;

int Container::count = 0;

void Container::sort(){
    for (int i = 0; i < capacity - 1; ++i)
		for (int j = 0; j < capacity - 1 - i; ++j)
			if (*data[j + 1] < *data[j])
				*data[j+1] *= *data[j];
}

Container::Container(){
    data = nullptr;
    capacity = 0;
    count++;
}

Container::Container(const Pair &p){
    data = new Pair*[1];
    data[0] = new Pair(p);
    capacity = 1;
    count++;
}

Container::Container(Pair **data, int numPairs){
    this->data = nullptr;
    capacity = 0;
    for(int i = 0; i < numPairs; i++){
        insert(*data[i]);
    }
    count++;
    sort();
}

Container::Container(const Container &C){
    capacity = C.capacity;
    data = new Pair*[capacity];
    for(int i = 0; i < capacity; i++){
        data[i] = new Pair(C.data[i]->getKey(), C.data[i]->getValue());
    }
    count++;
    sort();
}

Container::~Container(){
    if(data == nullptr) return;
    for(int i = 0; i < capacity; i++){
        delete data[i];
    }
    delete []data;
    count--;
}

void Container::erase(Pair *P){
    if(!find(P->getKey())) return;

    Pair **newData = new Pair*[capacity - 1];
    for(int i = 0; i < capacity - 1; i++){
        newData[i] = new Pair();
    }

    int idx = 0;
    for(int i = 0; i < capacity; i++){
        if(data[i]->getKey() != P->getKey()){
            newData[idx]->setPair(data[i]->getKey(), data[i]->getValue());
            idx++;
        }
    }

    for(int i = 0; i < capacity; i++){
        delete data[i];
    }
    delete[] data;
    data = newData;
    capacity--;
}

void Container::clear(){
    for(int i = 0; i < capacity; i++){
        delete data[i];
    }
    delete []data;
    capacity = 0;
    data = nullptr;
}

bool Container::empty(){
    return capacity == 0;
}

bool Container::insert(const Pair &P){
    //if insert the same key
    if(find(P.first)){
        return false;
    }

    capacity++;
    Pair **newData = new Pair*[capacity];
    for(int i = 0; i < capacity; i++){
        newData[i] = new Pair();
    }

    for(int i = 0; i < capacity - 1; i++){
        newData[i]->setPair(data[i]->getKey(), data[i]->getValue());
    }
    newData[capacity - 1]->setPair(P.first, P.second);

    for(int i = 0; i < capacity - 1; i++){
        delete data[i];
    }

    if(data != nullptr)
        delete[] data;
    data = newData;

    sort();
    return true;
}

int Container::size() const{
    return capacity;
}

Pair *Container::find(int key){
    for(int i = 0; i < capacity; i++){
        if(data[i]->getKey() == key) return data[i];
    }
    return NULL;
}

Pair *Container::end(){
    return NULL;
}

Pair *Container::begin(){
    if(capacity > 0) return data[0];
    return NULL;
}

int Container::getCount(){
    return count;
}

ostream& operator<<(ostream &out, const Container &C){
    for(int i = 0; i < C.capacity; i++){
        out << "key: " << C.data[i]->getKey() << ", value: " << C.data[i]->getValue() << endl;
    }
    return out;
}

Container &Container::operator+=(const Container &C){
    for(int i = 0; i < C.capacity; i++){
        Pair *result = find(C.data[i]->getKey());
        if(result){
            result->setPair(result->getKey(), result->getValue() + C.data[i]->getValue());
        }
        else{
            insert(*C.data[i]);
        }
    }
    return *this;
}

Container Container::operator+(const Container &C){
    Container ret(*this);   //call copy constructor
    for(int i = 0; i < C.capacity; i++){
        Pair *result = ret.find(C.data[i]->getKey());
        if(result){
            result->setPair(result->getKey(), result->getValue() + C.data[i]->getValue());
        }
        else{
            ret.insert(*C.data[i]);
        }
    }
    return ret;
}

Container &Container::operator-=(const Container &C){
    for(int i = 0; i < C.capacity; i++){
        Pair *result = find(C.data[i]->getKey());
        if(result){
            result->setPair(result->getKey(), result->getValue() - C.data[i]->getValue());
        }
    }
    return *this;
}

Container Container::operator-(const Container &C){
    Container ret(*this);   //call copy constructor
    for(int i = 0; i < C.capacity; i++){
        Pair *result = ret.find(C.data[i]->getKey());
        if(result){
            result->setPair(result->getKey(), result->getValue() - C.data[i]->getValue());
        }
    }
    return ret;
}

void Container::operator*=(Container &C){
    Pair **own_data = new Pair*[capacity];
    for(int i = 0; i < capacity; i++){
        own_data[i] = new Pair(data[i]->getKey(), data[i]->getValue());
    }

    int own_capacity = capacity;

    Pair **C_data = new Pair*[C.capacity];
    for(int i = 0; i < C.capacity; i++){
        C_data[i] = new Pair(C.data[i]->getKey(), C.data[i]->getValue());
    }

    int C_capacity = C.capacity;


    for(int i = 0; i < capacity; i++){
        delete data[i];
    }
    delete []data;
    data = C_data;
    capacity = C_capacity;

    for(int i = 0; i < C.capacity; i++){
        delete C.data[i];
    }
    delete []C.data;
    C.data = own_data;
    C.capacity = own_capacity;
}

Container &Container::operator=(const Container &C){
    capacity = C.capacity;
    data = new Pair*[capacity];
    for(int i = 0; i < capacity; i++){
        data[i] = new Pair(C.data[i]->getKey(), C.data[i]->getValue());
    }
    return *this;
}