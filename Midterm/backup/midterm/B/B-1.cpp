#include <iostream>
#include <fstream>
#include "Pair.h"
#include "Container.h"
using namespace std;

int main(int argc, char *argv[])
{
     if (argc < 3)
     {
          cout << "Usage: ./B-1 <input_file> <number_of_pairs>" << endl;
          return -1;
     }
     Pair **Pptr;
     Pptr = Pair::readBinaryFile(argv[1], atoi(argv[2]));
     cout << "Pptr:" << endl;
     for (int i = 0; i < atoi(argv[2]); i++)
          cout << *Pptr[i];
     cout << "The total number of Pairs: " << Pair::getCount() << endl
          << endl;

     Container C1(Pptr, atoi(argv[2]));
     cout << "The total number of Pairs before delete: " << Pair::getCount() << endl
          << endl;

     for (int i = 0; i < atoi(argv[2]); i++)
          delete Pptr[i];
     delete[] Pptr;
     cout << "Container C1:" << endl
          << C1;
     cout << "The total number of Pairs after delete: " << Pair::getCount() << endl
          << endl;

     Container C1_copy(C1);
     cout << "Container C1_copy:" << endl
          << C1_copy
          << endl;
     cout << "The total number of Containers: " << Container::getCount() << endl
          << endl;

     // repeat insert
     C1_copy.insert(Pair(4, 900));
     cout << "C1_copy after repeat insert:" << endl
          << C1_copy
          << endl;

     Pair p1(3);
     Container C2(p1);

     Pair p2(2, 5);
     C2.insert(p2);

     C2.insert(Pair(1, 9));
     cout << "Container C2:" << endl
          << C2;
     cout << "The total number of Pairs: " << Pair::getCount() << endl
          << endl;
     cout << "The total number of Containers: " << Container::getCount() << endl
          << endl;

     Pair *ptr_1 = C2.find(1);

     if (ptr_1 != C2.end())
          cout << "value of ptr_1: " << ptr_1->getValue() << endl
               << endl;
     else
          cout << "ptr_1 not found" << endl
               << endl;

     Pair *ptr_4 = C2.find(4);

     if (ptr_4 != C2.end())
          cout << "value of ptr_4: " << ptr_4->getValue() << endl
               << endl;
     else
          cout << "ptr_4 not found" << endl
               << endl;

     cout << "C2 before erase:" << endl
          << C2
          << endl;
     Pair *run;
     while (!C2.empty())
     {
          run = C2.begin();
          cout << "ready to erase " << *run;
          C2.erase(run);
     }
     cout << "Container C2:" << endl
          << C2
          << endl;

     if (!C2.empty())
          C2.clear();
     else
          cout << "C2 is empty!" << endl;

     cout << "C1 before clear:" << endl
          << C1;
     C1.clear();
     cout << "C1 after clear:" << endl
          << C1;

     // two pair object + one C1_copy container with three pair object
     cout << "The total number of Pairs before end: " << Pair::getCount() << endl
          << endl;
     // three container object
     cout << "The total number of Containers before end: " << Container::getCount() << endl
          << endl;

     if (C1.empty())
          cout << "Success" << endl;
     else
          cout << "Fail in clear()" << endl;

     return 0;
}
