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
        
        cout<<"start find..."<<endl;

        // int len = tmp.size();

        // if(len = s.size()+3){
        //     cout<<"get one addr: "<<endl;
        //     res.push_back(tmp);
        //     return;
        // }

        if(cnt == 4)
        {
            cnt = 0;
            cout<<tmp<<endl;
            return;
        }

        for(int i = 1; i <= 3; i++){
            cout<<"loop..."<<endl;
            int num = 0;
            string pill = "";
            for(int j = 0; j < i ; j++)
            {
                pill.push_back(s[j + start]);
                num = num * 10 + s[j + start] - '0';
            } 
            cout<<pill<<' '<<num<<' '<<tmp+pill+'.'<<endl;

            if(num > 255) break;
            cnt++;
            findIpAddress(s, start+i, tmp + pill + '.');

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

    vector<string> res = Solution().restoreIpAddresses("25525511135");
    // for( int k = 0; k < res.size(); k++ )
    //     cout<<res[k]<<endl;

    return 0;
}
