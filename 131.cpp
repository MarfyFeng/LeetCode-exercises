#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:

    vector<vector<string>> res;

    bool JudgeString(const string &substring){
        cout<<"start judge... "<<substring<<' ';

        int p = 0, q = substring.size() - 1;
        while(p < q){
            if(substring[p] != substring[q]){
                cout<<'0'<<endl;
                return false;
            }
            p++;
            q--;
        }
        cout<<'1'<<endl;
        return true;
    }

    void FindSubString(const string &s, int start, vector<string> &buf){
        
        if(start == s.size()){
            for(int i = 0; i < buf.size(); i++)
                cout<<buf[i]<<' ';
            cout<<endl;
            res.push_back(buf);
            return;
        }

        for(int i = 1; i <= s.size() - start; i++){
            cout<<"find start: "<<start<<endl;
            
            string substring = "";
            for(int j = 0; j < i; j++){
                substring.push_back(s[start + j]);
            }
            if(!JudgeString(substring))
                continue;
            buf.push_back(substring);
            FindSubString(s, start + i, buf);
            buf.pop_back();
        }
        return;
    }

public:
    vector<vector<string>> partition(string s) {
        
        res.clear();
        if(s == "")
            return res;
        
        vector<string> buf;
        buf.clear();
        FindSubString(s, 0, buf);

        return res;
    }
};

int main(){
    vector<vector<string>> res = Solution().partition("aab");
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout<<res[i][j]<<' ';
        cout<<endl;
    }
        
    return 0;
}