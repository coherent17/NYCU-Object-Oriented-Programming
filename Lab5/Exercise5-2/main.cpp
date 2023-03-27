#include "Score.h"
#include <iostream>

using namespace std;

int main(){
    Score s;
    while(1){
        cout << "input 1~4 to select function :" << endl;
        cout << "1.Set score" << endl;
        cout << "2.Set weight" << endl;
        cout << "3.Change score" << endl;
        cout << "4.Show average" << endl;
        cout << "5.Show weight average" << endl;

        int choice; cin >> choice;

        switch(choice){

            case 1:
                s.set_score();
                break;
            case 2:
                s.w.set_weight();
                break;
            case 3:
                s.Change();
                break;
            case 4:
                s.avg();
                break;
            case 5:
                s.w.weight_avg();
                break;

        }

    }
}