#include <iostream>
#include <sstream>
#include <fstream>
#include "Factory.h"
#include "Store.h"
#include "Item.h"
using namespace std;

int main()
{
    // Create a new factory system
    Factory fct;
    Store st;

    while (1)
    {
        char choose;
        int func;
        cout << "Choose A or B" << endl;
        cout << "A. Factory Mode" << endl;
        cout << "B. Store Mode" << endl;
        cin >> choose;
        switch (choose)
        {
        case 'A':
            // do for factory
            cout << "Input 1~2 for choose function" << endl;
            cout << "1. Manufacturing products" << endl;
            cout << "2. Show Factory Product" << endl;
            cin >> func;
            switch (func)
            {
            case 1: // Manufacturing products
            {
                double cost;
                int quantity, year, month, date;
                string name, exp_day, factory_file;
                cout << "input factory manufacture list filename" << endl;
                cin >> factory_file;
                ifstream factory_manu_list(factory_file);
                if (factory_manu_list.is_open())
                {
                    string line;

                    while (getline(factory_manu_list, line))
                    {
                        stringstream ss(line);
                        char delimiter = '/';
                        ss >> name >> quantity >> cost >> year >> delimiter >> month >> delimiter >> date;
                        Item a(name, quantity, cost, year, month, date);
                        fct.addItem(a); // add item a into factory's item list
                    }
                    factory_manu_list.close();
                }
                else
                {
                    cout << "cannot open file" << endl;
                }
            }
            break;
            case 2:                   // show factory product
                fct.sortItemsByEXP(); // factory list will sort items by expired date
                cout << fct;          // operator << show factory's item list
                break;
            default:
                cout << "Input error! Choose again!" << endl;
                break;
            }
            break;
        case 'B':
            // Store mode
            cout << "Input 1~4 for choose function" << endl;
            cout << "1. Purchase commodity" << endl;
            cout << "2. Settlement profit" << endl;
            cout << "3. Show menu" << endl;
            cout << "4. Show commodity list" << endl;
            cin >> func;
            switch (func)
            {
            case 1: //Purchase according to the list
            {
                string name, store_file;
                int quantity;
                double price, cost;
                cout << "input store purchase list filename" << endl;
                cin >> store_file;
                ifstream store_menu(store_file);
                if (store_menu.is_open())
                {
                    string line;

                    while (getline(store_menu, line))
                    {
                        stringstream ss(line);
                        ss >> name >> quantity >> price;
                        if (fct.searchItem(name) == -1) //if factory no this item
                        {
                            cout << name << " : no this product" << endl;
                        }
                        else
                        {
                            int supply = 0;
                            double cost = 0;
                            while (supply < quantity)
                            {
                                if (fct.searchItem(name) == -1)
                                {
                                    cout << name << " : no enough product" << endl;
                                    break;
                                }
                                else if (fct.items[fct.searchItem(name)].getQuantity() >= quantity - supply)
                                {
                                    cost = fct.items[fct.searchItem(name)].getCost();
                                    Item a(name, quantity - supply, price, cost, fct.items[fct.searchItem(name)].getEXP().year, fct.items[fct.searchItem(name)].getEXP().month, fct.items[fct.searchItem(name)].getEXP().date);
                                    st.addItem(a);
                                    fct.removeStock(name, quantity - supply);
                                    if (fct.items[fct.searchItem(name)].getQuantity() == 0)
                                    {
                                        fct.removeItem(fct.items[fct.searchItem(name)]);
                                    }
                                    break;
                                }
                                else
                                {
                                    supply += fct.items[fct.searchItem(name)].getQuantity();
                                    cost = fct.items[fct.searchItem(name)].getCost();
                                    Item a(name, fct.items[fct.searchItem(name)].getQuantity(), price, cost, fct.items[fct.searchItem(name)].getEXP().year, fct.items[fct.searchItem(name)].getEXP().month, fct.items[fct.searchItem(name)].getEXP().date);
                                    st.addItem(a);
                                    fct.removeItem(fct.items[fct.searchItem(name)]);
                                    cost = 0;
                                }
                            }
                        }
                    }
                    store_menu.close();
                }
                else
                {
                    cout << "file cannot open" << endl;
                }
            }
            break;

            case 2: // Settlement profit
            {
                st.sortItemsByEXP(); //Items are sale in order of expiration date
                string today, sale_file;
                cout << "input the date yyyy/mm/dd and sale list filename" << endl;
                cin >> today >> sale_file;
                ifstream sale_list(sale_file);
                double loss = st.get_expired(today); //Calculate Expired Item Cost
                double profit = 0; 
                string line;
                while (getline(sale_list, line))
                {
                    stringstream ss(line);
                    string name;
                    int quantity;
                    ss >> name >> quantity;
                    profit += st.get_profit(name, quantity); //Calculate the net profit of items sold
                }
                cout << today << " profit is: " << profit + loss << endl;
                break;
            }
            case 3:// show store menu
                st.show_menu(); //store menu will sort items by name , call sortItemsByName() in show_menu;
                break;
            case 4: // show commodity list
                st.sortItemsByEXP(); //store menu will sort items by expired day
                cout << st;
                break;
            default:
                cout << "Input error! Choose again!" << endl;
                break;
            }
            break;

        default:
            // cout << "Input error! Choose again!" << endl;
            break;
        }
    }

    return 0;
}
