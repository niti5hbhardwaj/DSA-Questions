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

int main(){
    int n;
    cin>>n;
    sieveOfEratosthenes(n);
    return 0;
}