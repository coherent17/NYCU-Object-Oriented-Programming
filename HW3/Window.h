#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <vector>

#include "utility.h"


using namespace std;

class View;

class Window {
    vector<View*> views;

    int sizeX;
    int sizeY;

    char** canvas;

    bool exit = false;
    View* selectedView = nullptr;

    public:
        // Consturctor, remember to allocate canvas 
        Window(int sizeX = 40, int sizeY = 20);

        // Destructor, remember to deallocate canvas 
        ~Window();

        // Add a new view to the window in provided position
        void addView(View* view, int posX, int posY);

        // Set exit to true
        void setExit();
        
        // Return selectedView
        View* getSelectedView();

        // Render the window, call "system("clear");" first
        void render();

        // Provided in Window.cpp 
        void run();


    private:
        // Will be called when arrow key is pressed
        // If selectedView == nullptr, set the first selectable view in the vector views to selectedView
        // Else set selectedView to the nearest selectable view of the current selectedView in the given direction
        void onArrowKeyPress(ArrowKey key);
        
        // Will be called when normal key is pressed (alphabet, symbols, backspace)
        // Call onInputKey() of the selected view
        void onNormalKeyPress(char key);

        // Will be called when Enter key is pressed
        // Call onClick() of the selected view
        void onEnterPress();

        // Set the selectedView
        void selectView(View* view);
};


#endif