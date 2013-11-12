#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;

#define PID "catchcow"
ifstream cin(PID ".in");
ofstream cout(PID ".out");

const int N = 100000;

inline bool in_limit(int x) {
  return 0 <= x && x <= 100000;
}

bool visited[N + 1] = { 0 };
int dist[N + 1] = { 0 };

int main() {
  int s, t, ans = -1;
  cin >> s >> t;

  queue<int> q;

  q.push(s);
  visited[s] = true;
  dist[s] = 0;

  while (!q.empty()) {
    int p = q.front();
    q.pop();

    if (p == t) {
      ans = dist[p];
      break;
    }

    if (in_limit(p + 1) && !visited[p + 1]) {
      visited[p + 1] = true;
      dist[p + 1] = dist[p] + 1;
      q.push(p + 1);
    }

    if (in_limit(p - 1) && !visited[p - 1]) {
      visited[p - 1] = true;
      dist[p - 1] = dist[p] + 1;
      q.push(p - 1);
    }

    if (in_limit(p * 2) && !visited[p * 2]) {
      visited[p * 2] = true;
      dist[p * 2] = dist[p] + 1;
      q.push(p * 2);
    }
  }

  cout << ans << endl;
  return 0;
}