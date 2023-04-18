#include <iostream>
#include <fstream>
#include "Container.h"
#include "Pair.h"
using namespace std;

int main(int argc, char *argv[])
{
     if (argc < 3)
     {
          cout << "Usage: ./B-2 <input_file> <number_of_pairs>" << endl;
          return -1;
     }
     Pair **Pptr = Pair::readBinaryFile(argv[1], atoi(argv[2]));
     Container C1(Pptr, atoi(argv[2]));
     for (int i = 0; i < atoi(argv[2]); i++)
          delete Pptr[i];
     delete[] Pptr;
     cout << "Container C1:" << endl
          << C1;
     cout << "The total number of Pairs: " << Pair::getCount() << endl
          << endl;

     Container C2(Pair(4, -50));
     C2.insert(Pair(3, 199));
     C2.insert(Pair(1, 33));
     C2.insert(Pair(2, -70));
     cout << "Container C2:" << endl
          << C2;
     cout << "The total number of Pairs: " << Pair::getCount() << endl
          << endl;

     Container C3(C1 + C2);
     cout << "Container C3:" << endl
          << C3;
     cout << "The total number of Pairs: " << Pair::getCount() << endl
          << endl;

     Container C4(C1 - C2);
     cout << "Container C4:" << endl
          << C4;
     cout << "The total number of Pairs: " << Pair::getCount() << endl
          << endl;

     C3 *= C4;
     Container C5;
     C5 = C4;
     cout << "Container C5:" << endl
          << C5;
     cout << "The total number of Pairs: " << Pair::getCount() << endl
          << endl;
     cout << "The total number of Containers: " << Container::getCount() << endl;

     return 0;
}
