#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:

    vector<vector<int>> res;

    void FindCombine(int n, int k, int start, vector<int>& c){

        if(c.size() == k){
            res.push_back(c);
            return;
        }

        for(int i = start; i <= n-k+c.size()+1; i++){
            c.push_back(i);
            FindCombine(n, k, i + 1, c);
            c.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> combine(int n, int k) {
        
        res.clear();
        if(n <= 0 || k <= 0 || k > n)
            return res;

        vector<int> c;
        FindCombine(n, k, 1, c);

        return res;
    }
};

int main(){

    vector<vector<int>> res = Solution().combine(4, 2);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout<<res[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}