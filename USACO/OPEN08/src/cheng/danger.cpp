#include <fstream>

using namespace std;

#define PID "danger"
ifstream cin(PID ".in");
ofstream cout(PID ".out");

const int N = 100 + 1, M = 10000 + 1;

int n, m, a[M] = { 0 }, d[N][N] = { 0 }, ans = 0;

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    --a[i];
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> d[i][j];
  
  // Floyd-Warshall
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (d[i][k] + d[k][j] < d[i][j])
          d[i][j] = d[i][k] + d[k][j];
  
  // begin debug
//  for (int i = 0; i < n; ++i) {
//    for (int j = 0; j < n; ++j)
//      cout << d[i][j] << ' ';
//    cout << endl;
//  }
  // end debug
  
  for (int i = 1; i < m; ++i)
    ans += d[a[i - 1]][a[i]];
    
  cout << ans << endl;
  return 0;
}
/*
3 4
1
2
1
3
0 5 1
5 0 2
1 2 0
*/
