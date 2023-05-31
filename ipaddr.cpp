#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::string;
using std::vector;


class Solution {
    vector<string> ans;
    string one_ip = "";
    int num_dot = 0;
public:
    void backtracking(int start, string s) {
        if (num_dot == 3) {
            cout << "sub "<< s.substr(start) << "\n";
            cout << "size " << s.length() << "start?? " << start << "\n";
            if (start >= s.length()) {
                cout << "Ret" ;
                return;
            }
            if (start < s.length() && stoi(s.substr(start)) >= 0 &&  stoi(s.substr(start)) < 256) {
                ans.push_back(s);
            }
            
            return;     
        }
        for (int i = start; i < s.length() -1 + num_dot; ++i) { // what about the dots
            if (i - start + 1 > 3) break;
            if (s.substr(start, 1) == "0" and (i - start + 1) > 1) break;
            
            if (stoi(s.substr(start, i - start + 1)) >= 0 && stoi(s.substr(start, i - start + 1)) < 256) {
                s.insert(i + 1, ".");
                num_dot++;
                backtracking(i + 2, s);
                num_dot--;
                s.erase(i + 1, 1);
               // cout << "after ip : " << one_ip << "\n";
            }
        }

    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(0, s);
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> ans = s.restoreIpAddresses("101023");
    // for (auto i:ans) {
    //     cout << i << "\n";
    // }
}