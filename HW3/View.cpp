#include "View.h"
#include "Window.h"
#include <iostream>

//static variable should be init in class implementation
vector<View*> View::views;

// Consturctor, remember to allocate canvas 
View::View(int sizeX, int sizeY): posX(0), posY(0), sizeX(sizeX), sizeY(sizeY), selectable(false){

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

    //views.push_back(this);
}

// Destructor, remember to deallocate canvas 
View::~View(){
    if(canvas){
        for(int i = 0; i < sizeY; i++){
            delete []canvas[i];
        }
        delete []canvas;
    }
}


// Getters
int View::getSizeX(){
    return sizeX;
}

int View::getSizeY(){
    return sizeY;
}

bool View::isSelectable(){
    return selectable;
}

// Return if window->selectedView is same as self
bool View::isSelected(){
    return (window != nullptr && window->getSelectedView() == this);
}

// Callback function pointers setters
void View::setOnClickListener(void (*listener)(View*)){
    onClickListener = listener;
}

void View::setOnChangeListener(void (*listener)(View*)){
    onChangeListener = listener;
}

// Delete all created View in views, call at the end of main()
void View::deleteAllView(){
    for (View* view : views) {
        delete view;
    }
    views.clear();
}

void View::setPos(int posX, int posY){
    this->posX = posX;
    this->posY = posY;
}

void View::setWindow(Window* window){
    this->window = window;
}

int View::getPosX(){
    return posX;
}

int View::getPosY(){
    return posY;
}

// Handler: when the view is clicked, call on click listener
void View::onClick(){
    if(onClickListener != nullptr){
        onClickListener(this);
    }
}

// Handler: when the view is changed, call on change listener
void View::onChange(){
    if(onChangeListener != nullptr){
        onChangeListener(this);
    }
}

// Handler: When user input to the view
void View::onInputKey(char key){

}

// Call window render()
void View::rerenderWindow(){
    if(window != nullptr){
        window->render();
    }
}