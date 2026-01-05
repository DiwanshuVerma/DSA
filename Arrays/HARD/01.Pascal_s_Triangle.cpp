#include<bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/pascals-triangle/description/

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it

input: 5
output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
*/

/*

optimal: O(N^2) , O(N^2)

Initialize a 2D vector ans of size numRows.

Loop from i = 0 to numRows-1:

Create a row with size i + 1.

Set first and last element of row to 1.

For each j from 1 to i-1:

Set ans[i][j] = ans[i-1][j-1] + ans[i-1][j].

Return ans.
*/

vector<vector<int>> generate(int numsRow){
    vector<vector<int>> ans(numsRow);

    for(int i=0; i<numsRow; i++){
        ans[i].resize(i+1);
        ans[i][0] = ans[i][i] = 1; // first and last element = 1
        
        for(int j=1; j<i; j++){
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }
    return ans;
}

int main(){
    int numsRow = 5;

    vector<vector<int>> ans = generate(numsRow);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) cout << ans[i][j] << " ";
        cout << endl;
    }
}