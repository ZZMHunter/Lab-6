/*
    Author: Zhao Zhang
    Course: CSCI-135
    Instructor: Tong Yi
    Assignment: Lab-6C

    Write a program vigenere.cpp. It should contain a function encryptVigenere implementing this cipher:
    The main should implement a testing interface similar to the one in Task B,
    the user enters the plaintext and the keyword, and the program reports the ciphertext.
*/

// A-Z 65-90
// a-z 97-122
#include <iostream>

int toShift(char c)
{
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
        return (char)((((int)c - 65 + rshift) % 26) + 65);
    }
    else if ((int)c >= 97 && (int)c <= 122)
    {
        return (char)((((int)c - 97 + rshift) % 26) + 97);
    }
    return c;
}

std::string encryptVigenere(std::string plaintext, std::string keyword)
{
    std::string encryptedString = "";
    int count = 0;
    for (int i = 0; i < plaintext.length(); i++)
    {
        int shift = toShift(keyword[count % keyword.length()]);
        encryptedString += shiftChar(plaintext[i], shift);
        // std::cout << plaintext[i] << count << shiftChar(plaintext[i], shift) << std::endl;
        if (toShift(plaintext[i]) != -1)
        {
            count++;
        }
    }
    return encryptedString;
}

int main()
{
    std::string plaintext;
    std::string keyword;
    std::cout << "Enter plaintext: ";
    getline(std::cin, plaintext);
    std::cout << "Enter keyword: ";
    getline(std::cin, keyword);
    std::cout << encryptVignere(plaintext, keyword);
    return 0;
}