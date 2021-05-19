vector<int> prefixFunction(string s) {
    int n = s.size();
    vector<int> pref(n);
    int k = 0;
    for (int i = 1; i < n; i++) {
	while (k > 0 && s[i] != s[k]) {
	    k = pref[k - 1];
	}
	if (s[i] == s[k]) {
	    k++;
	}
	pref[i] = k;
    }
    return pref;
}
