#include <fstream>

using namespace std;

const int N = 2500 + 1;

int n, m[N + 1] = { 0 }, f[N] = { 0 };

#define PRINT(x) cout << #x ": " << x << endl

#define PID "river"
ifstream cin(PID ".in");
ofstream cout(PID ".out");

int main() {
  cin >> n >> m[0];
  for (int i = 1; i <= n; ++i) {
    cin >> m[i];
    m[i] += m[i - 1];
  }

  f[1] = m[1] + m[0];
  for (int i = 1; i <= n; ++i) {
    f[i] = m[i];
    for (int j = 1; j < i; ++j) {
//      PRINT(i);
//      PRINT(j);
//      PRINT(i - j);
//      PRINT(m[i - j]);
//      PRINT(f[j] + m[i - j]);
//      cout << endl;
      if (f[j] + m[i - j] < f[i])
        f[i] = f[j] + m[i - j];
    }
    f[i] += m[0];
  }

//  for (int i = 1; i <= n; ++i)
//    cout << f[i] << ' ';
//  cout << endl;

  cout << f[n] - m[0] << endl;
  return 0;
}

/*
5 10
3
4
6
100
1
*/

