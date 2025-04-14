#include <iostream>
#include <vector>
using namespace std;

int PeakIndex(vector<int> arr){
    int srt = 1, end = arr.size()-2; // skip 1st and last values bcz there always will be a peak ele so 1st and last values never be peak value

    while(srt <= end){
        int mid = srt + (end - srt)/ 2;

        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;

        if(arr[srt] > arr[mid] || arr[mid] <= arr[mid-1]) end = mid - 1;
        else srt = mid + 1;
    }

    return -1;
}

int main(){
    vector<int> arr = {3,5,3,2,0};
    int ans = PeakIndex(arr);

    cout << "peak index: "<< ans << endl;
}