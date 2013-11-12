#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 100000 + 1;

int n, a[N] = { 0 }, dp[N] = { 0 };

int max_lis() {
  int ans = 0;

  vector<int> q;
  vector<int>::iterator pos;

  for (int i = 0; i < n; ++i) {
    if (q.empty() || a[i] > q.back()) {
      q.push_back(a[i]);
      dp[i] = q.size();
    } else {
      pos = lower_bound(q.begin(), q.end(), a[i]);
      *pos = a[i];
      dp[i] = pos - q.begin() + 1;
    }
    if (dp[i] > ans)
      ans = dp[i];
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  cout << n - lis() << endl;
  return 0;
}