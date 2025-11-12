#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
    // dp[i][j] word1 0->i word2 0->j 
    // word1 到 word2 的最小操作数
    // 三种操作
    // word1 插入 字符
    // word1 删除字符
    // word1 替换字符
    // 假设 word1的长度 <= word2，那么只有两种操作
    // word1 插入字符，word1 替换字符
    // word1 经过最少次操作到word2
    // dp[i][j]
    // word1 空串 仅添加
    // word1 一个字符，先寻找是否有重叠的，没有的话替换
    // word1 两个字符，先寻找是否有重叠的，没有就替换
    // word1 三个字符，
    /// -----
    // dp[i][j] 0...i -> 0...j 的最小操作数
    // dp[0][j] = j
    // dp[i][0] = i
    // dp[i][j] = 如果 word1[i] == word2[j] 那么，dp[i][j] = dp[i-1][j-1];
    // 取三者最小值
    // 如果 i > j 那么，dp[i][j] = dp[i-1][j] + 1; // 删除
    // 如果 i < j 那么，dp[i][j] = dp[i][j-1] + 1; // 增加
    // 如果 i == j 那么，dp[i][j] = dp[i-1][j-1] + 1; // 替换

    int minDistance(std::string word1, std::string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        std::vector<std::vector<int>> dp(
            len1 + 1,
            std::vector<int>(len2 + 1, 0)
        );
        for (int i = 0;i <= len1;i++) dp[i][0] = i;
        for (int j = 0;j <= len2;j++) dp[0][j] = j;
        for (int i = 1;i <= len1;i++) {
            for (int j = 1;j <= len2;j++) {
                if (word1.at(i-1) == word2.at(j-1)) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = std::min(
                        {dp[i-1][j] + 1, dp[i][j-1]+1, dp[i-1][j-1] + 1}
                    );
                }
            }
        }
        return dp[len1][len2];
    }
};