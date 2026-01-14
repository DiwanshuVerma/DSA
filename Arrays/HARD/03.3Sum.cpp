
/*
    https://leetcode.com/problems/3sum/description/

    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
*/

/*  
    Three nested loops: O(N^3)

    OPTIMAL O(N^2) : two pointer
        1. sort the array
        2. outer loop: i=0 -> n-1
        3. j=i+1, k=n-1
        4. while (j<k) keep addding all three three elements
        5. if sum > 0: k--
                sum<0: j++
        else store the triplets
*/

#include <bits/stdc++.h>

using namespace std;
/*  BRUTE
int main()
{
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    // vector<int> nums = {0,1,1,-1};
    vector<int> nums = {0,0,0};
    int n = nums.size();

    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++){
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]}; // define a temp vector array to sort the array then store in a set
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

*/   BETTER

// int main()
// {
//     // vector<int> nums = {0,1,1,-1};
//     // vector<int> nums = {0, 0, 0};
//     vector<int> nums = {-1, 0, 1, 2, -1, -4};

//     int n = nums.size();
//     set<vector<int>> stt;
//     for (int i = 0; i < n; i++)
//     {
//         unordered_map<int, int> mpp; // reset for each i
//         for (int j = i + 1; j < n; j++)
//         {
//             int x = -(nums[i] + nums[j]); // calculate the remaining element that will make it 0
//             if (mpp.find(x) != mpp.end())
//             {
//                 vector<int> temp = {nums[i], nums[j], x}; // if that remaining element exists in the map then store all these elements in a vector
//                 sort(temp.begin(), temp.end());           // store in a set in increasing order so that next same array don't store
//                 stt.insert(temp);
//             }
//             else
//             {
//                 //     // store value -> index
//                 mpp[nums[j]] = j; // -1
//             }
//         }
//     }

//     // store the set in an array for easy write and return
//     vector<vector<int>> ans(stt.begin(), stt.end());

//     for (int i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < ans[i].size(); j++)
//         {
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// OPTIMAL

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    if(n<3) return res;  // no triplet can be made, return empty vector

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        if (nums[i] > 0) break;  // can't sum to 0 if smallest > 0
        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) j++;
            else if (sum > 0) k--;
            else
            {
                ans.insert({nums[i] + nums[j] + nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    // return ans;

    // print all triplets
    for (auto &triplet : ans)
    {
        for (int var : triplet)
        {
            cout << var << " ";
        }
        cout << endl;
    }
}