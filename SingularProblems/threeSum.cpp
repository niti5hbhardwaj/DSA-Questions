#include<iostream>
using namespace std;

//https://youtu.be/BCLfxQja9dI?list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ

vector<int> threeSum(vector<int> arr, int sum){
    sort(arr.begin(), arr.end());
    vector<int> answer;
    for(int i=0;i<arr.size();i++){
        int low = i+1, high = arr.size()-1;
        int toFind = sum-arr[i];
        answer.push_back(arr[i]);
        while(low<high){
            if(arr[low]+arr[high]==toFind){
                answer.push_back(arr[low]);
                answer.push_back(arr[high]);
                return answer;
            } else if (arr[low]+arr[high]>toFind){
                high--;
            } else {
                low++;
            }
        }
        answer.pop_back();
    }
    return {};
}

int main(){
    vector<int> arr{12, 3, 7, 1, 6, 9};
    int sum = 23;
    vector<int> answer = threeSum(arr,sum);
    if(answer.size()!=0){
        for(auto x: answer){
            cout<<x<<" "; 
        }
    } else {
        cout<<"No three elements add up to "<<sum<<endl;
    }
    return 0;
}