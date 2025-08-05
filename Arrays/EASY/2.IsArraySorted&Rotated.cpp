#include <iostream>
using namespace std;
// check if array is sorted and rotated
// lc: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

/*
    1. declare a variable count = 0
    2. loop through the array: 0 -> n-1
        compare: arr[i] > arr[i+1 % n]
        increase count if its true, if it true means there is a drop 
    3. return false if count > 1, otherwise true
    
    count = 0: array is already sorted there is no drop
    cout = 1: there is just one drop and the drop's last ele is smaller than arr[0]

    this method called: count drop points
*/

int main(){
    int arr[] = {3, 5, 5, 6, 7};
    int n = size(arr);
    int count = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] > arr[(i+1) % n]) count++;
    }

   if(count > 1) return false;
    return true;
    
}
