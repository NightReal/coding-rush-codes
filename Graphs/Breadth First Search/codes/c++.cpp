vector<vector<int>> g;

vector<int> dist;

void bfs(int start) {
	dist.assign(g.size(), INT_MAX);
	dist[start] = 0;
	deque<int> q;
	q.push_back(start);
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		for (int u : g[v]) {
			if (dist[u] == INT_MAX) {
				dist[u] = dist[v] + 1;
				q.push_back(u);
			}
		}
	}
}
	
