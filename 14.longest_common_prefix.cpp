#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 水平扫描法
        if (strs.empty())
            return "";
        // 拿到第一个字符串
        string prefix = strs[0];

        // 遍历之后的字符串
        for (int i=1; i<strs.size(); i++) {
            // 没有发现该前缀，就去除前缀最后字符
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty())
                    return "";
            }
        }

        return prefix;
    }
};

// 主函数
int main(void) {

    vector<string> strs = {
        "flow",
        "flight",
        "flower"
    };

    Solution s;
    string res = s.longestCommonPrefix(strs);

    cout << "res: " << res << endl;
    return 0;
}