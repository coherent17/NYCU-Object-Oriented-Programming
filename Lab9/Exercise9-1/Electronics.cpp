#include "Electronics.h"

Electronics::Electronics(int length, int width):length(length), width(width){
    usage = false;
    charging = false;
}

Electronics::~Electronics(){
    
}

bool Electronics::get_usage(){
    return usage;
}

void Electronics::set_usage(bool flag){
    usage = flag;
}

bool Electronics::get_charging(){
    return charging;
}

void Electronics::set_charging(bool flag){
    charging = flag;
}

int Electronics::get_length(){
    return length;
}

int Electronics::get_width(){
    return width;
}

void Electronics::poweron(){

}

void Electronics::run(){

}

void Electronics::charge(){

}

void Electronics::poweroff(){

}