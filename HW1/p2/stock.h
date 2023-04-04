#ifndef _STOCK_H_
#define _STOCK_H_

#include <string>
using namespace std;

class Stock{
    private:
        static const double init_price;
        static const double limit_ratio;
        static double cur_price;
        static bool trade_available;
        int ticket_num;
        double avg_buy_price;
        const string owner_name;

    public:
        Stock();
        Stock(string name);
        Stock(string name, int n1);

        void operator + (const Stock &);
        void operator - (const Stock &);
        void buy();
        void sell();
        void show_stock();
        string get_owner_name() const;

        static void show_current_price();
        static void check_trade_is_available();
        static void refresh_current_price();

};

#endif