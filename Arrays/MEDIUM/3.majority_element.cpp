#include<bits/stdc++.h>
using namespace std;

/*
    https://leetcode.com/problems/majority-element/description/

    Given an array nums of size n, return the majority element.
    The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.*/

/*
    SOLUTION:

    ----> brute force: O(N^2)
    ----> use hashmap: 
            insert in the map: O(log n)
            loop through the map to get the majority element: O(N)
             => O(N*log n), O(N space)

    ----> better: O(N)
        sort the array then run a loop to get majority element
        both operations take: O(N*log N + N) => O(N log N), O(1) space

    ----> optimal: O(N)
            Moore's voting algorithm

        Moore's algorithm: array element that is >n/2 is always have plus frequency even if we decrease all the other elements from it

        take two variables:
        count=0
        Element=0
        
        loop through the array
            if count is 0 then store current element in Element var
            if curr ele is equal to Element then increase the count 
            else decrease the count value by one

*/

/* ------------------> brute force
int majorityElement(vector<int> arr){
    int N = arr.size();

    for(int i=0; i<N; i++){
        int count = 0;

        for(int j=0; j<N; j++){
            if(arr[i] == arr[j]) count++;
        }
        if(count > (N/2)){
            return arr[i];
        }
    }

    return -1;
}
    */

    /*  -----------------> map data structure
    
int majorityElement(vector<int> arr){
    int N = arr.size();
    map<int, int> mp;
    
    // storing the elements with its occurence
    for(int i=0; i<N; i++) {
        mp[arr[i]]++;
    }

    // search for the majority element
    for(auto it: mp){
        if(it.second > (N/2)) return it.first;
    }

    return -1;
}
*/

/* --------------> Moore's voting algorithm */

int majorityElement(vector<int> arr){
    int N = arr.size();

    int count = 0, candidate = 0;

    // Find candidate
    for(int i = 0; i < N; i++) {
        if(count == 0) candidate = arr[i];
        if(arr[i] == candidate) count++;
        else count--;
    }

    // Verify candidate
    int freq = 0;
    for(int num : arr) {
        if(num == candidate) freq++;
    }

    if(freq > N/2) return candidate;
    return -1; // No majority element
}

int main(){
    vector<int> arr = {4, 3, 4, 3, 4};
    cout << majorityElement(arr) << endl;
} 