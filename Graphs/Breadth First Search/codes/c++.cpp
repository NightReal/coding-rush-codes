const int INF = 1e9;
vector<vector<int>> g;

vector<int> dist;

void bfs(int start) {
	dist.assign(g.size(), INF);
	dist[start] = 0;
	deque<int> q;
	q.push_back(start);
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		for (int u : g[v]) {
			if (dist[u] == INF) {
				dist[u] = dist[v] + 1;
				q.push_back(u);
			}
		}
	}
}
	
