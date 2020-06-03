#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:

    vector<vector<int>> direction{
        {0,1},
        {1,0}
    };

    int res;
    vector<vector<bool>> status;

    void FindPaths(int m, int n, int x, int y){

        if(x == m-1 && y == n-1){
            cout<<"get"<<endl;
            res++;
            return;
        }

        if(status[x][y] != false)
            return;

        status[x][y] = true;
        for(int i = 0; i < 2; i++){
            // cout<<direction[i][0]<<' '<<direction[i][1]<<endl;
            FindPaths(m, n, x+direction[i][0], y+direction[i][1]);
        }
        status[x][y] = false;
        return;
    }

public:
    int uniquePaths(int m, int n){

        res = 0;
        status = vector<vector<bool>>(m, vector<bool>(n, false));

        FindPaths(m, n, 0, 0);

        return res;
    }
};

int main(){

    cout<<Solution().uniquePaths(3,2)<<endl;
    return 0;
}
