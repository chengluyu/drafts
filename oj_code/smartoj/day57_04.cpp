#include <iostream>

using namespace std;

const int N = 1e3 + 1, MAX = 11;

int n, m, t[N], v[N], c[N];
int f[N][N], drug[MAX][MAX] = { 0 };

inline int lowbit(int x) {
  return x & (-x);
}

void read() {
  int time, value, total = 0;

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> time >> value;
    ++drug[time][value];
  }

  for (int i = 0; i < MAX; ++i)
    for (int j = 0; j < MAX; ++j)
      if (drug[i][j] != 0) {
        // t[total] = i;
        // v[total] = j;
        // c[total] = drug[i][j];
        // ++total;

        int count = drug[i][j], p;
        while (count) {
          p = lowbit(count);
          t[total] = i * p;
          v[total] = j * p;
          c[total] = 1;
          ++total;
          count &= ~p;
        }
      }

  n = total;
}

#define PRT(x) cout << #x << ": " << x << endl

void dp() {
  for (int j = 0; j <= m; ++j) {
    // if (j - t[0] > 0 && v[0] > f[0][j])
    //   f[0][j] = v[0];
    for (int k = 0; k <= c[0]; ++k) {
      if (j - k * t[0] < 0)
        break;
      if (k * v[0] > f[0][j])
        f[0][j] = k * v[0];
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      // if (j - t[i] < 0 && f[i - 1][j - t[i]] + v[i] > f[i][j])
      //   f[i][j] = f[i - 1][j - t[i]] + v[i];
      for (int k = 0; k <= c[i]; ++k) {
        if (j - k * t[i] < 0)
          break;
        if (f[i - 1][j - k * t[i]] + k * v[i] > f[i][j])
          f[i][j] = f[i - 1][j - k * t[i]] + k * v[i];
      }
    }
  }
}

void debug() {
  cout << "> item info:" << endl;
  cout << "\ttime\tvalue\tcount" << endl;
  for (int i = 0; i < n; ++i)
    cout << i << '\t' << t[i] << '\t' << v[i] << '\t' << c[i] << endl;
  cout << "------------------------" << endl;
  cout << "> dynamic programming:" << endl;
  cout << '\t';
  for (int j = 0; j < n; ++j)
    cout << j << '\t';
  cout << endl << "\t--------------------" << endl;
  for (int i = 0; i <= m; ++i) {
    cout << i << " | \t";
    for (int j = 0; j < n; ++j)
      cout << f[j][i] << '\t';
    cout << endl;
  }
}

int main() {
  read();
  dp();
  // debug();
  cout << f[n - 1][m] << endl;
  return 0;
}
/*
3 9
10 10
8 1
1 2

4 9
10 10
8 1
1 2
1 2

5 9
10 10
8 1
1 2
1 2
1 2

6 11
10 10
8 6
8 6
1 2
1 2
1 2
*/