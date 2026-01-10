/* https://leetcode.com/problems/binary-search/description/ */

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
*/

#include<iostream>
#include<vector>
using namespace std;

int Search(vector<int> &nums, int target) {
    int low=0, high=nums.size()-1;
    
    while(low<=high) {
        int mid = low+(high-low)/2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main(){
    vector nums = {3, 4, 6, 7, 9, 12, 16, 17}; // sorted array
    int target = 6; // target element to search  // ans -> 2
    cout << Search(nums, target) << endl;
}