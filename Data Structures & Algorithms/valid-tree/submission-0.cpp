class Solution {
private:
    unordered_map<int, unordered_set<int>> tree_;

    bool validTree(int node, int previous, unordered_set<int>& visited) {
        if (visited.contains(node)) {
            return false;
        }
        visited.insert(node);
        for (int neighbor : tree_[node]) {
            if (neighbor == previous) {
                continue;
            }
            if (!validTree(neighbor, node, visited)) {
                return false;
            }
        }
        return true;
    }

public:
    
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }
        
        // we first need to build the tree
        for (const auto& edge : edges) {
            tree_[edge[0]].insert(edge[1]);
            tree_[edge[1]].insert(edge[0]);
        }

        unordered_set<int> visited;
        if (!validTree(0, -1, visited)) {
            return false;
        }

        if (visited.size() == n) {
            return true;
        }
        return false;
    }
};
