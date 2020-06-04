#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int uniquePaths(int m, int n){

        vector<vector<int>> direction{
            {0,1},
            {1,0}
        };

        vector<vector<int>> memo(m, vector<int>(n, -1));

        for(int i = m-1; i >= 0; i--)
            memo[i][n-1] = 1;

        for(int j = n-1; j >= 0; j--)
            memo[m-1][j] = 1;

        for(int i = m-2; i >= 0; i--)
            for(int j = n-2; j >= 0; j--)
                if(memo[i][j] == -1)
                    memo[i][j] = memo[i+direction[0][0]][j+direction[0][1]] + memo[i+direction[1][0]][j+direction[1][1]];
              
        return memo[0][0];
    }
};

int main(){

    cout<<Solution().uniquePaths(7,3)<<endl;
    return 0;
}
