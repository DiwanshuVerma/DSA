#include<iostream>
#include<unordered_map>
#include<vector>

/*
https://leetcode.com/problems/number-of-good-pairs/description/

    OPTIMAL: tc: O(N), SC: O(k);

    count how many times each number appears, if a number appears n times then n*n(n-1)/2 good pairs can be made with this number
    
    'hashmap i will use hashmap'
*/

using namespace std;

int goodPairs(vector<int> arr){
   unordered_map<int, int> freq;
    int goodPairsCount = 0;

    for (int num : arr) {
        // Every time we see this num, all previous same nums form a new pair
        goodPairsCount += freq[num];
        freq[num]++; // update frequency
    }

    return goodPairsCount;
}

int main(){
    // vector<int> arr = {1,2,3,1,1,3}; // 4
    vector<int> arr = {1,1,1,1}; // 6
    cout << goodPairs(arr) << endl;
}