#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <string>

#include "View.h"

using namespace std;

class Button : public View {
    string text;

    public:
        // Constructor, remeber to set selectable to true
        Button(int sizeX, int sizeY, string text = "");

        // Getter
        string getText();

    private:
        // Handler: When user click the button, call onChange()
        void onClick();

        // Render the button, the apperance of the button is different when selected
        char** render();
};

#endif