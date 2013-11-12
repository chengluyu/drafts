#include <iostream>

using namespace std;

const int MAX = 1000 + 1;

struct size {
  int h, w;
  inline int sqr() {
    return h * w;
  }
} f[MAX][MAX];

int n, m, ans = 0;
char map[MAX][MAX] = { 0 };

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> map[i][j];

  bool left, up, leftup;
  int x, y;

  for (int i = 1; i <= n; ++i) // height
    for (int j = 1; j <= m; ++j) { //width
      if (map[i][j] == 'F') {
        left = map[i][j - 1] == 'F';
        up = map[i - 1][j] == 'F';
        leftup = map[i - 1][j - 1] == 'F';

        if (leftup && left && up) {
          f[i][j].w = f[i - 1][j - 1].w + 1;
          f[i][j].h = f[i - 1][j - 1].h + 1;
        } else if (left) {
          f[i][j].w = f[i][j - 1].w + 1;
          f[i][j].h = 1;
        } else if (up) {
          f[i][j].w = 1;
          f[i][j].h = f[i][j].h + 1;
        } else {
          f[i][j].w = 1;
          f[i][j].h = 1;
        }

        if (f[i][j].sqr() > ans) {
          ans = f[i][j].sqr();
          y = i;
          x = j;
        }
      } else {
        f[i][j].w = 0;
        f[i][j].h = 0;
      }
    }

  cout << ans * 3 << endl;
  cout << x << ' ' << y << endl;
  return 0;
}