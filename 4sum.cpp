// given arr= [-2, -1, -1, 1, 1, 2, 2]  | tar=0
// To Find: groups of 4 nums s.t their sum = target
//          [ nums[i] + nums[j] + nums[k] + nums[l] = tar  && i != j != k != l]

// solution: 2 pointer approach

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int tar){
    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        for(int j=i+1; j<n; ){
            int k=j+1, l=n-1;
            while(k<l){
                long long sum = (long long)nums[i] + (long long)nums[j] +(long long)nums[k] +(long long)nums[l];
                if(sum<tar){
                    k++;
                }
                else if(sum>tar){
                    l--;
                }
                else{ //sum = tar
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++; l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                }
            }
            j++;
            while(j<n && nums[j] == nums[j-1]) j++;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {-2, -1, -1, 1, 1, 2, 2};
    int tar = 0;

    vector<vector<int>> result = fourSum(nums, tar);
    cout << "Required Four Sum answers:\n";

    for (const auto& quad : result) {
        cout << "[ ";
        for (int num : quad) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}

// Time Complexity: O(nlogn + n^3)
// Space Complexity: O(uniqueGroups)