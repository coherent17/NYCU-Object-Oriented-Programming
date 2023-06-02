#include "TextInput.h"

// Constructor, remeber to set selectable to true
TextInput::TextInput(int sizeX, int sizeY, string input) : View(sizeX, sizeY), input(input){
    selectable = true;
}

// Getter
string TextInput::getInput(){
    return input;
}

// When the TextInput is selected and the user press the keyboard, onInputKey() will be called
void TextInput::onInputKey(char key){
    if (key == '\n') {
        // Enter key pressed, handle the input or perform any desired action
        // For example, you can update the input variable or trigger an event
        // onChange();
    } else if (key == '\b') {
        // Backspace key pressed, remove the last character from the input
        if (!input.empty()) {
            input.pop_back();
        }
        onChange();
    } else {
        // Other characters pressed, add them to the input
        input += key;
        onChange();
    }
    rerenderWindow();
}

// Render the textInput, the apperance of the textInput is different when selected
char** TextInput::render(){
        // Clear the canvas
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            canvas[i][j] = ' ';
        }
    }

    // Render the input text
    int textLength = input.length();
    int startX = 1;
    int startY = (sizeY - 1) / 2;

    for (int i = 0; i < textLength; i++) {
        if (startX + i >= sizeX) {
            break;
        }
        canvas[startY][startX + i] = input[i];
    }


    //top
    for(int i = 0; i < sizeX; i++){
        if(i == 0 || i == sizeX - 1) canvas[0][i] = '+';
        else canvas[0][i] = '-';
    }

    //bottom
    for(int i = 0; i < sizeX; i++){
        if(i == 0 || i == sizeX - 1) canvas[sizeY - 1][i] = '+';
        else canvas[sizeY - 1][i] = '-';
    }

    //left
    for(int i = 0; i < sizeY; i++){
        if(i == 0 || i == sizeY - 1) canvas[i][0] = '+';
        else canvas[i][0] = '|';
    }

    //right
    for(int i = 0; i < sizeY; i++){
        if(i == 0 || i == sizeY - 1) canvas[i][sizeX - 1] = '+';
        else canvas[i][sizeX - 1] = '|';
    }

    // Set the appearance based on selection
    if (isSelected()) {
        //top
        for(int i = 0; i < sizeX; i++){
            if(i == 0 || i == sizeX - 1) canvas[0][i] = '+';
            else canvas[0][i] = '=';
        }

        //bottom
        for(int i = 0; i < sizeX; i++){
            if(i == 0 || i == sizeX - 1) canvas[sizeY - 1][i] = '+';
            else canvas[sizeY - 1][i] = '=';
        }

        //left
        for(int i = 0; i < sizeY; i++){
            if(i == 0 || i == sizeY - 1) canvas[i][0] = '+';
            else canvas[i][0] = '[';
        }

        //right
        for(int i = 0; i < sizeY; i++){
            if(i == 0 || i == sizeY - 1) canvas[i][sizeX - 1] = '+';
            else canvas[i][sizeX - 1] = ']';
        }

    }

    return canvas;
}