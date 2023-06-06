#include<iostream>
using namespace std;

//optimised brute
int maximumSubarraySum(int array[], int size){
    int maxSum = INT_MIN;
    for(int i=0;i<size;i++){
        int sum = 0;
        for(int j=i;j<size;j++){
            sum+=array[j];
            if(sum>maxSum){
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

//kadane's algorithm
//https://youtu.be/0JYgnhnZFcE?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&t=716
int Kadanes(int array[], int size){
    int maxSum = INT_MIN;
    int currentSum = 0;
    for(int i=0;i<size;i++){
        currentSum+=array[i];
        if(currentSum<0){
            currentSum = 0;
        }
        if(currentSum>maxSum){
            maxSum = currentSum;
        }
    }
    return maxSum;
}

//maximum circular subarray sum (It means that the subarray can wrap around the array)
//https://youtu.be/0JYgnhnZFcE?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&t=980
int maximumCircularSubarraySum(int array[], int size){
    int maxSum, totalSum = 0;
    int negationArray[size];
    for(int i=0;i<size;i++){
        totalSum+=array[i];
        negationArray[i] = -array[i];
    }
    int wrapSum = totalSum + Kadanes(negationArray, size);
    int nonWrapSum = Kadanes(array, size);
    maxSum = wrapSum>nonWrapSum? wrapSum: nonWrapSum;
    return maxSum;
}


int main(){
    int size;
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    cout<<maximumCircularSubarraySum(array,size)<<endl;
}