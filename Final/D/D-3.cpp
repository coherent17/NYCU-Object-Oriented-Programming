#include <iostream>
#include "MySTL.hpp"
#include "AbstractContainer.hpp"
#include "Vector.hpp"
#include "List.hpp"

int main()
{
    int arr[] = {-1, -1, -1, -1, -1, 3, 5, 8, 1, 6};
    MySTL<int> *Ptr = new MySTL<int>(arr, 10);

    cout << "================================= MySTL =================================" << endl
         << "Original: " << endl
         << "\t";
    Ptr->display();

    Ptr->insert(2, 11);
    Ptr->insert(6, -5);
    Ptr->insert(11, 20);
    cout << "After insert(2, 11), insert(6, -5), and insert(11, 20):" << endl
         << "\t";
    Ptr->display();

    Ptr->erase(0);
    cout << "After erase(0):" << endl
         << "\t";
    Ptr->display();
    cout << "List size: " << Ptr->size() << endl;

    Ptr->erase(11);
    cout << "After erase(11):" << endl
         << "\t";
    Ptr->display();

    Ptr->erase(5);
    cout << "After erase(5):" << endl
         << "\t";
    Ptr->display();
    cout << "List size: " << Ptr->size() << endl;

    // loop times
    int times = Ptr->size() / 2;
    cout << "times: " << times << endl;
    for (int i = 0; i < times; i++)
    {
        Ptr->erase(Ptr->begin());
        Ptr->erase(Ptr->end());
        Ptr->display();
    }
    cout << "List size: " << Ptr->size() << endl;

    Vector<int> *V_ptr = dynamic_cast<Vector<int> *>(Ptr);
    if (V_ptr)
    {
        cout << "================================= Vector =================================" << endl
             << "V_ptr->capacity(): " << V_ptr->capacity() << endl;
        cout << "After declaration: \n\tdisplay(): ";
        V_ptr->Vector<int>::display();

        // delete 5 items from backward
        V_ptr->pop_back();
        V_ptr->pop_back();
        V_ptr->pop_back();
        V_ptr->pop_back();
        V_ptr->pop_back();

        V_ptr->Vector<int>::insert(4, 4);
        cout << "After pop_back()*5, insert(4, 4): \n\tdisplay(): ";
        V_ptr->Vector<int>::display();

        V_ptr->push_back(1);
        V_ptr->push_back(3);
        V_ptr->Vector<int>::insert(7, 6);
        V_ptr->Vector<int>::insert(8, 9);
        cout << "After push_back(1), push_back(3), insert(7, 6), and insert(8, 9): \n\tdisplay(): ";
        V_ptr->Vector<int>::display();

        V_ptr->push_back(10);
        V_ptr->pop_back();
        cout << "After push_back(10), pop_back(): \n\tdisplay(): ";
        V_ptr->Vector<int>::display();

        V_ptr->Vector<int>::erase(3);
        V_ptr->Vector<int>::erase(5);
        cout << "V_ptr->capacity(): " << V_ptr->capacity() << endl;
        cout << "After erase(3), erase(5): \n\tdisplay(): ";
        V_ptr->Vector<int>::display();

        cout << "cout: ";
        for (int i = 0; i < V_ptr->Vector<int>::size(); i++)
            cout << (*V_ptr)[i] << " ";
        cout << endl;

        while (!V_ptr->Vector<int>::empty())
        {
            V_ptr->Vector<int>::erase(V_ptr->Vector<int>::begin());
            V_ptr->Vector<int>::erase(V_ptr->Vector<int>::  end());
            cout << "After erase(V_ptr->begin()), erase(V_ptr->end()): \n\tdisplay(): ";
            V_ptr->Vector<int>::display();
        }

        V_ptr->push_back(100);
        V_ptr->Vector<int>::insert(0, 200);
        V_ptr->Vector<int>::clear();
        cout << "size(): " << V_ptr->Vector<int>::size() << endl;
        cout << "V_ptr->capacity(): " << V_ptr->capacity() << endl;
    }

    delete Ptr;
    return 0;
}