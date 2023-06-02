#include <iostream>

#include "Button.h"
#include "Label.h"
#include "TextInput.h"
#include "Window.h"


using namespace std;


// Create window and views
Window window = Window(70, 30);
Label* displayLabel = new Label(30, 7, "Hello World!", Alignment::CENTER);

Label* nameLabel = new Label(10, 3, "Name:", Alignment::CENTER);
TextInput* nameInput = new TextInput(20, 3);

Button* leftAlignButton = new Button(20, 5, "Left Align");
Button* centerButton = new Button(20, 5, "Center Align");
Button* rightAlignButton = new Button(20, 5, "Right Align");
Button* helloButton = new Button(20, 5, "Hello");
Button* goodbyeButton = new Button(20, 5, "Goodbye");
Button* exitButton = new Button(20, 3, "Exit");

string name = "";


// Callback functions for views
void exitWindow(View* view) { window.setExit(); }
void updateName(View* view) { name = dynamic_cast<TextInput*>(view)->getInput(); }
void clickTextButton(View* view) { displayLabel->setOutput(dynamic_cast<Button*>(view)->getText() + " " + name + "!"); }
void clickAlignButton(View* view) {
    string buttonText = dynamic_cast<Button*>(view)->getText();
    if (buttonText == "Left Align") {
        displayLabel->setAlignment(Alignment::LEFT);
    } else if (buttonText == "Right Align") {
        displayLabel->setAlignment(Alignment::RIGHT);
    } else if (buttonText == "Center Align") {
        displayLabel->setAlignment(Alignment::CENTER);
    }
}


int main() {
    nameInput->setOnChangeListener(updateName);

    leftAlignButton->setOnClickListener(clickAlignButton);
    centerButton->setOnClickListener(clickAlignButton);
    rightAlignButton->setOnClickListener(clickAlignButton);
    helloButton->setOnClickListener(clickTextButton);
    goodbyeButton->setOnClickListener(clickTextButton);
    exitButton->setOnClickListener(exitWindow);


    window.addView(displayLabel, 20, 1);

    window.addView(nameLabel, 14, 8);
    window.addView(nameInput, 25, 8);

    window.addView(helloButton, 25, 12);
    window.addView(leftAlignButton, 4, 17);
    window.addView(centerButton, 25, 17);
    window.addView(rightAlignButton, 46, 17);
    window.addView(goodbyeButton, 25, 22);
    window.addView(exitButton, 25, 27);


    window.run();

    View::deleteAllView();
}
