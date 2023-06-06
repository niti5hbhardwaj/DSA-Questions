#include<iostream>
using namespace std;

bool isSafe(vector<vector<int>> &matrix, int x, int y){
    if(x>=matrix.size() || y>=matrix.size())
        return false;
    if(matrix[x][y]==0){
        return false;
    }
    return true;
}

bool ratInAMaze(vector<vector<int>> matrix, int x, int y, vector<vector<int>> &answer){
    if(x==matrix.size()-1 && y==matrix.size()-1){
        answer[x][y] = 1;
        return true;
    }

    if(isSafe(matrix, x, y)){
        answer[x][y] = 1;
        if(ratInAMaze(matrix, x+1, y, answer)){
            return true;
        }
        if(ratInAMaze(matrix, x, y+1, answer)){
            return true;
        }
        answer[x][y] = 0;
        return false;
    }
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int size;
    cin>>size;
    vector<vector<int>> matrix(size, vector<int>(size, 0));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>> answer(size, vector<int> (size, 0));
    if(ratInAMaze(matrix, 0, 0, answer)){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                cout<<answer[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}