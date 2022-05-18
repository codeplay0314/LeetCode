// See: Problem Problem 1192. Critical Connections in a Network
// 

void dfs(int u, int fa) {
    static int stp = 0;
    dfn[u] = low[u] = stp++;
    for (int v : edges[u]) {
        if (v != fa) {
            if (dfn[v] < 0) dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                ans.push_back(vector<int>{u, v});
            }
        }
    }
}