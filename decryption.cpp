/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Lab-6D

    Write a program decryption.cpp that uses the above functions to demonstrate encryption and decryption for both ciphers.
    It should first ask the user to input plaintext, then ask for a right shift 
    for the Caesar cipher and report the ciphertext and its subsequent decryption. 
    After that, it should do the same for the Vigenere cipher.
*/

#include <iostream>
#include <string>

int toShift(char c)
{
    //returns how much the keyword's character is shifting and returns the number otherwise if
    //outside bounds, it will return -1
    if ((int)c >= 65 && (int)c <= 90)
    {
        return (int)c - 65;
    }
    else if ((int)c >= 97 && (int)c <= 122)
    {
        return (int)c - 97;
    }
    return -1;
}

char shiftChar(char c, int rshift)
{
    if (rshift == -1)
    {
        return c;
    }
    if ((int)c >= 65 && (int)c <= 90)
    {
        //turns c into an int so that the base starting number can subtract from it, then subtract the shift and add 26 to get 
        //the amount it should change by then add 65 and convert to char to get the resulting number
        return (char)((((int)c - 65 - rshift + 26) % 26) + 65);
    }
    else if ((int)c >= 97 && (int)c <= 122)
    {
        return (char)((((int)c - 97 - rshift + 26) % 26) + 97);
    }
    return c;
}

std::string decryptVigenere(std::string plaintext, std::string keyword)
{
    std::string encryptedString = "";
    int count = 0;
    for (int i = 0; i < plaintext.length(); i++)
    {
        int shift = toShift(keyword[count % keyword.length()]);
        encryptedString += shiftChar(plaintext[i], shift);
        if (toShift(plaintext[i]) != -1)
        {
            count++;
        }
    }
    return encryptedString;
}

std::string decryptCaesar(std::string plaintext, int rshift)
{
    std::string encryptedString;
    for (int i = 0; i < plaintext.length(); i++)
    {
        encryptedString += shiftChar(plaintext[i], rshift);
    }
    return encryptedString;
}

int main()
{
    std::string caesarText, vigenereText, keyword;
    int shift;
    std::cout << "Enter plaintext: ";
    std::getline(std::cin, caesarText);
    std::cout << "Enter shift: ";
    std::cin >> shift;
    std::cin.ignore();
    std::cout << decryptCaesar(caesarText, shift) << std::endl;
    std::cout << "Enter plaintext: ";
    std::getline(std::cin, vigenereText);
    std::cout << "Enter keyword: ";
    std::getline(std::cin, keyword);
    std::cout << decryptVignere(vigenereText, keyword) << std::endl;
    return 0;
}
