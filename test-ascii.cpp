/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Lab-6A

    Write a program test-ascii.cpp that asks the user to input a line of text (which may possibly include spaces). 
    The program should report all characters from the input line together with their ASCII codes.
*/

#include <iostream>

int main(){
    std::string input;
    std::cout << "Input: ";
    getline(std::cin, input);
    for (int i = 0; i < input.length(); i++){
        std::cout << input[i] << " " << (int)input[i] << std::endl;
    }
    return 0;
}