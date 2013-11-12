#include <fstream>

using namespace std;

const int N = 100 + 2, T = 15 + 1;

bool c[N][N] = { 0 };
int n, m, t, f[N][N][T] = { 0 };
int r1, c1, r2, c2;

#define PID "ctravel"
ifstream cin(PID ".in");
ofstream cout(PID ".out");

int main() {
  char ch;

  cin >> n >> m >> t;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      cin >> ch;
      c[i][j] = ch == '.';
    }
  cin >> r1 >> c1 >> r2 >> c2;

  f[r1][c1][0] = 1;

  for (int k = 1; k <= t; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        if (c[i][j]) {
          if (c[i - 1][j] && f[i - 1][j][k - 1] > 0)
            f[i][j][k] += f[i - 1][j][k - 1];
          if (c[i + 1][j] && f[i + 1][j][k - 1] > 0)
            f[i][j][k] += f[i + 1][j][k - 1];
          if (c[i][j - 1] && f[i][j - 1][k - 1] > 0)
            f[i][j][k] += f[i][j - 1][k - 1];
          if (c[i][j + 1] && f[i][j + 1][k - 1] > 0)
            f[i][j][k] += f[i][j + 1][k - 1];
        } else {
          f[i][j][k] = -2;
        }
      }

//  for (int k = 0; k <= t; ++k) {
//    cout << "T = " << k << ":\n";
//    for (int i = 1; i <= n; ++i) {
//      for (int j = 1; j <= m; ++j)
//        cout << f[i][j][k] << ' ';
//      cout << endl;
//    }
//    cout << endl;
//  }

  cout << f[r2][c2][t] << endl;

  return 0;
}

/*
4 5 6
...*.
...*.
.....
.....
1 3 1 5
*/

