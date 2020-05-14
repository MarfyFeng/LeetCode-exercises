#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
private:

    vector<string> res;

    void findIpAddress(const string &s, int start, const string &tmp){
        
    }

public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if(s == "")
            return res;

        findIpAddress(s, 0, "");

        return res;
    }
};

int main() {


    return 0;
}