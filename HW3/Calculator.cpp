#include "Calculator.h"
#include "exprtk.hpp"

Window Calculator::window = Window(50, 30);
Label* Calculator::display = new Label(41, 4, "", Alignment::RIGHT);
string Calculator::expression = "";

Calculator::Calculator() {
    for (int i = 0; i < 10; i++) {
        numButtons[i] = new Button(9, 5, to_string(i));
        numButtons[i]->setOnClickListener(pressSymbolButton);
    }

    dotButton = new Button(9, 5, ".");
    dotButton->setOnClickListener(pressSymbolButton);

    addButton = new Button(9, 5, "+");
    addButton->setOnClickListener(pressSymbolButton);

    subButton = new Button(9, 5, "-");
    subButton->setOnClickListener(pressSymbolButton);

    mulButton = new Button(9, 5, "*");
    mulButton->setOnClickListener(pressSymbolButton);

    divButton = new Button(9, 5, "/");
    divButton->setOnClickListener(pressSymbolButton);

    eqButton = new Button(9, 5, "=");
    eqButton->setOnClickListener(pressEqualButton);

    exitButton = new Button(19, 3, "Exit");
    exitButton->setOnClickListener(exitWindow);

    //add view
    window.addView(display, 4, 1);

    window.addView(numButtons[7], 5, 6);
    window.addView(numButtons[8], 15, 6);
    window.addView(numButtons[9], 25, 6);
    window.addView(divButton, 35, 6);

    window.addView(numButtons[4], 5, 11);
    window.addView(numButtons[5], 15, 11);
    window.addView(numButtons[6], 25, 11);
    window.addView(mulButton, 35, 11);

    window.addView(numButtons[1], 5, 16);
    window.addView(numButtons[2], 15, 16);
    window.addView(numButtons[3], 25, 16);
    window.addView(addButton, 35, 16);

    window.addView(numButtons[0], 5, 21);
    window.addView(dotButton, 15, 21);
    window.addView(eqButton, 25, 21);
    window.addView(subButton, 35, 21);

    window.addView(exitButton, 15, 26);
}

Calculator::~Calculator() {
    View::deleteAllView();
}

void Calculator::run() {
    window.run();
}

void Calculator::exitWindow(View* view) {
    window.setExit();
}

void Calculator::pressSymbolButton(View* view) {
    Button* button = dynamic_cast<Button*>(view);
    string symbol = button->getText();
    expression += symbol;
    display->setOutput(expression);
}

void Calculator::pressEqualButton(View* view) {
    double result = evaluate(expression);
    expression = to_string(result);
    display->setOutput(expression);
    expression = "";
}

double Calculator::evaluate(string expression) {
    // Define the symbol table and expression parser
    exprtk::symbol_table<double> symbolTable;
    exprtk::expression<double> expr;
    expr.register_symbol_table(symbolTable);

    // Define the expression string
    exprtk::parser<double> parser;
    parser.compile(expression, expr);

    // Evaluate the expression and return the result
    return expr.value();
}