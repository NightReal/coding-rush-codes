vector<int> zFunction(string s) {
	int n = s.size();
	vector<int> z(n);
	int l = 0;
	int r = 0;
	for (int i = 1; i < n; i++) {
		if (i < r) {
			z[i] = min(r - i, z[i - l]);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] > r) {
			r = i + z[i];
			l = i;
		}
	}
	return z;
}
