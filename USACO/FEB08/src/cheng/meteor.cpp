#include <climits>
#include <iostream>
#include <queue>

using namespace std;

const int N = 300 + 2;

bool visited[N][N] = { 0 };
int m, t[N][N] = { 0 }, d[N][N] = { 0 };

struct point {
  int x, y;
  point(int _x, int _y) : x(_x), y(_y) { }
};

void bfs() {
  queue<point> q;
  
  q.push(point(0, 0));
  visited[0][0] = true;
  
  while (!q.empty()) {
    
  }
}

inline void destroy(int x, int y, int v) {
  if (0 <= x && x < N && 0 <= y && y < N) {
    t[x][y] = v;
  }
}

int main() {
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) {
      t[i][j] = 0;
      d[i][j] = -1;
    }
  cin >> m;
  int x, y, v;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y >> v;
    destroy(x, y, v);
    destroy(x - 1, y, v);
    destroy(x + 1, y, v);
    destroy(x, y - 1, v);
    destroy(x, y + 1, v);
  }
  
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 20; ++j)
      cout << t[i][j] << ' ';
    cout << endl; 
  }
  return 0;
}

/*
4
0 0 2
2 1 2
1 1 2
0 3 5
*/
