#include <iostream>
#include <vector>
using namespace std;

// calculate the product of array except self, TC: O(n) SC: O(n)
// e.g. array = 1 2 3 4, answer = 24 12 8 6
// solved using both brute force and optimal approaches
// brute force: TC: O(n^2), SC: O(n)
// optimal: TC: O(n), SC: O(1)
// total three ways to solve this question:

// ----------------------> brute force <----------------------
// int main(){
//     int array[] = {1,2,3,4};
//     int n = 4;
//     int answer[n];
    
//     for(int i=0; i<n; i++){
//         int product = 1;
//         for(int j=0; j<n; j++){
//             if(j != i){
//                 product = product * array[j];
//             }
//         }
//         answer[i] = product;
//     }
//     for(int i=0; i<n; i++){
//         cout<<answer[i] << endl;
//     }
// }

// ------------------------> optimal, tc: O(n), sc: O(n) ------------
    // prefix, suffix will take extra space so space complexity is: O(n)
/*
int main() {
    int array[] = {1,2,3,4};
    int n = 4;
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    vector<int> answer(n, 1);

    //prefix
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] * array[i-1];
    }

    //suffix
    for(int i = n-2; i>=0; i--){
        suffix[i] = suffix[i+1] * array[i+1];
    }

    //answer
    for(int i = 0; i<n; i++){
        answer[i] = prefix[i]*suffix[i];
    }

    for(int i=0; i<n; i++){
        cout<<answer[i]<<endl;
    }
}
*/

// ------------------------> optimal, tc: O(n), sc: O(1) ------------
// instead of defining two extra arrays to calcute prefix, suffix to calculate answer:
// prefix: directly calculate previous element and add into answer array
// suffix: define a variable that works exactly lilke suffix array

int main(){
    vector<int> array = {-1,1,0,-3,3};
    int n = array.size();
    vector<int> answer(n, 1);
    int suffix = 1;

    // prefix
    for(int i=1; i<n; i++){
        answer[i] = answer[i-1] * array[i-1];
    }
    
    //suffx
    for(int i=n-2; i>=0; i--){
        suffix *= array[i+1];
        answer[i] *= suffix;
    }
    
    for(int i=0; i<n; i++){
        cout<<answer[i]<<endl;
    }
}