
class Vehicle {
   public:
    // Level 1
    Vehicle(string brand, string model, double price, int seats, string transmission_type);
    double calculate_rental_price(int days, Customer *customer);
    double calculate_penalty_fee(int days, Customer *customer);

    // Level 2
    // turn calculate_rental_price(), calculate_penalty_fee() into virtual functions

   private:
    string brand;
    string model;
    double price;
    int seats;
    string transmission_type;
    bool available = true;
};
