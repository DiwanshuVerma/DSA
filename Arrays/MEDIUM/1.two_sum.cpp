/*
    LC: https://leetcode.com/problems/two-sum/description/

    Given an array of integers nums and an integer target, 
    return indices of the two numbers such that they add up to target.

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
*/

/*
    brute force: O(N^2)

        outer loop: i=0 -> n-2
        inner loop: j=i -> n-1
        if arr[i] + arr[j] == target, return i and j

    optimal: O(N)

        1. initialize a map data structure
        2. loop through the array: 0 -> n-1
            subtract current element with target and check if that exists in the map: target-arr[i]
            if exists return return i and the index of the element found in map
            
            if not exists: store current element(arr[i]) in the hashMap along with its index
        3. return {-1,-1}
*/



#include <bits/stdc++.h>
using namespace std;

vector<int> TwoSum(vector<int> arr, int target){
    int n=arr.size();
    vector<int> ans;
    unordered_map<int, int> mpp;
    
    for(int i=0; i<n; i++){
        int currSub = target-arr[i];

        if(mpp.find(currSub) != mpp.end()) return {mpp[currSub], i};
        mpp[arr[i]] = i;
    }
    return {-1,-1};
}

int main(){
    vector<int> arr = {2, 7, 10, 12, 9};
    // vector<int> arr = {3, 2, 4};
    
    vector<int> ans = TwoSum(arr, 11);
    for(int i: ans) cout << i << " ";
}