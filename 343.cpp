#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        
        assert(n >= 2);
        vector<int> memo(n+1, -1);

        for(int i = 1; i <= n; i++)
            if(memo[i] == -1)
                if(i == 1)
                    memo[i] = 1;
                else
                    for(int j = 1; j <= i-1; j++)
                        memo[i] = max(memo[i], max(j*(i-j), j*memo[i-j]));

        return memo[n];
    }
};

int main(){

    cout<<Solution().integerBreak(10)<<endl;
    return 0;
}