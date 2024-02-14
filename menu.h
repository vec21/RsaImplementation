#ifndef CRYPTO_MENU_H
#define CRYPTO_MENU_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;


// Função para exibir o menu
void showMenu();

int chosseE(int tot);
int calculeD(int e, int tot);
vector<int> divisors(int n);

#endif  // CRYPTO_MENU_H
