
// https://leetcode.com/problems/majority-element-ii/
//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
/*
    Input: nums = [3,2,3,2,1]
    Output: [3,2]

*/

/*
    BRUTE FORCE: O(N^2)
    1. initialize a set which will store the counted ith elements

    2. outer loop: pick the ith element
        if ith element is not counted already then run inner loop: 
            a. inner loop: jth element is equal to ith element keep increasing the count
            b. if the count is greater than n/3 store ith element in above initailize set

    GOOD: O(N)

    1. initialize a set
    2. loop through the array, store elements in a set, it will store the: element and its frequency
    3. loop through the set, if a element's freq is less-equal to n/3 drop it
    4. return the set 

    OPTIMAL: O(N) --> Entended Boyer-Moore Voting algorithm

    *There can be at most 2 elements that occure more that n/3 times
    1. initialize two candidated(cand1, cand2), and their counts (cnt1, cnt2)
    2. loop through the array:
        if(cnt1 == 0) cand1 = arr[i];
        else if(cnt2 == 0) cand2 = arr[i];

        if(cand1 == arr[i]) cnt1++;
        else if(cand2 == arr[i]) cnt2++;
     
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> MEs(vector<int> arr){
    int n=arr.size();
    //  ------> brute FORCE
    // set<int> st;
    // for(int i=0; i<n; i++){
    //     int cnt = 0;
    //     if(st.find(arr[i]) == st.end()) { // ith element not found in the set
    //         for(int j=i; j<n; j++){
    //             if(arr[i] == arr[j]) cnt += 1;
    //         }
    //         if(cnt>n/3) st.insert(arr[i]);
    //     }
    // }

    // -------------> GOOD
    // map<int, int> mp;

//         for(int i=0; i<n; i++) {
//             mp[arr[i]]++;
//         }
        
//     for (auto it = mp.begin(); it != mp.end(); ) {
//         if (it->second <= n/3) {
//             it = mp.erase(it);  // safe erase
//         } else {
//             ++it;
//         }
//     }

// return mp;



// -------------------> moore's
vector<int> ans;
int cand1=0, cand2=0;
int cnt1=0, cnt2=0;

for(int i: arr) {
    if(i == cand1) cnt1++;
    else if(i == cand2) cnt2++;
    else if(cnt1 == 0) {cand1 = i; cnt1=1;}
    else if(cnt2 == 0) {cand2 = i; cnt2=1;}
    else {cnt1--; cnt2--;}
}

// varify candidates
cnt1 = cnt2 = 0;
for(int i: arr) {
    if(i == cand1) cnt1++;
    else if(i == cand2) cnt2++;
}

if(cnt1 > n/3) ans.push_back(cand1);
if(cnt2 > n/3) ans.push_back(cand2);


return ans;
}

int main() {
    // vector<int> arr={11,33,33,11,33,11,1,1};
    // vector<int> arr={1};
    vector<int> arr={3,2,3};
    vector<int> ans = MEs(arr);
    for(int i: ans) cout << i << " ";
}