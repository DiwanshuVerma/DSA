/*
   https://leetcode.com/problems/single-number/description/
   Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
*/

/*
    SOLUTION:
    i. use XOR(^): O(N)
        if two elements are same then it returns 0

    ii. sort array then find uniqe number: O(N log N)
        1. sort(arr.begin(), arr.end())
        4. loop from 0 -> n-2 
         for(i=0; i<n-1; i+2)
            if(arr[i] != arr[i+1]) return arr[i]
            
        [1, 1, 2, 2, 4]
         If all pairs are found, last element is the unique one
        5. return arr[n-1]
        
*/

#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> arr, int n){
    int singleNum = 0;

    for(int i = 0; i<n; i++) singleNum ^= arr[i];
    
    return singleNum;
}

int main(){
    vector<int> arr = {4, 1, 2, 3, 1, 2, 4};
    int n = arr.size();
    cout << singleNumber(arr, n) << endl;
}
