/*
https://leetcode.com/problems/longest-consecutive-sequence/description/

given an array of integers nums, return the length of the longest consecutive elements sequence

Input: nums = [100,4,200,1,3,2]
Output: 4

*/

/*
    brute force: O(N long N)

    sort the array: O(N log N)
    last small = arr[i]
    linear search: O(N)
        if currEle - lastSmall == 1
            lastSmall = currEle
            count++;
        else if currEle != lastSmall
            lastSmall = currEle
            count=0;
        longest = max(longest, count)

    OPTIMAL -> O(N)
    1. store all the elements in a set --> O(N)
    2. iterate the array and check:
        if element is the starting point of the increasing sequence (means there is no nums[i])
*/

#include<bits/stdc++.h>
using namespace std;

// int longestConsecutive(vector<int> nums){
//     int n=nums.size();
//     int sequenceCount = 0;
//     int count = 0;
    
//     sort(nums.begin(), nums.end());
//     int lastSmall = nums[0];
//     for(int i=1; i<n; i++) {
//         if(nums[i] - 1 == lastSmall){
//             count += 1;
//             lastSmall = nums[i];
//         } else if(nums[i] != lastSmall){
//             count = 0;
//             lastSmall = nums[i];
//         }
//         sequenceCount = max(sequenceCount, count);
//     }
//     return sequenceCount+1;
// }

// --------------> optimal
int longestConsecutive(vector<int> nums){
    int n=nums.size();
    int maxSequenceCount = 0;
    unordered_set<int> stt;

    for(int i: nums){
        stt.insert(i);
    }

    for(auto it: stt) {
        if(stt.find(it-1) == stt.end()){
            int sequenceCount = 1;
            int j = it;
            while(stt.find(j+1) != stt.end()){
                sequenceCount++;
                j++;
            }
            maxSequenceCount = max(maxSequenceCount, sequenceCount);
        }
    }
    return maxSequenceCount;
}

int main(){
    // vector<int> nums = {0,3,7,2,5,8,4,6,0,1}; // 9
    vector<int> nums = {100,4,200,1,3,2,300}; // 4
    cout << longestConsecutive(nums) << endl;
}