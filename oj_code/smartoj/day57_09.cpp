#include <climits>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1500;

inline int abs(int x) {
  return x < 0 ? -x : x;
}

int n, father[N], weight[N];
int total = 0, first[N] = { 0 }, next[N] = { 0 }, to[N];
int f[N][3];
bool visited[N] = { 0 };

int tree_dp(int u) {
  int child_count = 0;

  visited[u] = true;

  for (int p = first[u]; p != 0; p = next[p]) {
    int v = to[p];

    if (!visited[v]) {
      ++child_count;
      tree_dp(v);
    }
  }

  if (child_count == 0) {
    f[u][0] = weight[u];
    f[u][1] = weight[u];
    f[u][2] = 0;
  } else {
    bool safe = false;
    int dist = INT_MAX;

    for (int p = first[u]; p != 0; p = next[p]) {
      int v = to[p];

      f[u][0] += min(min(f[v][0], f[v][1]), f[v][2]);

      if (f[v][0] > f[v][1])
        f[u][1] += f[v][1];
      else {
        f[u][1] += f[v][0];
        safe = true;
      }

      if (abs(f[v][0] - f[v][1]) > dist)
        dist = abs(f[v][0] - f[v][1]);
    }

    f[u][2] = f[u][1];
    if (!safe)
      f[u][1] += dist;
  }
}

int main() {
  int u, v, w, m;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> u >> w >> m;
    --u;
    weight[u] = w;
    for (int j = 0; j < m; ++j) {
      cin >> v;
      --v;
      father[v] = u;
      to[total] = v;
      next[total] = first[u];
      first[u] = total;
      ++total;
    }
  }

  tree_dp(0);

  cout << min(f[0][0], f[0][1]) << endl;

  for (int i = 0; i < n; ++i) {
    cout << f[i][0] << ' ' << f[i][1] << ' ' << f[i][2] << endl;
  }
  return 0;
}