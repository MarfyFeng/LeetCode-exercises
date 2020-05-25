#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;

    void FindSubNums(vector<int>& nums, int index, vector<int>& subnums){
        
        

    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        if(nums == (vector<int>)NULL)
            return res;
        
        vector<int> subnums;
        subnums.clear();
        FindSubNums(nums, 0, subnums);

        return res;
    }
};

int main(){

    return 0;
}