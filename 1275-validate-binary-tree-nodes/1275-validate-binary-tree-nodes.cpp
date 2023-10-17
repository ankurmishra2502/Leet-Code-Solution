class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, -1);

        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (find(parent, i) == find(parent, leftChild[i])) {
                    return false;
                }
                parent[leftChild[i]] = i;
            }

            if (rightChild[i] != -1) {
                if (find(parent, i) == find(parent, rightChild[i])) {
                    return false; 
                }
                parent[rightChild[i]] = i;
            }
        }

        int rootCount = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                rootCount++;
                if (rootCount > 1) {
                    return false; 
                }
            }
        }

        return rootCount == 1;
    }

    int find(vector<int>& parent, int node) {
        if (parent[node] == -1) {
            return node;
        }
        return parent[node] = find(parent, parent[node]);
    }
};