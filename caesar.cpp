/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Lab-6B

    Write a program caesar.cpp with functions implementing Caesar cipher encryption
    The main function should ask the user to input a plaintext sentence, 
    then enter the right shift, and report the ciphertext computed using your encryption function.
*/

//A-Z 65-90
//a-z 97-122
#include <iostream>

char shiftChar(char c, int rshift){
    if ((int)c >= 65 && (int)c <= 90){
        if ((int)c + rshift > 90){
            return (char)((int)c+rshift-26);
        }else{
            return (char)((int)c+rshift);
        }
    }else if ((int)c >= 97 && (int)c <= 122){
        if ((int)c + rshift > 122){
            return (char)((int)c+rshift-26);
        }else{
            return (char)((int)c+rshift);
        }
    }
    return c;
}

std::string encryptCaesar(std::string plaintext, int rshift){
    std::string encryptedString;
    for (int i = 0; i < plaintext.length(); i++){
        encryptedString += shiftChar(plaintext[i], rshift);
    }
    return encryptedString;
}

int main(){
    std::string plaintext;
    int shift;
    std::cout << "Enter plaintext: ";
    getline(std::cin,plaintext);
    std::cout << "Enter shift: ";
    std::cin >> shift;
    std::cout << encryptCaesar(plaintext, shift);
    return 0;
}