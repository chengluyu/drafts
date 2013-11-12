#include <iostream>

using namespace std;

#define PID "guardian" 

const int MAX = 700 + 2;

int n, m, w[MAX][MAX] = { 0 }, ans = 0;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> w[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (w[i - 1][j] < w[i][j] &&
          w[i + 1][j] < w[i][j] &&
          w[i][j - 1] < w[i][j] &&
          w[i][j + 1] < w[i][j]) {
        ++ans;
        cout << i << ' ' << j << endl;
      } else if (w[i - 1][j - 1] < w[i][j] &&
                 w[i - 1][j + 1] < w[i][j] &&
                 w[i + 1][j - 1] < w[i][j] &&
                 w[i + 1][j + 1] < w[i][j]) {
        ++ans;
        cout << i << ' ' << j << endl;
      }
    }
  cout << ans << endl;
  return 0;
}

/*
8 7
4 3 2 2 1 0 1
3 3 3 2 1 0 1
2 2 2 2 1 0 0
2 1 1 1 1 0 0
1 1 0 0 0 1 0
0 0 0 1 1 1 0
0 1 2 2 1 1 0
0 1 1 1 2 1 0
*/
