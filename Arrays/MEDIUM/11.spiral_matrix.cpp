/*
https://leetcode.com/problems/spiral-matrix/description/

Given an m x n matrix, return all elements of the matrix in spiral order.
*/

/*
we will be using four loops to print all four sides of the matrix.

1st loop: This will print the elements from left to right.

2nd loop: This will print the elements from top to bottom.

3rd loop: This will print the elements from right to left.

4th loop: This will print the elements from bottom to top.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(); // no. of rows
    int n = matrix[0].size(); // no. of columns
    vector<int> ans;

    int top = 0, left = 0, right = n-1, bottom = m-1;

    while(top <= bottom && left <= right) {

        // left to right
        for(int i = left; i<=right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        // top to bottom
        for(int i=top; i<=bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // right to left
        if(top <= bottom){
            for(int i = right; i>=left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // bottom to top
        if(left <= right) {
            for(int i=bottom; i>=top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
    }
    }

    return ans;
}

int main(){
    // vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}}; // {1,2,3,6,9,8,7,4,5}
    vector<vector<int>> matrix = {{1,2,3,4},
                                    {5,6,7,8},
                                    {9,10,11,12}}; // {1,2,3,4,8,12,11,10,9,5,6,7}

    vector<int> ans = spiralOrder(matrix);
    for(int i: ans) cout << i << " ";
}