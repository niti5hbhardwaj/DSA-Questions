#include<iostream>
using namespace std;

int sumTillN(int number){
    if(number==1)
        return 1;
    return (number + sumTillN(number-1));
}

int nToPowerP(int number, int power){
    if(power==1){
        return number;
    }
    return (number * nToPowerP(number, power-1));
}

int factorial(int number){
    if(number==1){
        return 1;
    }
    return (number * factorial(number-1));
}

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

bool sorted(int arr[], int size){
    if(size==1){
        return true;
    }
    if(arr[0]<arr[1] && sorted(arr+1, size-1)){
        return true;
    }
    return false;
}

int firstOccurence(int arr[], int size, int key, int index){
    if(index==size){
        return -1;
    }
    if(arr[index]==key){
        return index;
    }
    return firstOccurence(arr,size,key,index+1);
}

int lastOccurence(int arr[], int size, int key, int index){
    if(index==size){
        return -1;
    }
    int foundAt = lastOccurence(arr, size, key, index+1);
    if(foundAt!=-1){
        return foundAt;
    }
    if(arr[index]==key){
        return index;
    }
    return -1;
}

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<lastOccurence(arr,size,key,0)<<endl;
}