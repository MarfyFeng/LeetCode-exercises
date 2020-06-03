#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:

    vector<vector<int>> direction{
        {0,1},
        {1,0}
    };

    vector<vector<int>> memo;

    int FindPaths(int m, int n, int x, int y){
        
        if(x == m || y == n)
            return 1;

        if(memo[x][y] != -1)
            return memo[x][y];

        memo[x][y] = FindPaths(m, n, x+direction[0][0], y+direction[0][1]) + FindPaths(m, n, x+direction[1][0], y+direction[1][1]);
        
        return memo[x][y];
    }

public:
    int uniquePaths(int m, int n){

        memo = vector<vector<int>>(m, vector<int>(n, -1));

        return FindPaths(m, n, 0, 0);;
    }
};

int main(){

    cout<<Solution().uniquePaths(7,3)<<endl;
    return 0;
}
