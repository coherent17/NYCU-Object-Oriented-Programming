#include <iostream>
#include "AbstractContainer.hpp"
#include "Vector.hpp"

int main()
{
    Vector<int> *V_ptr = new Vector<int>(5, -1);
    cout << "V_ptr->capacity(): " << V_ptr->capacity() << endl;
    cout << "After declaration: \n\tdisplay(): ";
    V_ptr->display();

    V_ptr->insert(4, 4);
    cout << "After insert(4, 4): \n\tdisplay(): ";
    V_ptr->display();

    V_ptr->push_back(1);
    V_ptr->push_back(3);
    V_ptr->insert(7, 6);
    V_ptr->insert(8, 9);
    cout << "After push_back(1), push_back(3), insert(7, 6), and insert(8, 9): \n\tdisplay(): ";
    V_ptr->display();

    V_ptr->push_back(10);
    V_ptr->pop_back();
    cout << "After push_back(10), pop_back(): \n\tdisplay(): ";
    V_ptr->display();

    V_ptr->erase(3);
    V_ptr->erase(5);
    cout << "V_ptr->capacity(): " << V_ptr->capacity() << endl;
    cout << "After erase(3), erase(5): \n\tdisplay(): ";
    V_ptr->display();

    cout << "cout: ";
    for (int i = 0; i < V_ptr->size(); i++)
        cout << (*V_ptr)[i] << " ";
    cout << endl;

    while (!V_ptr->empty())
    {
        V_ptr->erase(V_ptr->begin());
        V_ptr->erase(V_ptr->end());
        cout << "After erase(V_ptr->begin()), erase(V_ptr->end()): \n\tdisplay(): ";
        V_ptr->display();
    }

    V_ptr->push_back(100);
    V_ptr->insert(0, 200);
    V_ptr->clear();
    cout << "size(): " << V_ptr->size() << endl;
    cout << "V_ptr->capacity(): " << V_ptr->capacity() << endl;

    delete V_ptr;
    return 0;
}