#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:

    int res;

    void FindMinimum(vector<vector<int>>& triangle, int x, int y, int& sum){

        if(x == triangle.size()){
            cout<<"res = "<<res<<" sum = "<<sum<<endl;
            if(sum < res)
                res = sum;
            return;
        }

        cout<<"res = "<<res<<" sum = "<<sum<<" triangle[ "<<x<<", "<<y<<" ] : "<<triangle[x][y]<<endl;
        for(int i = 0; i < 2; i++){
            sum += triangle[x][y];
            FindMinimum(triangle, x+1, y+i, sum);
            sum -= triangle[x][y];
        }

        return;
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        res = 0;
        for(int i = 0; i < triangle.size(); i++)
            res += triangle[i][0];
        
        int sum = 0;

        FindMinimum(triangle, 0, 0, sum);

        return res;
    }
};

int main(){

    vector<vector<int>> triangle{{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    cout<<Solution().minimumTotal(triangle)<<endl;
    return 0;
}