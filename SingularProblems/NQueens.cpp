#include<iostream>
using namespace std;

bool isSafe(vector<vector<int>> &answer, int x, int y){
    if(x>=answer.size() || y>=answer.size()){
        return false;
    }
    
    //checking for a queen in same column
    for(int row = x-1; row>=0; row--){
        if(answer[row][y]){
            return false;
        }
    }
    
    //checking for queen in left diagonal
    for(int i = x-1, j = y-1; i>=0 && j>=0; i--, j--){
        if(answer[i][j]){
            return false;
        }
    }
    
    // //checking for queen in right diagonal
    for(int i = x-1, j = y+1; i>=0 && j<answer.size(); i--, j++){
        if(answer[i][j]){
            return false;
        }
    }
    return true;
}

bool NQueens(vector<vector<int>> &answer, int N, int x){
    if(x==N){
        return true;
    }
    for(int column = 0; column < N; column++){
        if(isSafe(answer, x, column)){
            answer[x][column] = 1;
            if(NQueens(answer, N, x+1)){
                return true; 
            }
            answer[x][column] = 0;
        }
    }
    return false;
}

int main(){
    int N;
    cin>>N;
    vector<vector<int>> answer(N, vector<int>(N, 0));
    NQueens(answer, N, 0);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}