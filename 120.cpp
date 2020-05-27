#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:

    int res;
    vector<vector<int>> sums;

    int FindMinimum(vector<vector<int>>& triangle, int x, int y){

        if(x == triangle.size()-1){
            memcpy(&sums[x][0], &triangle[x][0], triangle[x].size());
            return sums[x][y];
        }

        if(FindMinimum(triangle, x+1, y) < FindMinimum(triangle, x+1, y+1))
            sums[x][y] = triangle[x][y] + FindMinimum(triangle, x+1, y+i);
 
        return sums[x][y];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        res = 0;
        for(int i = 0; i < triangle.size(); i++)
            res += triangle[i][0];
        
        sums.clear();

        FindMinimum(triangle, 0, 0);

        return res;
    }
};

int main(){

    vector<vector<int>> triangle{{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    cout<<Solution().minimumTotal(triangle)<<endl;
    return 0;
}