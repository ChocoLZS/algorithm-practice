#include <queue>
#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> indegree(numCourses, 0);
        for (auto &p: prerequisites) {
            int pre = p[0], next = p[1];
            adj[next].push_back(pre);
            indegree[pre]++;
        }

        std::queue<int> node_q;
        for (int i = 0; i < numCourses;i++) {
            if (indegree[i] == 0) {
                node_q.push(i);
            }
        }
        // 找到了入度为0的节点，弹出对应adj
        while(!node_q.empty()) {
            auto indegree_0_node = node_q.front();
            node_q.pop();
            for (auto node_next: adj[indegree_0_node]) {
                indegree[node_next]--;
                if (indegree[node_next] == 0) {
                    node_q.push(node_next);
                }
            }
        }

        bool res = true;
        for (int i = 0;i < numCourses;i++) {
            if (indegree[i] != 0) {
                res = false;
                break;
            }
        }
        return res;
    }
};