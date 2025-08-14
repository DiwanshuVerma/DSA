/*
    https://leetcode.com/problems/next-permutation/description/

    A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

    For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
    The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

    For example, the next permutation of arr = [1,2,3] is [1,3,2].
    Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
    While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
    Given an array of integers nums, find the next permutation of nums.
*/

/*
    BRUTE force: O(N! + N)
        1. generate all the permutations
        2. linear search the permutations if given array matches the current permutation return next permutation (if there is no next per. then return 1st per.)

    BETTER: O(N)
        STL inbuilt function:
        next_permutation(arr.begin(), arr.end())

    OPTIMAL: O(N)
        behind the scene architecture of that inbuilt function
    
        three observations:
         1. find the longest prefix: arr[i] < arr[i+1]
            [2,1,5,4,3,0] -> [1 5] (so i is the idx here)
            here 5 is the peak element, so 1 will be replaced by an element from remaining array: [5 4 3 0]
        2. in remaining array find the ele greater than idx but smallest in the remaining array (which is 3 here)
            so: [2,3,5,4,1,0]
        3. sort the array after prefix (idx)
            : [2,3,0,1,4,5]

        edge case: if there is no prefix found then reverse the array

*/

#include <bits/stdc++.h>
using namespace std;

/* -------------> built in STL function
void nextPermutation(vector<int> &arr){
    next_permutation(arr.begin(), arr.end());
}
*/

void nextPermutation(vector<int> &arr){
    int n = arr.size();
    int idx=-1;

    // find the right most peak element
    for(int i=n-2; i>=0; i--){
        if(arr[i] < arr[i+1]){
            idx = i;
            break;
        }
    }

    // edge case: if array is in decreasing order then just reverse the array, it is the next permutation
    if(idx == -1){
        reverse(arr.begin(), arr.end());
        return;
    }

    // find the element greater than prefix but smallest in the remaining part of array
    for(int i=n-1; i>idx; i--){
        if(arr[i] > arr[idx]){
            swap(arr[idx], arr[i]);
            break;
        }
    }

    // sort the array after prefix
    sort(arr.begin()+idx+1, arr.end());

}

int main(){
    // vector<int> arr = {4,3,3};  // 3 3 4
    // vector<int> arr = {1,2,3};  // 1 3 2
    // vector<int> arr = {3,2,1};  // 1 2 3
    // vector<int> arr = {3,1,2};  // 3 2 1
    // vector<int> arr = {2,3,1};  // 3 1 2
    // vector<int> arr = {2,3,2,1};  // 3 2 2 1 -> 3 1 2 2
    vector<int> arr = {2,1,5,4,3,0,0};  // 2,3,0,0,1,4,5
    // vector<int> arr = {3,2,1};  // 1,2,3

    nextPermutation(arr);
    for(int i: arr) cout << i << " ";
}