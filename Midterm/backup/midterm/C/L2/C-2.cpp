#include "HashTable-2.h"
using namespace std;

int main(int argc, char** argv){
    int tableSize, option;
	ifstream in(argv[1]);
    cout << "==== Level 2: Hash Table with Optional Hashing Function ====" << endl;
    cout << "Please enter the size of hash table: ";
    cin >> tableSize;
    HashTable HT(tableSize); //Create hash table

    //Choose hash function
    cout << "\nPlease choose a hashing function." << endl;
    cout << "1. Modulo-division" << endl;
    cout << "2. Digit-extraction" << endl;
    cout << "3. Folding" << endl;
    cout << "4. Pseudorandom" << endl;
    cout << "Your selection: ";
    cin >> option;
    HT.setHF(option);

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

