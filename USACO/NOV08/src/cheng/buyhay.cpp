/*
USACO NOV08 buyhay
*/
#define PID "buyhay"
#include <algorithm>
#ifdef CONSOLE
#include <iostream>
using namespace std;
#else
#include <fstream>
using namespace std;
ifstream cin(PID ".in");
ofstream cout(PID ".out");
#endif

const int N = 100 + 1, H = 50000 + 1;

int n, h, c[N], p[N], f[N][H];

int main() {
  cin >> n >> h;
  for (int i = 0; i < n; ++i)
    cin >> p[i] >> c[i];

  // dp
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < h; ++j) {
      f[i][j] = 
    }
  }
  return 0;
}