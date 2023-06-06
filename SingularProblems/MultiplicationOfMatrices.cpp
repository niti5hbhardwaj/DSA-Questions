#include<iostream>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> array1, vector<vector<int>> array2){
    int rows1 = array1.size();
    int columns1 = array1[0].size();
    int columns2 = array2[0].size();
    vector<vector<int>> result(rows1, vector<int> (columns2, 0));
    for(int i=0;i<rows1;i++){
        for(int j=0;j<columns2;j++){
            for(int k=0;k<columns1;k++){
                result[i][j]+= array1[i][k] * array2[k][j];
            }
        }
    }
    return result;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int rows1, columns1;
    cin>>rows1>>columns1;
    vector<vector<int>> array1(rows1, vector<int> (columns1, 0));
    for(int i=0;i<rows1;i++){
        for(int j=0;j<columns1;j++){
            cin>>array1[i][j];
        }
    }

    int rows2, columns2;
    cin>>rows2>>columns2;
    vector<vector<int>> array2(rows2, vector<int> (columns2, 0));
    for(int i=0;i<rows2;i++){
        for(int j=0;j<columns2;j++){
            cin>>array2[i][j];
        }
    }

    if(columns1==rows2){
        vector<vector<int>> result = multiply(array1, array2);
        for(int i=0;i<result.size();i++){
            for(int j=0;j<result[0].size();j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    } else{
        cout<<"Matrices cannot be multiplied"<<endl;
    }
    return 0;
}