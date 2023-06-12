
class Customer {
   public:
    // Levle 1
    Customer(string name, string license_number, double account_balance = 0.0);
    ~Customer();
    void rent_vehicle(Vehicle* vehicle, int rental_duration);
    void return_vehicle(Vehicle* vehicle, int late_day);
    void add_value(double deposit);  // deposit $ into the account

    // Levle 2
    // void point_manipulate(int i);    // i: +1 if make a reservation, -1 if return late

   private:
    string name;
    string license_number;
    double account_balance;  // money in the account
    int bonus_point = 0;     // +1: make a reservation, -1: late return
};
