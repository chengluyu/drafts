/*
USACO Contest JAN09 bestspot
*/
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

const int V = 500 + 1;

int p, f, c, prefer[V], w[V][V];

void debug() {
  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < p; ++j)
      if (w[i][j] != INT_MAX)
        cout << w[i][j] << ' ';
      else
        cout << 'x' << ' ';
    cout << endl;
  }
}

int main() {
  int a, b, t;

  cin >> p >> f >> c;
  for (int i = 0; i < p; ++i)
    for (int j = 0; j < p; ++j)
      w[i][j] = INT_MAX;
  for (int i = 0; i < f; ++i)
    cin >> prefer[i];
  for (int i = 0; i < c; ++i) {
    cin >> a >> b >> t;
    w[a][b] = w[b][a] = t;
  }

  debug();

  for (int i = 0; i < p; ++i)
    for (int j = 0; j < p; ++j)
      if (i != j)
        for (int k = 0; k < p; ++k)
          if (j != k && w[i][k] + w[k][j] < w[i][j])
            w[i][j] = w[i][k] + w[k][j];

  cout << endl;
  debug();

  int ans = INT_MAX;
  for (int i = 0; i < p; ++i) {
    int sum = 0;
    for (int j = 0; j < f; ++j)
      if (i != prefer[j]) {
        if (w[i][prefer[j]] == INT_MAX) {
          sum = INT_MAX;
          break;
        } else
          sum += w[i][prefer[j]];
      }
    if (sum < ans)
      ans = sum;
  }

  cout << ans << endl;
  return 0;
}