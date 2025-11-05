#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);  // edge from b -> a
            indegree[p[0]]++;
        }
        
        // Step 2: Queue for nodes with 0 indegree
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        // Step 3: BFS
        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            
            for (int next : adj[course]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }
        
        // Step 4: Check if all courses are completed
        return count == numCourses;
    }
};
