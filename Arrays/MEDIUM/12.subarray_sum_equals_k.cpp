/*
https://leetcode.com/problems/subarray-sum-equals-k/description/

given an array of integers nums and an integer k ,task is to return total number of subarrays whose sum equals k

Input: nums = [1,1,1], k = 2
Output: 2

Input: nums = [1,2,3], k = 3
Output: 2
*/

/*
Sliding window: O(N) for positive numbers only

Prefix Sum: O(N):
    
*/

#include<bits/stdc++.h>
using namespace std;

//--------------> Sliding window: for positive number only

// int subarraySum(vector<int> nums, int k){
//     int subarraySumCount = 0;
//     int left = 0, right = 0;
//     int sum = 0;

//     while(right < nums.size()){
//         sum += nums[right];

//         while(sum>k && left <= right){
//             sum -= nums[left];
//             left++;
//         }

//         if(sum == k) subarraySumCount++;

//         right++;
//     }

//     return subarraySumCount;
// }

// -----------------> Prefix: O(N)

int subarraySum(vector<int> nums, int k) {
    int prefixSum = 0;
    int subarrayCount = 0;

    unordered_map<int, int> mpp; // key: prefix sum, value: frequency
    mpp[0] = 1; // to handle subarrays starting from index 0

    for (int num : nums) {
        prefixSum += num;

        // Check if there's a previous prefixSum such that currentSum - previousSum = k
        if (mpp.find(prefixSum - k) != mpp.end()) {
            subarrayCount += mpp[prefixSum - k];
        }

        // Add/update current prefixSum frequency
        mpp[prefixSum]+=1;
    }

    return subarrayCount;
}

int main(){
    // vector<int> nums = {1, 2, 3}; // k=3, ans = 2
    // vector<int> nums = {1, 1, 1}; // k=2 ans = 2
    // vector<int> nums = {3,1,2,4}; // k=6 ans = 2
    vector<int> nums = {1, 0, 2, -3, 3, 4, -1, 2, 1}; // k=3 ans = 6
    cout << subarraySum(nums, 3) << endl;
}