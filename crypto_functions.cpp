#include "crypto_functions.h"


long long int encrypt(double message, int public_key, int n){
    int e = public_key;
    long long int encrpyted_text = 1;
    while (e--) {
        encrpyted_text *= message;
        encrpyted_text %= n;
    }
    return encrpyted_text;
}

long long int decrypt(int encrpyted_text, int private_key, int n){
    int d = private_key;
    long long int decrypted = 1;
    while (d--) {
        decrypted *= encrpyted_text;
        decrypted %= n;
    }
    return decrypted;
}

vector<int> encoder(string message,  int public_key, int n){
    vector<int> form;
    // calling the encrypting function in encoding function
    for (auto& letter : message)
        form.push_back(encrypt((int)letter, public_key, n));
    return form;
}

string decoder(vector<int> encoded, int private_key, int n){
    string s;
    // calling the decrypting function decoding function
    for (auto& num : encoded)
        s += decrypt(num, private_key, n);
    return s;
}