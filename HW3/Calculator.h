#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include "Button.h"
#include "Label.h"
#include "Window.h"

using namespace std;

// You can reference hw3-1.cpp to learn how to use the gui library you created
class Calculator {
    static Window window;
    static Label* display;
    Button* numButtons[10];
    Button* exitButton;
    Button* dotButton;
    Button* addButton;
    Button* subButton;
    Button* mulButton;
    Button* divButton;
    Button* eqButton;

    static string expression;


    public:
        // Constructor, setup views
        Calculator();

        // Destructor, call View::deleteAllView();
        ~Calculator();

        // Call window.run()
        void run();

        // Callback static functions
        static void exitWindow(View* view);
        static void pressSymbolButton(View* view);
        static void pressEqualButton(View* view);

    private:
        // Evaluate the expression inputed by buttons
        static double evaluate(string expression);
};

#endif