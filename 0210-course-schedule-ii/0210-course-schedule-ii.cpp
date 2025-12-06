class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);  // adjacency list
        vector<int> indegree(numCourses, 0);   // indegree count

        // Build graph & count indegrees
        for (auto &p : prerequisites) {
            int course = p[0];
            int pre = p[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Add all courses with 0 indegree → can be taken immediately
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            // Reduce indegree of neighbours
            for (int next : adj[node]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If we processed all courses → valid ordering
        if (order.size() == numCourses)
            return order;

        // Otherwise → cycle exists, no valid order
        return {};
    }
};
