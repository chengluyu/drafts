#include <algorithm>
#include <fstream>

using namespace std;

#define PID "egroup"
ifstream cin(PID ".in");
ofstream cout(PID ".out");

const int N = 30000 + 1;

int n, a[N] = { 0 }, f[N][4] = { 0 }, g[N + 1][4] = { 0 };

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  for (int i = 1; i <= n; ++i) {
    f[i][1] = f[i - 1][1] + (a[i] == 1 ? 0 : 1);
    f[i][2] = min(f[i - 1][1], f[i - 1][2]) + (a[i] == 2 ? 0 : 1);
    f[i][3] = min(min(f[i - 1][1], f[i - 1][2]), f[i - 1][3]) + (a[i] == 3 ? 0 : 1);
  }

  for (int i = n; i >= 1; --i) {
    g[i][1] = g[i + 1][1] + (a[i] == 1 ? 0 : 1);
    g[i][2] = min(g[i + 1][1], g[i + 1][2]) + (a[i] == 2 ? 0 : 1);
    g[i][3] = min(min(g[i + 1][1], g[i + 1][2]), g[i + 1][3]) + (a[i] == 3 ? 0 : 1);
  }

  int ans1 = min(f[n][1], min(f[n][2], f[n][3]));
  int ans2 = min(g[1][1], min(g[1][2], g[1][3]));

  cout << min(ans1, ans2) << endl;
  return 0;
}

