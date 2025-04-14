#include <iostream>
#include <vector>
using namespace std;

/*
    if mid == target -> return mid
    if arr[start] <= arr[mid]          // CHECK IF LEFT SORTED
       if arr[start] <= target <= arr[mid] -> end = mid-1
       else -> start = mid+1
    
    else                               // ELSE RIGHT SORTED
      if arr[mid] <= target <= arr[end] -> start = mid+1
       else -> end = mid-1 
*/

int rotatedSortedArray(vector<int> arr, int target){
    int start = 0, end = arr.size()-1;

    while(start <= end){
        int mid = start+(end-start)/2;
 
        if(arr[mid] == target) return mid;
        
        if(arr[start] <= arr[mid]){  // check left sorted array
            if(target >= arr[start] && target <= arr[mid]) end = mid - 1;
            else start = mid + 1;
        } else {                    // right sorted array part
            if(target >= arr[mid] && target <= arr[end]) start = mid + 1;
            else end = mid - 1;
        }
    }
    return -1;
}


int main(){
    vector<int> arr = {4,5,6,0,1,2,3};
    int ans = rotatedSortedArray(arr, 2);

    cout<<"target at: " << ans << endl;
}