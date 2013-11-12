#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

const int T = 10000 + 1, N = 100 + 1;

struct interval {
  int a, b, w;
};

inline bool operator< (const interval & lhs, const interval & rhs) {
  if (lhs.a == rhs.a)
    return lhs.b < rhs.b;
  return lhs.a < rhs.a;
}

inline istream & operator>> (istream & in, interval & i) {
  return in >> i.a >> i.b >> i.w;
}

int n, t, f[N][T];
interval l[N];

int main() {
  cin >> t >> n;
  for (int i = 0; i < n; ++i)
    cin >> l[i];

  sort(l, l + n);

  for (int i = 0; i <= t; ++i)
    f[0][i] = (l[i].w >= i ? l[i].w : INT_MIN);

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= t; ++j) {
      if (j - l[i].w >= 0 && l[i].a >= j)
        if (f[i - 1][j - l[i].w] + l[i].w > f[i][j])
          f[i][j] = f[i - 1][j - l[i].w] + l[i].w;
      if (f[i - 1][j] > f[i][j])
        f[i][j] = f[i - 1][j];
      if (f[i][j] == 0)
        f[i][j] = INT_MIN;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= t; ++j) {
      cout << f[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
/*
5 3
1 1 2
1 3 5
4 1 3

5 3
1 2 2
1 3 5
4 1 3
*/