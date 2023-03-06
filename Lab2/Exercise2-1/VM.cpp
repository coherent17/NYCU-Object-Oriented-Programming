#include "VM.h"
#include<bits/stdc++.h>

using namespace std;


bool cmp(item x, item y){
    return x.id < y.id;
}

void VM::add_item(){
    item temp;
    cout << "Please enter the information of the item." << endl;
    cout << "ID: ";
    cin >> temp.id;
    cout << "Name: ";
    cin >> temp.name;
    cout << "Price: ";
    cin >> temp.price;
    item_vec.push_back(temp);
    sort(item_vec.begin(), item_vec.end(), cmp);
}

void VM::remove_item(){
    if(item_vec.size() == 0){
        cout << "There is no item right now!!!" << endl;
        return;
    }
    else{
        cout << "The name of the item you want to remove: ";
        string rm_name;
        cin >> rm_name;

        bool found = false;
        for(size_t i = 0; i < item_vec.size(); i++){
            if(item_vec[i].name == rm_name){
                item_vec.erase(item_vec.begin() + i);
                found = true;
                break;
            }
        }
        if(found == false) cout << "No item found!" << endl;
    }
}

void VM::print_itemList(){
    if(item_vec.size() == 0){
        cout << "There is no item right now!!!" << endl;
        return;
    }
    cout << "ID\tName\tPrice" << endl; 
    for(size_t i = 0; i < item_vec.size(); i++){
        cout << item_vec[i].id << "\t" << item_vec[i].name << "\t" << item_vec[i].price << endl;
    }
}

void VM::find_change(item x, int num1, int num5, int num10, int num50){
    int total = num1 * 1 + num5 * 5 + num10 * 10 + num50 * 50;
    int price = x.price;
    int diff = total - price;
    if(diff == 0) cout << "No change should be given." << endl;

    int retnum1, retnum5, retnum10, retnum50;
    retnum50 = int(diff / 50);
    diff -= retnum50 * 50;

    retnum10 = int(diff / 10);
    diff -= retnum10 * 10;

    retnum5 = int(diff / 5);
    diff -= retnum5 * 5;
    
    retnum1 = diff;
    cout << "Your change" << endl;
    cout << "One dollar: " << retnum1 << endl;
    cout << "Five dollar: " << retnum5 << endl;
    cout << "Ten dollar: " << retnum10 << endl;
    cout << "Fifty dollar: " << retnum50 << endl;
    cout << "Thank you for your purchase!" << endl;
}

void VM::purchase_item(){
    if(item_vec.size() == 0){
        cout << "Sorry! There is no item right now." << endl;
        return;
    }
    cout << "Welcome! Here is the item list." << endl;
    print_itemList();
    cout << "Which item do you want to buy?" << endl;
    string want_name;
    cin >> want_name;
    bool found = false;
    for(size_t i = 0; i < item_vec.size(); i++){
        if(want_name == item_vec[i].name){
            found = true;
            cout << "The price is " << item_vec[i].price << " dollars" << endl;
            cout << "Please insert coins." << endl;
            int num1, num5, num10, num50;
            cout << "One dollar: ";
            cin >> num1;
            cout << "Five dollar: ";
            cin >> num5;
            cout << "Ten dollar: ";
            cin >> num10;
            cout << "Fifty dollar: ";
            cin >> num50;
            
            find_change(item_vec[i], num1, num5, num10, num50);
            item_vec.erase(item_vec.begin() + i);
            break;
        }
    }
    if(found == false){
        cout << "Out of stock!" << endl;
        return;
    }
}

void VM::print_optionList(){
    cout << "Enter 1 for owner mode, 2 for customer mode: ";
            int mode;
        cin >> mode;
        if(mode != 1 && mode != 2){
            cout << "Invalid input!" << endl;
            return;
        }

        if(mode == 1){
            cout << "Please enter your password: ";
            string pwd;
            cin >> pwd;
            if(pwd == password){
                cout << "Welcome to owner mode!" << endl;
                cout << "1. Add item" << endl;
                cout << "2. Remove item" << endl;
                cout << "3. Print item list" << endl;
                int choice;
                cin >> choice;

                if(choice == 1) add_item();
                else if(choice == 2) remove_item();
                else if(choice == 3) print_itemList();
                else{
                    cout << "Invalid input!" << endl;
                    return;
                }
            }
            else{
                cout <<"Wrong password!" << endl;
                cout << "Enter 1 for type again, 2 for going back to last step: " << endl;
                int choice;
                cin >> choice;
                if(choice == 1){
                    cout << "Please enter your password: ";
                    string pwd;
                    cin >> pwd;
                    if(pwd == password){
                        cout << "Welcome to owner mode!" << endl;
                        cout << "1. Add item" << endl;
                        cout << "2. Remove item" << endl;
                        cout << "3. Print item list" << endl;
                        int choice;
                        cin >> choice;
                        if(choice == 1) add_item();
                        else if(choice == 2) remove_item();
                        else if(choice == 3) print_itemList();
                    }
                }
                if(choice == 2) return;
            }
        }
        else if(mode == 2){
            purchase_item();
        }
}

void VM::start(){
    bool pwdFinish = false;
    while(!pwdFinish){
        string pwd, ensured_pwd;
        cout << "Enter a password for your vending machine: ";
        cin >> pwd;
        cout << "Enter your password again: ";
        cin >> ensured_pwd;
        if(pwd != ensured_pwd){
            cout << "It's different from the first password! Please set the password again!" << endl;
        }
        else{
            password = pwd;
            pwdFinish = true;
        }
    }

    while(1){
        print_optionList();
    }
}