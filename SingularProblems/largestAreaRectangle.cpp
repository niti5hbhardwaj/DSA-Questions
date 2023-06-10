#include<iostream>
using namespace std;

//Brute Force
int largestAreaRectangle(vector<int> arr){
    int area = INT_MIN;
    for(int i=0;i<arr.size();i++){
        int minHeight = INT_MAX;
        for(int j=i;j<arr.size();j++){
            minHeight = min(minHeight, arr[j]);
            int width = j-i+1;
            area = max(area, minHeight*width);
        }
    }
    return area;
}

int main(){
    vector<int> arr{2,1,5,6,2,3};
    cout<<largestAreaRectangle(arr)<<endl;
}