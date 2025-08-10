/*
LC: https://leetcode.com/problems/sort-colors/description/

Given an array nums with n objects colored red, white, or blue,     
sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
expected TC: N, SC: 1

 SOLUTION: Dutch National Flag Algorithm
    using three pointers
    1. initailize three variables:
        low=0, mid=0, high=n-1
    2. iterate while low<=high
        if mid == 0, swap with low, move both low++ and mid++
        if mid == 1, just move mid++
        if mid == 2, swap with high, just move high--


*/

#include <bits/stdc++.h>
using namespace std;

void SortColors(vector<int> &nums){
    int low=0;
    int mid=0;  
    int high=nums.size()-1;

    while(mid<=high){
        if(nums[mid] == 0) {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1) mid++;
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    } 
}

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    // vector<int> nums = {2,0,1};
    SortColors(nums);

    for (int i=0; i<nums.size(); i++) cout << nums[i] << " " ;
}