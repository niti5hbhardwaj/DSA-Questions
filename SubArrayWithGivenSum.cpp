#include<iostream>
using namespace std;

void subarrayWithSum(vector<int> array,int size, int sum){
    int i=0, j=0, currentSum = array[0];
    bool found = false;
    while(j<size){
        if(currentSum==sum){
            found = true;
            break;
        }
        else if(currentSum<sum){
            j++;
            currentSum+=array[j];
        }
        else{
            currentSum-=array[i];
            i++;
        }
    }
    if(found)
        cout<<i<<" "<<j<<endl;
    else
        cout<<"No Subarray found"<<endl;
}

int main(){
    int size;
    cin>>size;
    vector<int> array(size);
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    int sum;
    cin>>sum;
    subarrayWithSum(array, size, sum);
}