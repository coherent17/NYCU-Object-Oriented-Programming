
class RentalSystem {
   public:
    vector<Customer*> customers;                // to record all customer information
    vector<Vehicle*> vehicles;                  // to store all vehicle information
    map<Customer*, RentalContract*> contracts;  // to store all contracts

    // Level 1
    RentalSystem();
    ~RentalSystem();
    void add_customer(Customer*);
    void add_vehicle(Vehicle*);
    void add_account_value(string name, string liscense_number, double amount);
    void rent_car(string name, string liscense_number, Vehicle*, string start_date, string end_date, double deposit = 0.0);
    void return_car(string name, string liscense_number, string return_date);
    void generate_report();

    // Level 3
    // Vehicle* car_recommendation(map<string, vector<string>> criterias);
};
