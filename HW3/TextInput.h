#ifndef _TEXTINPUT_H_
#define _TEXTINPUT_H_

#include <string>

#include "View.h"

using namespace std;

class TextInput : public View {
    string input;

    public:
        // Constructor, remeber to set selectable to true
        TextInput(int sizeX, int sizeY, string input = "");

        // Getter
        string getInput();

    private:
        // When the TextInput is selected and the user press the keyboard, onInputKey() will be called
        void onInputKey(char key);

        // Render the textInput, the apperance of the textInput is different when selected
        char** render();
};

#endif