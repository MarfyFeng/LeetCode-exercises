#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        vector<vector<int>> sums(triangle.size(), vector<int>(triangle.size(), 0));
        
        for(int i = triangle.size()-1; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                if(sums[i][j] == 0){
                    if(i == triangle.size()-1)
                        sums[i][j] = triangle[i][j];
                    else
                        sums[i][j] = triangle[i][j] + min(sums[i+1][j], sums[i+1][j+1]);
                }
                cout<<"x,y : "<<i<<","<<j<<" sums:"<<sums[i][j]<<endl;
            }
        }

        return sums[0][0];
    }
};

int main(){

    vector<vector<int>> triangle{{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    cout<<Solution().minimumTotal(triangle)<<endl;
    return 0;
}
