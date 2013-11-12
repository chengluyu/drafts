/*
USACO OPEN08 ratf
*/

#define PID "ratf"
#ifdef CONSOLE
#include <algorithm>
#include <iostream>
using namespace std;
#else
#include <fstream>
using namespace std;
ifstream cin(PID ".in");
ofstream cout(PID ".out");
#endif

int k;

int dfs(int n) {
  if ((n + k) % 2 || n <= k)
    return 1;
  int v = (n + k) / 2;
  return dfs(v) + dfs(v - k);
}

int main() {
  int n;
  cin >> n >> k;
  cout << dfs(n) << endl;
  return 0;
}