#include <bits/stdc++.h>
using namespace std;

/*
 coding ninjas (only non-negative numbers): https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?leftPanelTabValue=SUBMISSION&count=25&page=2&search=longest%20sub&sort_entity=order&sort_order=ASC
 coding ninjas (for all integers): https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505?count=25&search=longest%20subarray%20&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM&customSource=studio_nav
 GFG (for all integers): https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
 Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
*/

/*
    --------->brute force: O(N^2)
    
    1. initialize a variable to store maximum length of the arr:
        longestSubArrCount = 0;
    2. loop through the array: i=0 -> n-1
        i. initialize two variables: 
            currSum = 0 : for inner loop to add every item 
            currCout = 0 : increase it by one until currSum >= current element
        ii. run a loop: j=i -> n-1
            if currSum >= current element break the loop
            else keep adding every new ele to currSum and increase currCount by one
        iii. if currSum == k then asign max value in longestSubArrCount of currCount
    

    --------------->two pointer: N+N ->  2N => O(N) -----> works only for non-negative numbers
    
    1. initialize:
        pointers: left = 0, right = 0 
        maxLength = 0
        sum = arr[0]
    2. run a while loop untill right < n
        i. run a while until sum > k && right >= left
            keep moving the left pointer to right and subtract sum with left most element
            until sum is greater than given k
        ii. get max length from left -> right
            right - left + 1
        iii. keep moving the right pointer and add current element in sum variable
    3. return maxLength

    ------> YES there are two while loops one inside other but time complexity is linear/N
    outer loop: 0 -> n => N
    inner: it only runs until the sum is greater than K, so suppose it runs N times, but this wont multiply it just add

    O(N+N) => O(N)


    ----------------------> prefix sum+hashmap: O(N) --> works for any integers(positivem negative, or mixed)

    1. Initialize:

        sum = 0 (running prefix sum)
        maxLen = 0 (answer)
        mp (hashmap: prefix sum → first index where it occurred)

    2. Loop through the array:

        Add current element to sum.
        Case 1: If sum == k, then the subarray from 0 to i works — update maxLen.
        Case 2: If (sum - k) is in the map, then the subarray between mp[sum - k] + 1 and i works — update maxLen with length i - mp[sum - k].
        Case 3: If sum not in map, store sum → i (we store only the first occurrence to maximize length).

    3. Return maxLen.

*/

// ----------------> brute force: O(N^2)

// int longestSubarrayWithSumK(vector<int> arr, int n, int k){
//     int longestSubArrCount = 0;

//     for(int i=0; i<n; i++){
//         int currSum = 0;
//         int currCount = 0;

//         for(int j=i; j<n; j++){
//             if(currSum >= k) break;

//             currSum += arr[j];
//             currCount++;
//         }

//         if(currSum == k) longestSubArrCount = max(longestSubArrCount, currCount);
//     }
//     return longestSubArrCount;
// }

// ------------------>  two pointer approach: O(N)

/*
int longestSubarrayWithSumK(vector<int> arr, int n, int k){
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int maxLen = 0;

    while(right < n){

        // keep moving the left pointer to right and subtract sum with left most element until sum is greater than given k
        while(right >= left && sum > k){
            sum -= arr[left];
            left++;
        }

        // get max length from left -> right
        if(sum == k) maxLen = max(maxLen, right-left+1);

        // keep moving the right pointer and add current element in sum variable
        right++;
        if(right < n) sum += arr[right];
    }

    return maxLen;
}
*/

// ---------------> prefix sum + hashmap: O(N)

int longestSubarrayWithSumK(vector<int> arr, int n, int k) {
    unordered_map<int, int> prefixIndex; // {prefixSum -> first index}
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: subarray from start
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // Case 2: subarray from middle
        if (prefixIndex.find(sum - k) != prefixIndex.end()) {
            int len = i - prefixIndex[sum - k];
            maxLen = max(maxLen, len);
        }

        // Case 3: store first occurrence
        if (prefixIndex.find(sum) == prefixIndex.end()) {
            prefixIndex[sum] = i;
        }
    }

    return maxLen;
}


int main(){
    // vector<int> arr = {1,2,3,1,1,1,1,3,3}; // k=6 // ans: 4
    // vector<int> arr ={4, -2, 2, -1}; // k=10 // ans: 7

    vector<int> arr = {2, 3, 5, -1, 1, 1, 2, -1, 3, 9}; // k:10, ans: 7

    int n = arr.size();
    
    cout << longestSubarrayWithSumK(arr, n, 10) << endl;
}
