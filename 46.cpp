#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<bool> status;

    void FindSubNums(vector<int>& nums, vector<int>& subnums){
        
        if(subnums.size() == nums.size()){
            cout<<"get one."<<endl;
            res.push_back(subnums);
            for(int i = 0; i < subnums.size(); i++)
                cout<<subnums[i]<<' ';
            cout<<endl;
            return;
        }

        for(int i = 0; i < nums.size(); i++){

            if(status[i] == true){
                cout<<"F index: "<<i<<" num: "<<nums[i]<<endl;
                continue;
            }
            cout<<"T index: "<<i<<" num: "<<nums[i]<<endl;
            subnums.push_back(nums[i]);
            status[i] = true;
            FindSubNums(nums,subnums);
            subnums.pop_back();
            status[i] = false;
        }

        return;

    }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        res.clear();
        if(nums.size() == 0)
            return res;

        status = vector<bool>(nums.size(), false);

        vector<int> subnums;
        subnums.clear();
        FindSubNums(nums, subnums);

        return res;
    }
};

int main(){

    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = Solution().permute(nums);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout<<res[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}