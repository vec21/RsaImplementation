#include "number_operations.h"
#include <algorithm>




int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}


vector<int> divisors(int n){
	vector<int> divs;
	for(int i = 2;i*i<n;i++){
		if(n%i!=0){
			divs.push_back(i);
			if(n/i != i) 
				divs.push_back(n/i);
		}
	}
	return divs;
}
int chosseE(int tot){
    
    vector<int> result = divisors(tot);

   sort(result.begin(), result.end());

    for (int i = 0; i <= result.size(); i++){
        if(gcd(result[i], tot) == 1){
            return result[i]; 
        }

    }
    
    return tot;
}
int calculeD(int e, int tot){
        for (int i = 1; i <= tot; i++){
            if((i * e ) % tot == 1)
                return i;
        }
        
    return e;
}
