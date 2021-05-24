int tree[MAXN];

void add(int i, int x) {
	for (; i < MAXN; i += i & (-i)) {
		tree[i] += x;
	}
}

int get(int i) {
	int ans = 0;
	for (; i > 0; i -= i & (-i)) {
		ans += tree[i];
	}
	return ans;
}
