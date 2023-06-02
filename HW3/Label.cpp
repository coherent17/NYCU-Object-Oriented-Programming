#include "Label.h"

// Constructor, remeber to set selectable to false
Label::Label(int sizeX, int sizeY, string output, Alignment alignment) : View(sizeX, sizeY), output(output), alignment(alignment){
    selectable = false;
}

// Setters: remember to call onChange and rerenderWindow() when setter is called
void Label::setOutput(string output){
    this->output = output;
    onChange();
    rerenderWindow();
}

void Label::setAlignment(Alignment alignment){
    this->alignment = alignment;
    onChange();
    render();
    rerenderWindow();
}

// Render the label, need to render text for different alignment
char** Label::render(){
    // Clear the canvas
    for (int i = 0; i < sizeY; i++) {
        for (int j = 0; j < sizeX; j++) {
            canvas[i][j] = ' ';
        }
    }

    // Render the text based on the alignment
    int textLength = output.length();
    int startX = 1;

    if (alignment == Alignment::CENTER) {
        startX = (sizeX - textLength) / 2;
    } 
    
    else if (alignment == Alignment::RIGHT) {
        startX = sizeX - textLength - 1;
    }

    for (int i = 0; i < textLength; i++) {
        if (startX + i >= sizeX) {
            break;
        }
        canvas[sizeY / 2][startX + i] = output[i];
    }

    //boundary
    
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