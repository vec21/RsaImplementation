
#include "prime_functions.h"
#include "number_operations.h"
#include <vector>
#include <iostream>
#include <random>

using namespace std;

bool era(long long n){
    if (n <= 1) // 0 e 1 não são primos
        return false;

    vector<bool> isPrime(n+1,true);
    isPrime[0] = isPrime[1] = false;

    for(long long i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(long long j=i*i;j<=n;j+=i)
                isPrime[j] = false;
        }
    }
    return isPrime[n];
}
long long generatePrime(long long min, long long max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<long long> distribution(min, max);

    long long candidate = distribution(gen);

    while (!era(candidate)) {
        candidate = distribution(gen);
    }

    return candidate;
}
/*void radom(){
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
    
    vector<int> coded = encoder(message, e, n);
    cout<< "1/ p e q : " << p <<" "<< q <<"\n";
    cout<< "2/ n = p * q: " << n <<  "\n";
    cout<< "3/ ϕ(n) = (p - 1) * (q - 1): " << tot <<  "\n";
    cout<< "4/ e = " << e <<  "\n";
    cout<< "5/ d = " << d <<  "\n";
    cout<<  "Public Key:  {e, n} = "<<" {"<<e<<", " <<n<<"}"<< "\n";
    cout<<  "Private Key: {d, n} = "<<" {"<<d<<", " <<n<<"}"<< "\n";
    cout<<  "Encripty: c = m ^ e  mod  n "<< "\n";
    cout<<  "Decripty: m = c ^ d  mod  n "<< "\n";

} */