// See: Problem 127. Word Ladder

int BiBFS(int S, int T) {
    int cnt = 0;
    queue<int> q;
    vector<vector<int>> dis(2, vector<int>(N, inf));
    q.push(S), dis[0][S] = 0;
    q.push(T), dis[1][T] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int t = 0; t < 2; t++)
            if (dis[t][u] != inf)
                for (auto v : E[u]) {
                    if (dis[t][v] == inf) q.push(v), dis[t][v] = dis[t][u] + 1;
                    if (dis[t^1][v] != inf) return dis[0][v] + dis[1][v] + 1;
                }
    }
    return 0;
}