/*
    https://leetcode.com/problems/missing-number/description/

    Given an array nums containing n distinct numbers in the range [0, n], 
    return the only number in the range that is missing from the array.
*/

/*
    1. initialize two variables:
        expectedSum = ((n+1) * n) / 2
        givenSum = 0;
    2. loop through the array 0->n-1
        add each element in givenSum
    3. return expectedSum - givenSum
*/

#include<bits/stdc++.h>
using namespace std;

int missing(vector<int> &nums, int n){
    int expectedSum = ((n+1) * n)/2;
    int givenSum=0;
    
    for(int i=0; i<n; i++) {
        givenSum += nums[i];
    }
    return expectedSum-givenSum;
}

int main(){
    vector<int> nums = {3, 0, 1};

    int n = nums.size();

    cout << missing(nums, n) << endl;
}