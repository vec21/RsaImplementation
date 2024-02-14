#ifndef CRYPTO_FUNCTIONS_H
#define CRYPTO_FUNCTIONS_H

#include <string>
#include <vector>

using namespace std;


// Função para criptografar uma mensagem usando chave pública e módulo n
long long int encrypt(double message, int public_key, int n);

// Função para descriptografar uma mensagem usando chave privada e módulo n
long long int decrypt(int encrypted_text, int private_key, int n);

// Função para codificar uma mensagem usando criptografia
vector<int> encoder(string message, int public_key, int n);

// Função para decodificar uma mensagem usando descriptografia
string decoder(vector<int> encoded, int private_key, int n);

#endif  // CRYPTO_FUNCTIONS_H
