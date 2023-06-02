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
int maximumCircularSubarraySum(int array[], int size){
    int maxSum;
    int negationArray[size];
    for(int i=0;i<size;i++){
        negationArray[i] = -array[i];
    }
    int wrapSum = Kadanes(negationArray, size);
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