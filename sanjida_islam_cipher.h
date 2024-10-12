/*

Name: Sanjida Islam

NetID: w10173067

Program Description: Takes a plain text and key and encodes or decodes it accordingly making a Caesar Cipher kind of program.

*/
#pragma once
#include <string>
using namespace std;

class Cipher {
private:
    string plaintext;
    string ciphertext;
    int key;
    void Encode();
    void Decode();
    int FindChar(char c);
    char EncodeChar(char c);
    char DecodeChar(char c);

public:
    Cipher(string text, int key, bool isEncrypted);
    void ChangeText(string text, int key, bool isEncrypted);
    string GetPlainText();
    string GetCipherText();
    int GetKey();
    void SetKey(int key);

};


