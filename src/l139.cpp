#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> words {wordDict.begin(), wordDict.end()};
        std::vector<bool> dp(s.size() + 1, false); // 0 - j
        dp[0] = true; // ""
        for (int i = 1;i <= s.size(); i++) {
            for (int j = 0;j < i;j++) { // j..i
                std::string str = s.substr(j ,i - j);
                // if (words.count(str) > 0) {
                //     if (j == 0) dp[i] = true;
                //     else if (dp[i] == false) dp[i] = dp[j];
                // }
                

                // 优化
                if (dp[j] && words.count(str) > 0) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};

int main() {
    std::string s = "aaaaaaa";
    std::vector<std::string> wordDict = {
        "aaaa", "aaa"
    };

    auto res = Solution().wordBreak(s, wordDict);
}