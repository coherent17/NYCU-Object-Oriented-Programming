#include "Button.h"

// Constructor, remeber to set selectable to true
Button::Button(int sizeX, int sizeY, string text) : View(sizeX, sizeY), text(text){
    selectable = true;
}

// Getter
string Button::getText(){
    return text;
}

// Handler: When user click the button, call onChange()
void Button::onClick(){
    View::onClick();
    View::onChange();
}

// Render the button, the apperance of the button is different when selected
char** Button::render(){
    // Clear the canvas
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            canvas[i][j] = '#';
        }
    }

    // Render the button text
    int textLength = text.length();
    int startX = (sizeX - textLength) / 2;
    int startY = (sizeY - 1) / 2;

    for (int i = 0; i < textLength; i++) {
        if (startX + i >= sizeX) {
            break;
        }
        canvas[startY][startX + i] = text[i];
    }

    // Set the appearance based on selection
    if (!isSelected()) {
        for(int i = 0; i < sizeY; i++){
            for(int j = 0; j < sizeX; j++){
                if(canvas[i][j] == '#') canvas[i][j] = ' ';
            }
        }
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

    return canvas;
}