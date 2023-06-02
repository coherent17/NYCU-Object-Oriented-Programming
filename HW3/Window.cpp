#include "Window.h"

#include <termios.h>

#include <cmath>
#include <cstdlib>
#include <iostream>

#include "View.h"


using namespace std;

// Consturctor, remember to allocate canvas 
Window::Window(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY){

    //allocate for canvas
    canvas = new char *[sizeY];
    for(int i = 0; i < sizeY; i++){
        canvas[i] = new char[sizeX];
    }

    //initialize the canvas
    for(int i = 0; i < sizeY; i++){
        for(int j = 0; j < sizeX; j++){
            canvas[i][j] = ' ';
        }
    }
}

// Destructor, remember to deallocate canvas 
Window::~Window(){
    for(int i = 0; i < sizeY; i++){
        delete []canvas[i];
    }
    delete []canvas;

    for(size_t i = 0; i < views.size(); i++){
        delete views[i];
    }
    views.clear();
}

// Add a new view to the window in provided position
void Window::addView(View* view, int posX, int posY){
    view->setPos(posX,  posY);
    view->setWindow(this);
    views.push_back(view);
}

// Set exit to true
void Window::setExit(){
    exit = true;
}

// Return selectedView
View* Window::getSelectedView(){
    return selectedView;
}

// Render the window, call "system("clear");" first
void Window::render() {
    system("clear");
    // TODO: Render the window

    //fill in the canvas
    for(View *view : views){
        char** viewCanvas = view->render();
        int posX = view->getPosX();
        int posY = view->getPosY();
        int viewSizeX = view->getSizeX();
        int viewSizeY = view->getSizeY();

        for (int i = 0; i < viewSizeY; i++) {
            for (int j = 0; j < viewSizeX; j++) {
                if (posY + i < sizeY && posX + j < sizeX) {
                    canvas[posY + i][posX + j] = viewCanvas[i][j];
                }
            }
        }
    }


    //cout the canvas
    //top boundary:
    for(int i = 0; i < sizeX + 2; i++){
        if(i == 0 || i == sizeX + 2 - 1) cout << '+';
        else cout << '-';
    }
    cout << endl;

    for (int i = 0; i < sizeY; i++) {
        cout << '|';
        for (int j = 0; j < sizeX; j++) {
            cout << canvas[i][j];
        }
        cout << '|' << endl;
    }

    //bottom boundary:
    for(int i = 0; i < sizeX + 2; i++){
        if(i == 0 || i == sizeX + 2 - 1) cout << '+';
        else cout << '-';
    }
    cout << endl;
}

// You don't have to modify
void Window::run() {
    struct termios ter;
    tcgetattr(0, &ter);
    ter.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &ter);

    render();
    while (!exit) {
        char key;
        key = cin.get();
        if (key == 27) {
            key = cin.get();
            if (key == 91) {
                key = cin.get();
                ArrowKey arrowKey;
                if (key == 65) {
                    arrowKey = ArrowKey::UP;
                } else if (key == 66) {
                    arrowKey = ArrowKey::DOWN;
                } else if (key == 67) {
                    arrowKey = ArrowKey::RIGHT;
                } else if (key == 68) {
                    arrowKey = ArrowKey::LEFT;
                }
                onArrowKeyPress(arrowKey);
            }
        } else if (key == 10) {
            onEnterPress();
        } else {
            onNormalKeyPress(key);
        }
        render();
    }
}


// Will be called when arrow key is pressed
// If selectedView == nullptr, set the first selectable view in the vector views to selectedView
// Else set selectedView to the nearest selectable view of the current selectedView in the given direction
void Window::onArrowKeyPress(ArrowKey key){
    if(selectedView == nullptr){
        // Set the first selectable view in the vector views to selectedView
        for (View* view : views) {
            if (view->isSelectable()) {
                selectView(view);
                break;
            }
        }
    }
    else{
        int selectedIndex = -1;
        int nearestIndex = -1;
        int minDistance = sizeX + sizeY;
        int minRefDistance = sizeX + sizeY;

        // Find the index of the selected view
        for (size_t i = 0; i < views.size(); i++) {
            if (views[i] == selectedView) {
                selectedIndex = i;
                break;
            }
        }

        // Find the nearest selectable view in the given direction
        for (size_t i = 0; i < views.size(); i++) {
            if (views[i]->isSelectable() && i != size_t(selectedIndex)) {
                int distance = 0;
                int ref_distance = 0;
                if (key == ArrowKey::UP) {
                    distance = selectedView->getPosY() - views[i]->getPosY();
                    ref_distance = abs(selectedView->getPosX() - views[i]->getPosX());
                } 
                
                else if (key == ArrowKey::DOWN) {
                    distance = views[i]->getPosY() - selectedView->getPosY();
                    ref_distance = abs(views[i]->getPosX() - selectedView->getPosX());
                } 
                
                else if (key == ArrowKey::LEFT) {
                    distance = selectedView->getPosX() - views[i]->getPosX();
                    ref_distance = abs(selectedView->getPosY() - views[i]->getPosY());
                } 
                
                else if (key == ArrowKey::RIGHT) {
                    distance = views[i]->getPosX() - selectedView->getPosX();
                    ref_distance = abs(views[i]->getPosY() - selectedView->getPosY());
                }

                if (distance > 0 && distance <= minDistance){
                    if(distance == minDistance){
                        if(ref_distance <= minRefDistance){
                            nearestIndex = i;
                            minDistance = distance;
                            minRefDistance = ref_distance;
                        }
                    }
                    else{
                        nearestIndex = i;
                        minDistance = distance;
                        minRefDistance = ref_distance;
                    }
                }
            }
        }

        if (nearestIndex != -1) {
            selectView(views[nearestIndex]);
        }
    }
}

// Will be called when normal key is pressed (alphabet, symbols, backspace)
// Call onInputKey() of the selected view
void Window::onNormalKeyPress(char key){
    if(selectedView != nullptr) selectedView->onInputKey(key);
}

// Will be called when Enter key is pressed
// Call onClick() of the selected view
void Window::onEnterPress(){
    if(selectedView != nullptr) selectedView->onClick();
}

// Set the selectedView
void Window::selectView(View* view){
    selectedView = view;
    render();
}