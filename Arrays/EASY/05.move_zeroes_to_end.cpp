#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/move-zeroes/description/

/*
    optimal: tc: O(n) sc: O(1)

    1. take a variable i = 0;
    2. loop through the array j=0 -> n-1
        store current ele in arr[i] if the element is not equal to 0
        and increase i++
    3. run another loop from i to n-1
        store 0 in arr[i]
*/

int main(){
    vector<int> nums= {0 , 2, 1, 0 , 0, 5, 0};
    int n = nums.size();
    int i = 0;

    for(int j=0; j<n; j++){
        if(nums[j] !=  0){
            nums[i] = nums[j];
            i++;
        }
    }
    for(int j=i; j<n; j++) nums[j] = 0;
}
