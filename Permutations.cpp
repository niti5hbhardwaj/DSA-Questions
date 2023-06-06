#include<iostream>
using namespace std;

void permutate(vector<int> &arr, int index, vector<vector<int>> &answer){
    if(index == arr.size()){
        answer.push_back(arr);
        return;
    }
    for(int i = index;i<arr.size();i++){
        swap(arr[i], arr[index]);
        permutate(arr, index+1, answer);
        swap(arr[index], arr[i]);
    }
    return;
}

int main(){
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    vector<vector<int>> answer;
    permutate(arr, 0, answer);
    for(auto x: answer){
        for(int i=0;i<size;i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }

}