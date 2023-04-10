#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;
 

struct PriorityQueue
{
public:
    vector<int> A;
 
    int PARENT(int i) {
        return (i - 1) / 2;
    }
 
    int LEFT(int i) {
        return (2*i + 1);
    }
 
    int RIGHT(int i) {
        return (2*i + 2);
    }
 
    void heapify_down(int i)
    {
        int left = LEFT(i);
        int right = RIGHT(i);
 
        int smallest = i;
 
        if (left < size() && A[left] < A[i]) {
            smallest = left;
        }
 
        if (right < size() && A[right] < A[smallest]) {
            smallest = right;
        }
 
        if (smallest != i)
        {
            swap(A[i], A[smallest]);
            heapify_down(smallest);
        }
    }
 
    void heapify_up(int i)
    {
        if (i && A[PARENT(i)] > A[i])
        {
            swap(A[i], A[PARENT(i)]);
 
            heapify_up(PARENT(i));
        }
    }
 
public:
    unsigned int size() {
        return A.size();
    }
 
    bool empty() {
        return size() == 0;
    }
 
    void push(int key)
    {
        A.push_back(key);
 
        int index = size() - 1;
        heapify_up(index);
    }
 
    void pop()
    {
        try {
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                        "index is out of range(Heap underflow)");
            }
 
            A[0] = A.back();
            A.pop_back();
 
            heapify_down(0);
        }
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }
 
    int top()
    {
        try {
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                        "index is out of range(Heap underflow)");
            }
            return A.at(0);
        }
        catch (const out_of_range &oor) {
            cout << endl << oor.what();
        }
    }
};

int main(int argc, char* argv[]){

    
    std::ifstream input(argv[1], std::ios::binary);
    
    int num;
    PriorityQueue pq;
    while (input.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        cout << num << " ";
        pq.push(num);
    }
    cout << endl << endl;
    

    vector<int> B;
    B.assign(pq.A.begin(), pq.A.end());


    int size_per_layer [] = {1, 2, 4, 8, 16};
    string layer3_space[] = {"    ", "  ", "   ", "", "  "};
    string layer4_space[] = {"            ", "     ", "             ", "  ", "      ", "      ", "    ", "", "  ", "  "};
    string layer5_space[] = {"                        ", "          ", "                           ", "      ", "       ", "              ", "                    ", "  ", "      ", "       ", "     ", "     ", "     ", "     ", "     ", "", "  ", "  ", "  ", "  "};

    int current_layer = 0;

    int index = 0;
    int count = 0;

    if(B.size() == 5){
        while(index < B.size()){
            if(count < size_per_layer[current_layer]){
                cout << layer3_space[index] << B[index] << " ";
                count++;
                index++;
            }
            else{
                cout << endl;
                count = 0;
                current_layer++;
            }
        }
    }

    if(B.size() == 10){
        while(index < B.size()){
            if(count < size_per_layer[current_layer]){
                cout << layer4_space[index] << B[index] << " ";
                count++;
                index++;
            }
            else{
                cout << endl;
                count = 0;
                current_layer++;
            }
        }
    }

    if(B.size() == 20){
        while(index < B.size()){
            if(count < size_per_layer[current_layer]){
                cout << layer5_space[index] << B[index] << " ";
                count++;
                index++;
            }
            else{
                cout << endl;
                count = 0;
                current_layer++;
            }
        }
    }


    cout << endl << endl;

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    
    return 0;
}
