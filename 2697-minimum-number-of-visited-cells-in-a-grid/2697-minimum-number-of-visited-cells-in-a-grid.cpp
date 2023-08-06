class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (n == 1 && m == 1)
            return 1;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<array<int, 4>> q;
        q.push({0, 0, 0, 0});
        vis[0][0] = true;
        vector<int> row_start(n, 0), col_start(m, 0);
        for (int d = 0;!q.empty(); d++) {
            queue<array<int, 4>> nq;
            while (!q.empty()){
                auto [ci, cj, prev_row, prev_col] = q.front();
                q.pop();
                for (int i = max(ci + 1, prev_row) ; i < n && i - (ci + 1) < grid[ci][cj]; i++) {
                    int ni = i, nj = cj;
                    if (ni == n - 1 && nj == m - 1)
                        return d + 2;
                    if (vis[ni][nj])
                        continue;
                    vis[ni][nj] = true;
                    nq.push({ni, nj, grid[ci][cj] + ci, 0});
                }
                for (int j = max(cj + 1, prev_col); j < m && j - (cj + 1) < grid[ci][cj]; j++) {
                    int ni = ci, nj = j;
                    if (ni == n - 1 && nj == m - 1)
                        return d + 2;
                    if (vis[ni][nj])
                        continue;
                    vis[ni][nj] = true;
                    nq.push({ni, nj, 0, grid[ci][cj] + cj});
                }
            }
            swap(q, nq);
        }
        return -1;
    }
};