#include<iostream>
using namespace std;

//https://youtu.be/7FE5Q_Bqzw8?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ

int maxConsecutiveOnes(vector<int> arr, int k){
    int start = 0, end = 0, count = 0, maxLength = INT_MIN, currentLength = 0;
    while(end<arr.size()){
        if(arr[end]==1){
            end++;
            currentLength++;
        } else if(arr[end]==0){
            end++;
            count++;
            currentLength++;
        }
        while(count>k){
            if(arr[start]==0){
                count--;
            }
            start++;
            currentLength--;
        }
        maxLength = max(maxLength, currentLength);
    }
    return maxLength;
}

int main(){
    vector<int> arr {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    cout<<maxConsecutiveOnes(arr, k)<<endl;
}