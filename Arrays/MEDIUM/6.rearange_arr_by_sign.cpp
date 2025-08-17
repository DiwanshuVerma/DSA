
/*
    https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

    You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
    You should return the array of nums such that the the array follows the given conditions:

    1. Every consecutive pair of integers have opposite signs.
    2. For all integers with the same sign, the order in which they were present in nums is preserved.
    3. The rearranged array begins with a positive integer.

    Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

    Input: nums = [3,1,-2,-5,2,-4]
    Output: [3,-2,1,-5,2,-4]
*/

/*
    brute force: TC: O(n + n/2), SC: O(n/2 + n/2)
            ---------> O(n) and O(n)
    1. define two arrays:
        positive and negative
    2. loop through the original array
        if curr ele is greater than 0 store it into positive array
        else in negative array
    3. run a loop till n/2 (n = size of the original arr)
        arr[2*i] = posi[i]
        arr[2 * i+1] = posi[i]

    OPTIMAL: O(n), O(n)
    1. define two variables and a ans array
        positive = 0: for even indexing
        negative = 1 for odd indexing
    2. loop through the array
        if curr ele is less than 0 then store it in ans[pos] and inc pos by 2
        else store it in ans[neg] inc neg by 2
    
*/

#include<bits/stdc++.h>

using namespace std;

/* ----------------> O(n), O(n)
void rearrangeArray(vector<int> &nums){
    int n = nums.size();
    vector<int> posi;
    vector<int> negi;

    for(int i=0; i<n; i++){
        if(nums[i] > 0) posi.push_back(nums[i]);
        else negi.push_back(nums[i]);
    }

    for(int i=0; i<n/2; i++){
        nums[2*i] = posi[i];
        nums[2*i+1] = negi[i];
    }
}
*/

// ----------------> O(n), O(1)
vector<int> rearrangeArray(vector<int> nums){
    int n = nums.size();
    int pos = 0;  // even index for positive value 
    int neg = 1; // odd index for negative value
    vector<int> ans(n, 0); // ans array

    for(int i=0; i<n; i++) {
        if(nums[i] < 0) {      // store negative value in odd index and inc neg by 2
            ans[neg] = nums[i];
            neg += 2;
        } else {                // store positive value in even index and inc it by 2
            ans[pos] = nums[i];
            pos += 2;
        }
    }   
    return ans;
}

int main(){
    // vector<int> nums = {3,1,-2,-5,2,-4};   // 3,-2,1,-5,2,-4
    vector<int> nums = {-37,-10,-9,15,14,31};  // 15, -37, 14, -10, 31, -9
    // vector<int> nums = {-1,1};   // 1, -1
    vector<int> ans = rearrangeArray(nums);

    for(int i: ans){
        cout << i << " ";
    }
}