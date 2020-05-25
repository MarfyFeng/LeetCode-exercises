#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:

    vector<vector<int>> res;
    vector<bool> status;

    void FindSubNums(vector<int>& nums, vector<int>& subnums){
        
        if(subnums.size() == nums.size()){
            res.push_back(subnums);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(status[i]){
                continue;
            }
            if(i > 0 && nums[i - 1] == nums[i] && !status[i - 1]){
                continue;
            }
            subnums.push_back(nums[i]);
            status[i] = true;
            FindSubNums(nums, subnums);
            subnums.pop_back();
            status[i] = false;
        }

        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        res.clear();
        if(nums.size() == 0)
            return res;

        status = vector<bool>(nums.size(), false);

        vector<int> subnums;
        subnums.clear();
        sort(nums.begin(), nums.end());
        FindSubNums(nums, subnums);

        return res;
    }
};

int main(){

    vector<int> nums{3,3,0,3};
    vector<vector<int>> res = Solution().permuteUnique(nums);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout<<res[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}