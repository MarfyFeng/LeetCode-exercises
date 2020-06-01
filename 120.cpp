#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:

    int FindMinimum(vector<vector<int>>& triangle, int x, int y, vector<vector<int>>& sums){

        if(sums[x][y] == 0){
            if(x == triangle.size()-1)
                sums[x][y] = triangle[x][y];
            else
                sums[x][y] = triangle[x][y] + min(FindMinimum(triangle, x+1, y, sums), FindMinimum(triangle, x+1, y+1, sums));
        }
        cout<<"x,y : "<<x<<","<<y<<" sums:"<<sums[x][y]<<endl;
        return sums[x][y];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<vector<int>> sums(triangle.size(), vector<int>(triangle.size(), 0));

        return FindMinimum(triangle, 0, 0, sums);
    }
};

int main(){

    vector<vector<int>> triangle{{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    cout<<Solution().minimumTotal(triangle)<<endl;
    return 0;
}
