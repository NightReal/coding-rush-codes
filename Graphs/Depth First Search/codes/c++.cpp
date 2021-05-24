vector<vector<int>> g;

vector<int> used;
vector<int> tin;
vector<int> tout;
int cur_time = 0;

void dfs(int v) {
	used[v] = 1;
	tin[v] = cur_time++;
	for (int u : g[v]) {
		if (!used[u]) {
			dfs(u);
		}
	}
	tout[v] = cur_time;
}
