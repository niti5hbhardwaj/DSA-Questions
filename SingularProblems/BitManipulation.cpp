#include<iostream>
using namespace std;

// https://youtu.be/MiJdgxTWaFs?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
int getBit(int number, int position){
    return ((number & (1<<position))!=0);
}

int setBit(int number, int position){
    return (number | (1<<position));
}

int clearBit(int number, int position){
    return (number & ~(1<<position));
}

int updateBit(int number, int position, int value){
    number = clearBit(number, position);
    return (number | (value<<position));
}

// https://youtu.be/s8l8NWII3qw?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
int isPowerOf2(int number){
    return (number && !(number & (number-1)));
}

int numberOfOnes(int number){
    int count = 0;
    while(number){
        number = number & number-1;
        count++;
    }
    return count;
}

void subsets(int arr[], int size){
    for(int i=0;i<(1<<size);i++){
        for(int j=0;j<size;j++){
            if( i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}

//https://youtu.be/WEpLyOc0bCE?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ
int uniqueElement(int arr[], int size){
    int element = 0;
    for(int i=0;i<size;i++){
        element = element ^ arr[i];
    }
    return element;
}

void twoUniqueElements(int arr[], int size){
    int xorSum = uniqueElement(arr, size);
    int tempXor = xorSum;
    int rightmostBit = 0;
    int positionOfRightmostSetBit = -1;

    while(rightmostBit!=1){
        rightmostBit = tempXor & 1;
        positionOfRightmostSetBit++;
        tempXor = tempXor>>1;
    }

    int firstUniqueElement = 0;
    for(int i=0;i<size;i++){
        if(getBit(arr[i], positionOfRightmostSetBit)){
            firstUniqueElement = firstUniqueElement ^ arr[i];
        }
    }
    int secondUniqueElement = firstUniqueElement ^ xorSum;
    cout<<firstUniqueElement<<" "<<secondUniqueElement<<endl;
}

int main(){
    int size = 6;
    int arr[] = {1,2,3,4,2,1};
    twoUniqueElements(arr,size);
    return 0;
}