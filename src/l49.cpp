
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    static std::vector<std::vector<std::string>> groupAnagramSlowSolution(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> res_map{};
        std::vector<std::string> empty_vec{};
        // bit flag for char ch - 'a'; 'aaaa' == 'a'; 'bbaa' == 'baaa' 
        // bit flag 无法检测重复项
        // 但我可能可以用 bit flag 的值 加上 长度以及差值''，
        // 或者hash编码 a3b1, 但是如何保证字母有序
        // 那么就是 ch[26], 根据差值 + 1, 不为0的遍历？N * 26 还是O(N)
        // 还需要处理空字符串
        int ch[26] = {0};
        for (auto str : strs) {
            if (str.empty()) {
                empty_vec.push_back(str);
                continue;
            }
            // 可优化
            // iterate ch
            for (auto _ch : str) {
                ch[_ch - 'a']++;
            }
            std::string hash_str = "";
            // iterate  
            for (int i = 0; i < 26; i++) {
                if (ch[i] != 0) {
                    std::string hash_fragment = {(char)(i + 'a')};
                    hash_str.append(hash_fragment + std::to_string(ch[i]));
                    ch[i] = 0; // reset for next iteration
                }
            }
            // save hash result
            auto it = res_map.find(hash_str);
            if (it == res_map.end()) {
                auto vec = std::vector<std::string> {str};
                res_map.insert({hash_str, vec});
            } else {
                it->second.push_back(str);
            }
        }

        std::vector<std::vector<std::string>> res{};
        if (empty_vec.size()>0) {
            res.push_back(empty_vec);
        }
        for (auto it : res_map) {
            res.push_back(it.second);
        }
        return res;
    }

    // 排序入hash
    static std::vector<std::vector<std::string>> groupAnagram_sort(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> res_map{};
        for (auto str : strs) {
            std::string key = str;
            std::sort(key.begin(), key.end());
            res_map[key].push_back(str);
        }

        std::vector<std::vector<std::string>> res{};
        for (auto it : res_map) {
            res.push_back(it.second);
        }
        return res;
    }


    /**
    * return a1b2c3...
    */
    std::string hash(const std::string& str) {
        int counter[26] = {0};    
        for (auto ch : str) {
            counter[static_cast<int>(ch - 'a')]++;
        }
        std::string res = "";
        for (int i = 0;i < 26;i++) {
            int counts = counter[i];
            if (counts == 0) continue;
            res.append(std::string(counts, i + 'a'));
        }
        return res;
    }
    // 单词计数
    std::vector<std::vector<std::string>> groupAnagram(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> res_map{};
        for (auto str : strs) {
            std::string key = hash(str);
            res_map[key].push_back(str);
        }

        std::vector<std::vector<std::string>> res{};
        for (auto it : res_map) {
            res.push_back(it.second);
        }
        return res;
    }
};

int main() {
    std::vector<std::string> strs = {"cat","rye","aye","cud","cat","old","fop","bra"};
    auto result = Solution().groupAnagram(strs);
    return 0;
}