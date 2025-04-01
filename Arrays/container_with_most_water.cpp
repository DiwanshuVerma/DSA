#include <iostream>
using namespace std;

//---------------------------> brute force

// int main(){
//     int values[] = {2, 8, 4, 9, 3, 7, 12};
//     int n = 7;
//     int ans = 0;
//     for(int i = 0; i<n-1; i++){
        
//         int startCon = values[i];

//         for(int j=i+1; j<n; j++){
//             int width = j-i; // 1, 2, 3, 4, 5, 6, 
//             int endCon = values[j];

//             int minCon = min(startCon, endCon);

//             ans = max(ans, minCon*width);
//             cout << "water: " << ans << endl;
//         }

//     }
//     cout << "max water: "<< ans << endl; 
// }


//---------------------------------------> optimized

int main() {
    int values[] = {2, 8, 4, 9, 3, 7, 12};
    int n = 7;
    int ans = 0;

    int s = 0;
    int l = n-1;

    while(s<l){
        int width = l-s;
        int minCon = min(values[s], values[l]);
        ans = max(ans, minCon*width);

        if(values[s] < values[l]){
            s++;
        } else {
            l--;
        }
    }

    cout<<"most water: "<<ans << endl;

}