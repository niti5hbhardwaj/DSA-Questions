#include<iostream>
using namespace std;

int numberOfWays(int s, int e){
    if(s==e)
        return 1;
    if(s>e)
        return 0;

    int count=0;
    for(int i=1;i<=6;i++){
        count+=numberOfWays(s+i,e);
    }
    return count;
}

int countMazePaths(int n, int i, int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    return countMazePaths(n, i+1, j) + countMazePaths(n, i, j+1);
}

int tilingWays(int n){
    if(n==0 || n==1){
        return n;
    }
    return tilingWays(n-1) + tilingWays(n-2);
}

int pairingWays(int n){
    if(n==0||n==1||n==2){
        return n;
    }
    return ((n-1)*pairingWays(n-2))+pairingWays(n-1);
}

int knapsack(int weight[], int value[], int n, int W){
    if(n==0 || W==0){
        return 0;
    }
    if(weight[n-1]>W){
        knapsack(weight, value, n-1, W);
    }
    return max(value[n-1] + knapsack(weight, value, n-1, W-weight[n-1]), knapsack(weight, value, n-1, W));
}

int main(){
    int weight[] = {10,20,30};
    int value[] = {100,50,150};
    int n = 3;
    int W = 50;
    cout<<knapsack(weight, value, n, W);
}