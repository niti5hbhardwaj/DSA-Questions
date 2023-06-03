#include<iostream>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>> &array, int rows, int columns){
    for(int i=0;i<rows;i++){
        for(int j=0;j<=i;j++){
            swap(array[i][j], array[j][i]);
        }
    }
    return array;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int rows, columns;
    cin>>rows>>columns;
    vector<vector<int>> array(rows, vector<int> (columns, 0));
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin>>array[i][j];
        }
    }
    vector<vector<int>> transposeMatrix = transpose(array, rows, columns);
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}