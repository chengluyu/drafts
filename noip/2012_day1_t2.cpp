#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1000 + 1;

int n;

struct person {
  unsigned long long a, b, w;
  inline bool operator< (const person & rhs) const {
    return w < rhs.w;
  }
} p[N];

int main() {
  cin >> n;
  ++n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i].a >> p[i].b;
    p[i].w = p[i].a * p[i].b;
  }

  sort(p + 1, p + n);

  unsigned long long sum = p[0].a, ans = 0;

  for (int i = 1; i < n; ++i) {
    if (sum / p[i].b > ans)
      ans = sum / p[i].b;
    sum *= p[i].a;
  }

  cout << ans << endl;
  return 0;
}

/*
3
1 1
2 3
7 4
4 6

60
*/