#include <iostream>
#include <vector>
#include <ctype.h>
#include <string>
#include "sanjida_islam_cipher.h"

using namespace std;

Cipher::Cipher(string text, int key, bool isEncrypted) {
    if (isEncrypted) {
        this->ciphertext = text;
        SetKey(key);
        Decode();
    }
    else {
        this->plaintext = text;
        SetKey(key);
        Encode();
    }
    return;
}

string Cipher::GetPlainText() {
    return this->plaintext;
}

string Cipher::GetCipherText() {
    return this->ciphertext;
}

int Cipher::GetKey() {
    return this->key;
}

void Cipher::SetKey(int key) {
    if (key == 0) {
        return;
    }
    this->key = key;
    return;
}

void Cipher::ChangeText(string text, int key, bool isEncrypted) {
    SetKey(key);
    if (isEncrypted) {
        this->ciphertext = text;
    }
    else {
        this->plaintext = text;
    }
    return;
}

void Cipher::Encode() {
    string text = this->plaintext;
    string encoded = "";
    for (char c : text) {
        encoded = encoded + EncodeChar(c);
    }
    this->ciphertext = encoded;
}

void Cipher::Decode() {
    string text = this->ciphertext;
    string decoded = "";
    for (char c : text) {
        decoded = decoded + DecodeChar(c);
    }
    this->plaintext = decoded;
}

char Cipher::EncodeChar(char c) {
    int key = this->key;
    int position = FindChar(c);

    if (position == -1) {
        return c;
    }

    int new_position;
    char new_char;

    if ((position + key) >= 0) {
        new_position = (position + key) % 26;
    } else {
        new_position = (26 + (position + key)) % 26;
    }
    if (isupper(c)) {
        new_char = 65 + new_position;
    } else {
        new_char = 97 + new_position;
    }
    return new_char;
}

char Cipher::DecodeChar(char c) {
    int key = this->key;
    int position = FindChar(c);

    if (position == -1) {
        return c;
    }

    int new_position;
    char new_char;
    if ((position - key) >= 0) {
        new_position = (position - key) % 26;
    }
    else {
        new_position = (26 + (position - key)) % 26;
    }
    if (isupper(c)) {
        new_char = 65 + new_position;
    }
    else {
        new_char = 97 + new_position;
    }
    return new_char;
}

int Cipher::FindChar(char character) {
    char c = toupper(character);
    vector<char> alphabets = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    // vector<char> alphabets = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    vector<int> positions = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
    int length = alphabets.size();
    for (int i = 0; i < length; i++) {
        char alphas = alphabets.at(i);
        if (alphas == c) {
            return positions.at(i);
        }
    }
    return -1;
}

int main() {
    cout << "Let's encode a message!" << endl;
    string text;
    int key;
    cout << "---> Shift Key: ";
    cin >> key;
    
    cout << endl;
    cin.get();
    cout << "--->Plain Text: ";
    getline(cin, text);

    Cipher encode(text, key, false); 
    string ciphertext = encode.GetCipherText();
    cout << "--->Cipher Text: " << ciphertext;

    cout << endl;
    cout << endl;

    cout << "Now I am going to take the Cipher Text Above and convert it back to Plain!" << endl;
    Cipher decode(ciphertext, key, true);
    string plaintext = decode.GetPlainText();
    cout << "--->Result: " << plaintext;


    return 0;
}
