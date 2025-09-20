/*
    LC: https://leetcode.com/problems/maximum-subarray/description/
    Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

/*
    Kadane's algorithm: O(N)
    1. initialize two variables:
        maxSum, currSum
    2. loop through the array
        sum every ele in currSum
        consider maximum sum in maxSum
        if currSum value becomes less than 0 then reset it to 0
    3. return maxSum
*/

#include <bits/stdc++.h>
using namespace std;

int maximumSubarray(vector<int> nums){
    int n = nums.size();
    long long maxSum = LONG_MIN;
    long long currSum = 0;

    for(int i=0; i<n; i++) {
        currSum += nums[i];
        maxSum = max(maxSum, currSum);

        if(currSum < 0) currSum = 0;
    }

    return maxSum;
}   

int main(){
    // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4}; // 6
    vector<int> nums = {5,4,-1,7,8}; // 23
    cout << maximumSubarray(nums) << endl;
}
