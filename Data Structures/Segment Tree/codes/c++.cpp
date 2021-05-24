int arr[4 * MAXN];
int tree[4 * MAXN];

void build(int v, int l, int r) {
	if (l + 1 == r) {
		tree[v] = arr[l];
	} else {
		int m = (l + r) / 2;
		build(2 * v + 1, l, m);
		build(2 * v + 2, m, r);
		tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
	}
}

void update(int v, int l, int r, int i, int x) {
	if (i < l || i >= r) {
		return;
	}
	if (l + 1 == r) {
		arr[i] = x;
		tree[v] = x;
	} else {
		int m = (l + r) / 2;
		update(2 * v + 1, l, m, i, x);
		update(2 * v + 2, m, r, i, x);
	}
}

int get(int v, int l, int r, int ql, int qr) {
	if (ql >= r || l >= qr) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		return tree[v];
	}
	int m = (l + r) / 2;
	return get(2 * v + 1, l, m, ql, qr) + get(2 * v + 2, m, r, ql, qr);
}
