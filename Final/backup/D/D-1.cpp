#include <iostream>
#include "AbstractContainer.hpp"
#include "List.hpp"

int main()
{
    int arr1[] = {-1, -1, -1, -1, -1, 3, 5, 8, 1, 6};
    AbstractContainer<int> *Ptr = new List<int>(arr1, 10);
    cout << "Original: " << endl
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

    delete Ptr;
    return 0;
}