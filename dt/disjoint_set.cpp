#include <iostream>

using namespace std;

const int N = 5000 + 1;

int n, m, q, pre[N], rank[N] = { 0 };

int get_father(int x) {
  if (pre[x] == x)
    return x;
  return pre[x] = get_father(pre[x]);
}

void merge(int x, int y) {
  x = get_father(x);
  y = get_father(y);
  if (rank[x] < rank[y])
    swap(x, y);
  if (rank[x] == rank[y])
    ++ rank[x];
  pre[y] = x;
}

inline bool is_relative(int x, int y) {
  return get_father(x) == get_father(y);
}

void init_disjoint_set() {
  for (int i = 1; i <= n; ++i)
    pre[i] = i;
}

void print_pre() {
  for (int i = 1; i <= n; ++i)
    cout << "pre[" << i << "] = " << pre[i] << endl;
}

int main() {
  cin >> n >> m >> q;
  init_disjoint_set();
  int x, y;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    merge(x, y);
    print_pre();
  }
  for (int i = 0; i < q; ++i) {
    cin >> x >> y;
    cout << (is_relative(x, y) ? "Yes" : "No") << endl;
  }
  return 0;
}