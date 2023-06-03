#include<iostream>
using namespace std;

void sieveOfEratosthenes(int n){
    bool prime[n+1];
    for(int i=0;i<n+1;i++){
        prime[i] = true;
    }

    for(int i=2;i<=n;i++){
        if(prime[i]==true){
            for(int j=i*i;j<=n;j+=i){
                prime[j] = false;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(prime[i])
            cout<<i<<" ";
    }
}

void primeFactors(int num){
    int primeFactor[num+1];
    for(int i=0;i<=num;i++){
        if(i<2){
            primeFactor[i] = 0;
        }
        primeFactor[i] = i;
    }

    for(int i=2;i<=num;i++){
        if(primeFactor[i]==i){
            for(int j=i*i;j<=num;j+=i){
                if(primeFactor[j]==j)
                    primeFactor[j] = i;
            }
        }
    }

    while(num!=1){
        cout<<primeFactor[num]<<" ";
        num/= primeFactor[num];
    }
}

int main(){
    int n;
    cin>>n;
    primeFactors(n);
    return 0;
}