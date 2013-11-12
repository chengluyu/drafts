#include <cmath>
#include <climits>
#include <fstream>

using namespace std;

const int N = 1050 + 1;
const double INIT_SPEED = 10000;

#define PID "baler"
ifstream cin(PID ".in");
ofstream cout(PID ".out");

struct gear {
  int x, y, r;
  double s;
} gears[N];
bool visited[N] = { 0 };
int n, start = -1, xt, yt, ans = 0;

inline int sqr(int x) {
  return x * x;
}

void dfs(int k, double d) {
  if (gears[k].x == xt && gears[k].y == yt)
    ans = d;
  for (int i = 0; i < n; ++i)
    if (!visited[i])
      if (sqr(gears[i].x - gears[k].x) + sqr(gears[i].y - gears[k].y) ==
          sqr(gears[i].r + gears[k].r)) {
        visited[i] = true;
        gears[i].s = -gears[k].s * gears[k].r / gears[i].r;
        dfs(i, d + fabs(gears[i].s));
      }
}

int main() {
  cin >> n >> xt >> yt;
  for (int i = 0; i < n; ++i) {
    cin >> gears[i].x >> gears[i].y >> gears[i].r;
    //visited[i] = false;
    if (gears[i].x == 0 && gears[i].y == 0)
      start = i;
  }

  if (start == -1)
    return 1;

  gears[start].s = INIT_SPEED;
  visited[start] = true;
  dfs(start, INIT_SPEED);

  cout << ans << endl;
  return 0;
}
/*
4 32 54
0 0 10
0 30 20
32 54 20
-40 30 20
*/

