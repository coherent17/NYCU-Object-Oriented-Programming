#include "HashTable-1.h"
using namespace std;

int main(int argc, char** argv){
    int tableSize, option;
	ifstream in(argv[1]);
    cout << "==== Level 1: Hash Table with Modulo-division Hashing Function ====" << endl;
    cout << "Please enter the size of hash table: ";
    cin >> tableSize;

    //Create hash table
    HashTable HT(tableSize);

    //Insert data to hash table
    node n;
	while(in.read((char*)&n,sizeof(n)))
        HT += n;  

    //Print menu
    char sel;
    cout << "\ns) Search\np) Print\na) Analyze\nq) Quit\nYour selection: ";
    cin >> sel;
    while(sel != 'q'){
        switch(sel){
            case 's':
                HT.searchTable();
                break;
            case 'p':
                HT.printTable();
                break;
            case 'a':
                HT.analyzeTable();
                break;
            default:
                break;
        }
        cout << "\ns) Search\np) Print\na) Analyze\nq) Quit\nYour selection: ";
        cin >> sel;
    }
    return 0;
}