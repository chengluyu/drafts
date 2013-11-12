#include <cassert>
#include <iostream>

using namespace std;

const int N = 100000;

int n, seq[N];

#define PRT(x) cout << #x << " = " << x << endl

struct node {
  int l, r, sum;
  node * lc, * rc;

  node(int lv, int rv) : l(lv), r(rv), lc(NULL), rc(NULL) { }

  void auto_build() {
    if (l < r) {
      int mid = (l + r) / 2;
      lc = new node(l, mid);
      rc = new node(mid + 1, r);
      lc->auto_build();
      rc->auto_build();
      sum = lc->sum + rc->sum;
    } else
      sum = seq[l];
  }

  static void modify_impl(node * pn, int pos) {
    if (pn->l == pn->r && pn->l == pos)
      pn->sum = seq[pos];
    
    else {
      int mid = (pn->l + pn->r) / 2;

      if (pos <= mid)
        modify_impl(pn->lc, pos);

      else
        modify_impl(pn->rc, pos);

      pn->sum = pn->lc->sum + pn->rc->sum;
    }
  }

  static int query_impl(node * pn, int l, int r) {
    if (l == pn->l && r == pn->r)
      return pn->sum;

    int mid = (pn->l + pn->r) / 2;

    if (r <= mid)
      return query_impl(pn->lc, l, r);

    else if (l > mid)
      return query_impl(pn->rc, l, r);

    else {
      return query_impl(pn->lc, l, mid) + query_impl(pn->rc, mid + 1, r);
    }
  }
};

class tree {
  node * root;
  int lb, rb;
public:
  tree() : root(NULL), lb(0), rb(0) { }

  inline bool in_range(int pos) const {
    return lb <= pos && pos <= rb;
  }

  inline void modify(int pos, int value) {
    if (in_range(pos)) {
      seq[pos] += value;
      node::modify_impl(root, pos);
    }
  }

  inline int query(int l, int r) {
    if (r > rb)
      r = rb;
    if (l < 0)
      l = 0;
    return node::query_impl(root, l, r);
  }

  inline void initialize(int l, int r) {
    lb = l;
    rb = r;
    root = new node(l, r);
    root->auto_build();
  }
};

int main() {
  tree t;

  cin >> n;

  for (int i = 0; i < n; ++i)
    cin >> seq[i];

  t.initialize(0, n - 1);

  int m, opt, arg1, arg2;

  cin >> m;

  for (int i = 0; i < m; ++i) {
    cin >> opt >> arg1 >> arg2;
    if (opt == 2)
      cout << t.query(arg1 - 1, arg2 - 1) << endl;
    else
      t.modify(arg1 - 1, arg2);
  }

  return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 10
      1       5 10
      -3       -3 +1

6
4 5 6 2 1 3
4
1 3 5
2 1 4
1 1 9
2 2 6
*/