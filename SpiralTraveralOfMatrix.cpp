#include<iostream>
using namespace std;

vector<int> spiralTraversal(vector<vector<int>> array, int rows, int columns){
    int topLimit, bottomLimit, leftLimit, rightLimit;
    topLimit = 0;
    bottomLimit = rows-1;
    leftLimit = 0;
    rightLimit = columns -1;
    vector<int> traverseOrder;
    
    while(leftLimit<=rightLimit || topLimit<= bottomLimit){

        for(int column = leftLimit; column<= rightLimit; column++){
            traverseOrder.push_back(array[topLimit][column]);
        }
        topLimit++;

        for(int row = topLimit; row<= bottomLimit; row++){
            traverseOrder.push_back(array[row][rightLimit]);
        }
        rightLimit--;

        for(int column = rightLimit; column>= leftLimit; column--){
            traverseOrder.push_back(array[bottomLimit][column]);
        }
        bottomLimit--;

        for(int row = bottomLimit; row>= topLimit; row--){
            traverseOrder.push_back(array[row][leftLimit]);
        }
        leftLimit++;
    }
    return traverseOrder;
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
    vector<int> traverseOrder = spiralTraversal(array, rows, columns);
    for(auto x: traverseOrder){
        cout<<x<<" ";
    }
}