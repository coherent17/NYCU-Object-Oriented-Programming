#include "Seq.h"
using namespace std;

int main(){
    Seq seq1("1.dat");
    Seq seq2("2.dat");
    seq1 >> 11;
    seq1.display();
    seq2 << 3;
    seq2.display();
    Seq seq3 = Seq(-seq1);
    seq3.display();
    return 0;
}