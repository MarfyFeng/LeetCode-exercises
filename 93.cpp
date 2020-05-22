#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
private:

    vector<string> res;
    int cnt;

    void findIpAddress(const string &s, int start, const string &tmp){
        
        // cout<<"start find..."<<endl;

        if(cnt == 4)
        {
            // cout<<tmp<<endl;
            int len = tmp.size();
            if(len == s.size()+3)
                res.push_back(tmp);
            return;
        }

        for(int i = 1; i <= 3; i++){
            // cout<<"loop..."<<endl;
            int num = 0;
            string pill = "";

            if(i > 1 && s[start] == '0')
                break;

            for(int j = 0; j < i ; j++)
            {
                pill.push_back(s[j + start]);
                num = num * 10 + s[j + start] - '0';
            } 
            // cout<<cnt<<' '<<pill<<' '<<num<<endl;

            if(num > 255) break;

            cnt++;
            if(cnt <= 3)
                findIpAddress(s, start+i, tmp + pill + '.');
            else
                findIpAddress(s, start+i, tmp + pill);
            cnt--;
        }
        return;
    }

public:
    vector<string> restoreIpAddresses(string s){
        res.clear();
        cnt = 0;
        if(s == "")
            return res;

        findIpAddress(s, 0, "");

        return res;
    }
};

int main(){

    vector<string> res = Solution().restoreIpAddresses("010010");
    for( int k = 0; k < res.size(); k++ )
        cout<<res[k]<<endl;

    return 0;
}
