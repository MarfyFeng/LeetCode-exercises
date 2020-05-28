#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:

    int FindMinimum(vector<vector<int>>& triangle, int x, int y, vector<vector<int>>& sums){

        int left = FindMinimum(triangle, x+1, y, sums);
        int right = FindMinimum(triangle, x+1, y+1, sums);
        sums[x][y] = triangle[x][y] + (left < right ? left : right);

        return sums[x][y];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<vector<int>> sums;

        FindMinimum(triangle, 0, 0, sums);
        
    }
};

int main(){

    vector<vector<int>> triangle{{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    cout<<Solution().minimumTotal(triangle)<<endl;
    return 0;
}