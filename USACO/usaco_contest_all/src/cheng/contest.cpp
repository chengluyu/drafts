/*
USACO Contest JAN08 contest
*/
#define PID "contest"

#ifdef USE_CONSOLE
  #include <iostream>
  using namespace std;
#else
  #include <fstream>
  using namespace std;
  ifstream cin(PID ".in");
  ofstream cout(PID ".out");
#endif

int main() {
  const int N = 100 + 1;

  int n, m, a, b, ans = 0;
  bool c[N][N] = { 0 }; // connectivity

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    c[a - 1][b - 1] = true;
  }

  for (int i = 0; i < n; ++i)
    c[i][i] = true;

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      if (c[i][k])
        for (int j = 0; j < n; ++j)
          if (c[k][j])
            c[i][j] = true;

  for (int i = 0; i < n; ++i) {
    bool connect = true;

    for (int j = 0; j < n; ++j)
      if (!c[i][j] && !c[j][i]) {
        connect = false;
        break;
      }

    if (connect)
      ++ans;
  }

  cout << ans << endl;
  return 0;
}