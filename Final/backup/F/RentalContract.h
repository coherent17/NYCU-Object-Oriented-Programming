
class RentalContract {
   private:
    Customer* customer;
    Vehicle* vehicle;
    string start_date;
    string end_date;

   public:
    // Level 1
    RentalContract(Customer* customer, Vehicle* vehicle, string start_date, string end_date);
    ~RentalContract();
    void start_of_contract();
    void end_of_contract(string return_date);
};
