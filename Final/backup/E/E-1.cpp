#include <iostream>

#include "Minecraft.h"

using namespace std;

int main() {
    Minecraft minecraft("./map/1.map");
    minecraft.render();
}