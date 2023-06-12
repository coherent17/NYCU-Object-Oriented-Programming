// Complex.h
class Complex{
private:
    double real;
    double imag;
public:
    // please add constructors
    void set_real(double);
    void set_imag(double);
    void operator=(const Complex &);
    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
    void operator+=(const Complex &);
    void operator-=(const Complex &);
    friend std::ostream &operator<<(std::ostream &os, const Complex);
};