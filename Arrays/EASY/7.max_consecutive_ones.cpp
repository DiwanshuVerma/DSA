/*
    https://leetcode.com/problems/max-consecutive-ones/description/
    Given a binary array nums, return the maximum number of consecutive 1's in the array.

    Input: nums = [1,1,0,1,1,1]
    Output: 3
*/

/*
    1.initialize two variables:
        maxCons = 0;
        currCons = 0;
    2. loop through the array
        if(currElement == 1) currCons++;
        else {
            maxCons = max(currCons, maxCons);
            currCons = 0;
        }
    3. maxCons = max(currCons, maxCons);
    4. return maxCons;
*/

#include<bits/stdc++.h>
using namespace std;

int maxOnes (vector<int> nums, int n){
    int maxCons = 0;
    int currCons = 0;

    for(int i=0; i<n; i++){
        if(nums[i] == 1) currCons++;
        else {
            maxCons = max(currCons, maxCons);
            currCons = 0;
        }
    }
    maxCons = max(currCons, maxCons);
    return maxCons;
} 

int main(){
    vector<int> arr = {1, 1, 0, 1, 1, 1, 0};
    int n = arr.size();

    cout<< maxOnes(arr, n) << endl;
}