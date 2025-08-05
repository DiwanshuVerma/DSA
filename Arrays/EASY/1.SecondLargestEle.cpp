#include <iostream>
using namespace std;

// GFG: https://www.geeksforgeeks.org/problems/second-largest3735/1
/*
    1. initialize two variables:
        largest = arr[0]
        secLargest = -1
    2. loop through the array from 1 to n-1
    3. if current ele is greater than largest then: 
        secLargest = largest;
        largest = arr[i]
        else if curr ele is less than largest && greater than secLargest
        secLargest = arr[i]
    4. return secLargest
*/


int main() {
    int arr[5] = {22, 4, 21, 6, 0};
    int largest=arr[0];
    int secondLargest=0;

    for(int i=1; i<5; i++){
        if(largest < arr[i]){
            secondLargest = largest;
            largest = arr[i];
        } else if(secondLargest<arr[i] && arr[i] < largest) secondLargest = arr[i];
    }
    cout << "second largest element: " << secondLargest<<endl;
}
