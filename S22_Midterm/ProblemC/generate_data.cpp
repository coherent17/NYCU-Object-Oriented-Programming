#include <iostream>
#include <fstream>

int main() {
    // Open the binary file in binary mode
    std::ofstream file("1.dat", std::ios::binary);

    if (file.is_open()) {
        // Array of numbers to write into the binary file
        int numbers[] = {5, -1, 2, 0, -2, 1};

        // Write the array of numbers into the binary file
        file.write(reinterpret_cast<char*>(numbers), sizeof(numbers));

        // Close the binary file
        file.close();

        std::cout << "Numbers written to 1.dat successfully." << std::endl;
    } else {
        std::cerr << "Failed to open 1.dat for writing." << std::endl;
    }


    // Open the binary file in binary mode
    std::ofstream file2("2.dat", std::ios::binary);

    if (file2.is_open()) {
        // Array of numbers to write into the binary file
        int numbers[] = {6, 1, 0, -1, 0, 1, 0};

        // Write the array of numbers into the binary file
        file2.write(reinterpret_cast<char*>(numbers), sizeof(numbers));

        // Close the binary file
        file2.close();

        std::cout << "Numbers written to 2.dat successfully." << std::endl;
    } else {
        std::cerr << "Failed to open 2.dat for writing." << std::endl;
    }

    return 0;
}
