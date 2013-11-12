#include <array>
#include <iostream>

using namespace std;

const int N = 10, Q = 1000 + 1;

array<int, N> value, count;

int f[N][Q] = { 0 };

int main() {
  int n, k, q;

  cin >> n >> k;

  for (int i = 0; i < n; ++i)
    cin >> value[i] >> count[i];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= Q; ++j) {
      for (int k = 0; k <= count[i]; ++k) {
        if (j - k * value[i] < 0)
          break;
        if (f[i - 1][j - k * value[i]] > f[i][j])
          f[i][j] = f[i - 1][j - k * value[i]] + value[i];
      }
    }
  }

  for (int i = 0; i < k; ++i) {
    cin >> q;
    cout << f[n - 1][q] % 10000 << endl;
  }
  return 0;
}