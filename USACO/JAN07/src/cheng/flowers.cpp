#include <algorithm>
#ifdef CONSOLE
#include <iostream>
#else
#include <fstream>
#define PID "flowers"
std::ifstream cin(PID ".in");
std::ofstream cout(PID ".out");
#endif

using namespace std;

const int N = 100000 + 1;

struct cow {
  int t, d;
  inline bool operator< (const cow & rhs) const {
    int w1 = t * rhs.d, w2 = rhs.t * d;
    return w1 < w2;
  }
} c[N];

int main() {
  int n, sum = 0, ans = 0;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c[i].t >> c[i].d;
    c[i].t *= 2;
  }

  sort(c, c + n);

  // for (int i = 0; i < n; ++i) {
  //   cout << c[i].t << ' ' << c[i].d << endl;
  // }

  for (int i = n - 1; i >= 0; --i) {
    ans += sum * c[i].t;
    sum += c[i].d;
  }

  cout << ans << endl;
  return 0;
}

/*
6
3 1
2 5
2 3
3 2
4 1
1 6
*/