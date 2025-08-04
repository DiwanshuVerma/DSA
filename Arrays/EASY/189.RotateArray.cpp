#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/rotate-array/description/
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/


void reverse(vector<int> &arr, int start, int end){
    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotate(vector<int> &arr, int k){
    int n = arr.size();

    // reverse first n-k elements
    reverse(arr, 0, n-k-1);

    // reverse last k elements
    reverse(arr, n-k, n-1);

    // reverse whole array
    reverse(arr, 0, n-1);
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    rotate(arr, 3);
    for(int i=0; i<arr.size(); i++) cout << arr[i] << " ";
}