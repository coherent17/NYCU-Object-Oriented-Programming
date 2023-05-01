#include <string>

using namespace std;

class Personnel {
   private:
    string id;
    string name;
    string email;
    string password;

   public:
    Personnel();
    Personnel(string id, string name, string email, string password);

    // Reference
    // https://wiki.sei.cmu.edu/confluence/display/cplusplus/OOP52-CPP.+Do+not+delete+a+polymorphic+object+without+a+virtual+destructor
    virtual ~Personnel() = default;
    void printInfo();
    string getId();
};