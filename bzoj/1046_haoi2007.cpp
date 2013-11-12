/*
HAOI 2007
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

const int N = 10000 + 1;

int n, a[N] = { 0 }, dp[N] = { 0 };
int m, q, max_lis;

void lis() {
  vector<int> q;
  vector<int>::iterator pos;

  for (int i = n - 1; i >= 0; --i) {
    if (q.empty() || a[i] < q.back()) {
      q.push_back(a[i]);
      dp[i] = q.size();
    } else {
      pos = lower_bound(q.begin(), q.end(), a[i], greater<int>());
      *pos = a[i];
      dp[i] = distance(q.begin(), pos) + 1;
    }

    if (dp[i] > max_lis)
      max_lis = dp[i];
  }
}

void find_seq(int len) {
  int last = INT_MIN;

  for (int i = 0; i < n; ++i)
    if (dp[i] >= len && a[i] > last) {
      cout << a[i];

      if (len == 1) {
        cout << endl;
        break;
      } else {
        cout.put(' ');
        --len;
        last = a[i];
      }
    }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  lis();
  // for (int i = 0; i < n; ++i)
  //   cout << dp[i] << ' ';
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> q;
    if (q > max_lis)
      cout << "Impossible" << endl;
    else
      find_seq(q);
  }
  return 0;
}