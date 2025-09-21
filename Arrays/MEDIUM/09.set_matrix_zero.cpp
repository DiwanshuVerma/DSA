/*
https://leetcode.com/problems/set-matrix-zeroes/description/

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
*/


/*
    brute force TC: O(m∗n), SC: O(m+n)
        create two arrays:
            a column array which will keep track of all the zeroes of j-th position
            a row array it will keep track of all the zeroes of i-th position
            
            iterate through the array
                if any element of [i][j]-th position is zero then make row[i] and col[j] zero

            now that we have both the arrays containing indexes of rows and column to be turned zero
                we will iterate through our matrix array again and check if row[i] or col[j] is zero then update the current element into zero iteself


    OPTIMAL: TC: O(m∗n) , SC: O(1)
        instead of creating two separate arrays we will make our existing array's first col and first row's element zero
        
        STEP1: iterate through the matrix, if a element is zero then make its curresponding arr[i][0] and arr[0][j] = 0
    
        STEP2: Mark with 0 from (1,1) to (n-1, m-1):

        STEP3: Finally mark the 1st col & then 1st row:
*/

#include<bits/stdc++.h>
using namespace std;

// ----------------> brute force: TC: O(m∗n) ==> N^2 , SC: O(m+n)
/*
void setZeroes(vector<vector<int>> &matrix, int m, int n){
    vector<int> row(m, 0);
    vector<int> col(n, 0);


    // iterate through the matrix: if there is zero then update curresponding row and column
    
    for(int i=0; i<m; i++){             // ---> O(m) *
        for(int j=0; j<n; j++){          // ---> O(n)
            if(matrix[i][j] == 0){
                row[i] = -1;  // keep track of the row
                col[j] = -1;  // keep track of the column
            }
        }
    }

    // now that we have updated matrix with curresponding -1 rows and column, updated them to 0
    for(int i=0; i<m; i++){              // ---> O(m) *
        for(int j=0; j<n; j++){          // ---> O(n)
            if(row[i] == -1 || col[j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
}
*/

// -----------------> OPTIMAL: tc: O(m*n) , sc: O(1)
void setZeroes(vector<vector<int>> &matrix, int m, int n){
    int col0 = 1;  // flag for first column

    // iterate through the matrix, if a element is zero then make its curresponding arr[i][0] and arr[0][j] = 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;  // mark row

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    // vector<vector<int>> matrix = {{1,1,1}, {1,0,1}, {1,1,1}};
    // vector<vector<int>> matrix = {{1,1,1}, {1,0,1}, {0,1,1}};
    vector<vector<int>> matrix = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};

    int m = matrix.size();
    int n = matrix[0].size();

    setZeroes(matrix, m, n);

    // print matrix
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
}
