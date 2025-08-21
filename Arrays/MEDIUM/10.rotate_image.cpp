/*
https://leetcode.com/problems/rotate-image/description/

rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/

/*
    BRUTE force: tc: O(N^2) , sc: O(N)

        initialize a n*n ans matrix
        iterate through the matrix row by row, store every row as column in ans matrix
    
    Optimal: tc: O(N)
        1. transpose the matrix
            transponse: interchanging rows into columns or columns into rows
        2. reverse every row
*/

#include<bits/stdc++.h>
using namespace std;

/*
void rotateImage(vector<vector<int>> &matrix, int n){
    int ans[n][n];

    for(int i=0; i<n; i++){
       for(int j=0; j<n; j++) {
            ans[j][n-1-i] = matrix[i][j];
       }
    }
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << ans[i][j] << " ";
        cout << endl;
    }
}
    */

void rotateImage(vector<vector<int>> &matrix, int n){

    // transpose the matrix (interchanging row into columns)
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    // reverse each row
    for(int i=0; i<n; i++){
        int l=0, r=n-1;

        while(l<r){
            swap(matrix[i][l], matrix[i][r]);
            l++;
            r--;
        }
    }
}



int main() {
    // vector<vector<int>> matrix = {{1,1,1}, {1,0,1}, {1,1,1}};
    // vector<vector<int>> matrix = {{1,1,1}, {1,0,1}, {0,1,1}};
    // vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}}; // {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}}
    vector<vector<int>> matrix = {{5,1,9,11}, {2,4,8,10}, {13,3,6,7}, {15,14,12,16}};


    int n = matrix.size();

    rotateImage(matrix, n);

    // print matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
}
