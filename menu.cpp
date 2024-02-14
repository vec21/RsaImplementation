#include "menu.h"
#include "crypto_functions.h"
#include "prime_functions.h"
#include <iostream>





// Função para exibir o menu
void showMenu() {
    int escolha;
    //string mensagem, resultado;
    long long min = 200;
    long long max = 6001;
    // Gerando p e q primos
    long long p = generatePrime(min, max);
    long long q = generatePrime(min, max);
    long long n, tot, e, d;

    n = p * q;
    tot = (p - 1) * (q - 1);
    e = chosseE(tot);
    d = calculeD(e, tot);
    string message;
    vector<int> coded ;

    do {
        // Exibir menu
        cout << "\nMenu:\n";
        cout << "1. Criptografar\n";
        cout << "2. Descriptografar\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
                
                //void radom();
                cout<< "1/ p e q : " << p <<" "<< q <<"\n";
                cout<< "2/ n = p * q: " << n <<  "\n";
                cout<< "3/ ϕ(n) = (p - 1) * (q - 1): " << tot <<  "\n";
                cout<< "4/ e = " << e <<  "\n";
                cout<< "5/ d = " << d <<  "\n";
                cout<<  "Public Key:  {e, n} = "<<" {"<<e<<", " <<n<<"}"<< "\n";
                cout<<  "Private Key: {d, n} = "<<" {"<<d<<", " <<n<<"}"<< "\n";
                cout<<  "Encripty: c = m ^ e  mod  n "<< "\n";
                cout<<  "Decripty: m = c ^ d  mod  n "<< "\n";
                cout<<"\n";
                cout<<"\n";
                cout << "Digite a mensagem a ser criptografada: ";
                cin.ignore();
                getline(cin, message);
                coded =  encoder(message, e, n);

                cout << "\n\nThe encoded message(encrypted by public "
            "key)\n";
                for (auto& p : coded)
                      cout << p<<" ";

                //cout<<  "Mensagem a Encriptar: "<< message<<endl;
                
                break;
            case 2:
                cout << "Digite a mensagem criptografada: ";
                cin.ignore(); // Limpar o buffer do teclado


                cout << "Digite a mensagem criptografada: ";
                cout << "\n\nThe decoded message(decrypted by private "
               "key)\n";
                cout << decoder(coded, d, n) << endl;
               // getline(cin, mensagem);
                //resultado = decrypt(mensagem);
               // cout << "Mensagem descriptografada: " << resultado << endl;
                break;
            case 3:
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (escolha != 3);
}
