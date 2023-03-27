#include "Complex.h"
#include <iostream>
#include <cstring>
#include <string>


using namespace std;

void parse(string &expression, double &real, double &image){
    for(int i = 0; i < expression.length(); i++){
        bool isNegative = false;
        bool isImage = false;

        if(expression[i] == '+') i++;
        else if(expression[i] == '-'){
            isNegative = true;
            i++;
        }

        double current = 0;
        while(expression[i] >= '1' && expression[i] <= '9'){
            current = current * 10;
            current += (expression[i]-'0');
            i++;
        }
        if(expression[i] == 'j'){
            if(i - 1 >= 0 && (expression[i-1]=='+' || expression[i-1] == '-')){
                current = 1;
            }
            isImage = true;
            i++;
        } 
        
        if(isImage && isNegative) image += -current;
        else if(isImage && !isNegative) image += current;
        else if(!isImage && isNegative) real += -current;
        else if(!isImage && !isNegative) real += current;
        if(expression[i] != 'j'){
            i--;
        }
    }
}

int main(){
    string expression;
    cout << "input complex number: "; cin >> expression;
    double real = 0, image = 0;
    parse(expression, real, image);
    Complex a = Complex(real, image);
    Complex b;
    string last_op;
    while(1){

        string op;
        cout << "input operator: "; cin >> op;
        
        
        if(op == ">>"){
            a.Polar();
            printComplex(a);
        }
        else if(op == "+"){
            string temp;
            cout << "input complex number: "; cin >> temp;
            double real_temp = 0, image_temp = 0;
            parse(temp, real_temp, image_temp);
            b = Complex(real_temp, image_temp);
            a = a + b;
            printComplex(a);
            last_op = op;
        }

        else if(op == "-"){
            string temp;
            cout << "input complex number: "; cin >> temp;
            double real_temp = 0, image_temp = 0;
            parse(temp, real_temp, image_temp);
            b = Complex(real_temp, image_temp);
            a = a - b;
            printComplex(a);
            last_op = op;
        }

        else if(op == "*"){
            string temp;
            cout << "input complex number: "; cin >> temp;
            double real_temp = 0, image_temp = 0;
            parse(temp, real_temp, image_temp);
            b = Complex(real_temp, image_temp);
            a = a * b;
            printComplex(a);
            last_op = op;
        }

        else if(op == "*"){
            string temp;
            cout << "input complex number: "; cin >> temp;
            double real_temp = 0, image_temp = 0;
            parse(temp, real_temp, image_temp);
            b = Complex(real_temp, image_temp);
            a = a * b;
            printComplex(a);
            last_op = op;
        }



        else if(op == "="){
            if(last_op == ">>"){
                a.Polar();
                printComplex(a);
            }
            else if(last_op == "+"){
                a = a + b;
                printComplex(a);
            }

            else if(last_op == "-"){
                a = a - b;
                printComplex(a);
            }

            else if(last_op == "*"){
                a = a * b;
                printComplex(a);
            }

            else if(last_op == "*"){
                a = a * b;
                printComplex(a);
            }
        }
        

    }

    return 0;
}