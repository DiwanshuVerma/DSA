#include<bits/stdc++.h>
using namespace std;

    // https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
    // -------------> USING SET: TC: O(N log N), SC: O(N)

    // set<int> temp;
    // for(int i=0; i<size; i++) temp.insert(arr[i]);
    
    // int k=temp.size();
    // int j=0;
    // for(int x: temp) arr[j++] = x;
    // return k;

    //----------------> optimal O(N), O(1)
    // Take a variable i as 0;
    // Use a for loop by using a variable ‘j’ from 1 to length of the array.
    // If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
    // After completion of the loop return i+1, i.e size of the array of unique elements.

int removeDublicates(vector<int> &arr){
    int size = arr.size();

    int i=0;
    for(int j=1; j<size; j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

 int main(){
    vector<int> arr = {1, 1, 1, 2, 4, 4, 4,};
    int k = removeDublicates(arr);
    for(int i=0; i<k; i++) cout << arr[i] << " ";
 }
