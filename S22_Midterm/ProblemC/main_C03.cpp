#include "Seq.h"
using namespace std;

int main(){
    Seq seq1("1.dat");
    Seq seq2("2.dat");
    seq1 >> 11;
    seq2 << 3;
    seq1.display();
    seq2.display();
    Seq seq3 = seq1 * seq2;
    seq3.display();
    Seq seq4 = seq3.mid_filter(3);
    seq4.display();
    return 0;
}