#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

//#define PID "cowrun"
//ifstream cin(PID ".in");
//ofstream cout(PID ".out");

const int N = 10000 + 1, M = 500 + 1 + 1;
int n, m, d[N] = { 0 }, f[N][M] = { 0 }, p[N][M] = { 0 };

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> d[i];
    
  for (int i = 1; i <= n; ++i) {
    //f[i][0] = max(f[i][0], f[i - 1][0]);
    if (f[i - 1][0] > f[i - 1][1]) {
      f[i][0] = f[i - 1][0];
      p[i][0] = 0;
    } else {
      f[i][0] = f[i - 1][1];
      p[i][0] = 1;
    }
    for (int j = 1; j <= m && j <= i; ++j) {
      //f[i][j] = max(f[i][j], f[i - 1][j - 1] + d[i]);
      if (f[i - 1][j - 1] + d[i] > f[i - 1][j + 1]) {
        f[i][j] = f[i - 1][j - 1] + d[i];
        p[i][j] = j - 1;
      } else {
        f[i][j] = f[i - 1][j + 1];
        p[i][j] = j + 1;
      }
    }
  }
  
  for (int j = 0; j <= m; ++j) {
    for (int i = 1; i <= n; ++i)
      cout << f[i][j] << ' ';
    cout << endl;
  }
  
  vector<int> road;
  int pos = 0;
  for (int i = n; i > 0; --i) {
    road.push_back(pos);
    pos = p[i][pos];
  }
  reverse(road.begin(), road.end());
  int prev = 0, sum = 0, cost = 0;
  for (int i = 0; i < road.size(); ++i) {
    if (road[i] > prev) {
      ++ cost;
      sum += d[i + 1];
      cout << i + 1 << ": run " << d[i + 1] << " m, cost: " << cost << endl;
    } else {
      if (-- cost < 0)
        cost = 0;
      cout << i + 1 << ": rest, cost: " << cost << endl;
    }
    prev = road[i];
  }
  cout << "sum: " << sum << ", cost: " << cost << endl;
  
  cout << f[n][0] << endl;
  return 0;
}

/*
5 2
5
3
4
2
10
*/
