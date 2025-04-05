#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
    Given an array nums of size n, return the majority element.
    The majority element is the element that appears more than n / 2 times.
    You may assume that the majority element always exists in the array.
*/

/*
    there are two main ways to solve this question: 
    1. Sorting
    2. Moore's algorithm (more optimal)
    
    1. in sorting method we first sort the array then iterate from 1 to n-1 and if currect item is equal to previous then increase frequency by one if not then reset freq to 1
    2. Moore's algorithm: array element that is >n/2 is always have plus frequency even if we decrease all the other elements from it
*/

// -------------------> sorting <-------------------------------
/*
int majorityElement(vector<int>& nums ){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int freq = 1;

    for(int i=1; i<n; i++){
        if(nums[i] == nums[i-1]) freq++;
        else freq = 1;

        if(freq > n/2) return nums[i];
    }

    return nums[0];
}
*/

// -----------------------> Moore's algorithm <---------------
int majorityElement(vector<int>& nums ){
    int n = nums.size();
    int freq = 0;
    int ans = 0;

    for(int i=0; i<n; i++){
        if(freq == 0) ans = nums[i];
        
        if(ans == nums[i]) freq++;
        else freq--;
    }

    return ans;
}


int main(){
    vector<int> nums = {2,2,2,1,1,1,2,2};
    int ans = majorityElement(nums);

    cout<< "answer is: "<<ans<<endl;
}