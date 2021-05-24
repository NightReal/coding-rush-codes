struct node {
	node *ch[2];
	node *p;
	bool rev;
	int sz;

	node() {
		ch[0] = ch[1] = p = NULL;
		rev = false;
		sz = 1;
	}
};

int getsz(node *n) {
	return (n == NULL) ? 0 : n->sz;
}

void pull(node *n) {
	n->sz = getsz(n->ch[0]) + getsz(n->ch[1]) + 1;
}

void push(node *n) {
	if (n->rev) {
		if (n->ch[0]) {
			n->ch[0]->rev ^= 1;
		}
		if (n->ch[1]) {
			n->ch[1]->rev ^= 1;
		}
		swap(n->ch[0], n->ch[1]);
		n->rev = 0;
	}
}

bool isRoot(node *n) {
	return n->p == NULL || (n->p->ch[0] != n && n->p->ch[1] != n);
}

int chnum(node *n) {
	return n->p->ch[1] == n;
}

void attach(node *n, node *p, int num) {
	if (n != NULL)
		n->p = p;
	if (p != NULL)
		p->ch[num] = n;
}

void rotate(node *n) {
	int num = chnum(n);
	node *p = n->p;
	node *b = n->ch[1 - num];
	node *pp = p->p;
	if (pp != NULL) {
		n->p = pp;
		if (!isRoot(p)) {
			pp->ch[chnum(p)] = n;
		}
	} else {
		n->p = NULL;
	}
	attach(p, n, 1 - num);
	attach(b, p, num);
	pull(p);
	pull(n);
}

node *qq[MAXN];

void splay(node *n) {
	node *nn = n;
	int top = 0;
	qq[top++] = nn;
	while (!isRoot(nn)) {
		nn = nn->p;
		qq[top++] = nn;
	}
	while (top) {
		push(qq[--top]);
	}
	while (!isRoot(n)) {
		if (!isRoot(n->p)) {
			if (chnum(n) == chnum(n->p)) {
				rotate(n->p);
			} else {
				rotate(n);
			}
		}
		rotate(n);
	}
}

void expose(node *n) {
	splay(n);
	n->ch[1] = NULL;
	pull(n);
	while (n->p != NULL) {
		splay(n->p);
		attach(n, n->p, 1);
		pull(n->p);
		splay(n);
	}
}

void makeRoot(node *n) {
	expose(n);
	n->rev ^= 1;
}

node *nodes[MAXN];
