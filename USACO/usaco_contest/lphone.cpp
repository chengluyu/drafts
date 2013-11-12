/*
USACO Contest JAN09 lphone
*/
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>

using namespace std;

const int N = 100 + 1;

enum { EMPTY, WALL, SOURCE, TARGET };

struct point {
  int x, y;
};

int w, h, map[N][N] = { 0 }, dist[N][N] = { 0 };
point s, t;
bool visited[N][N] = { 0 };

void set_map(int x, int y, char ch) {
  static bool set_source = false;
  switch (ch) {
    case '.':
      map[x][y] = EMPTY;
      break;
    case '*':
      map[x][y] = WALL;
      break;
    case 'C':
      if (set_source) {
        map[x][y] = TARGET;
        t.x = x;
        t.y = y;
      } else {
        map[x][y] = SOURCE;
        set_source = true;
        s.x = x;
        s.y = y;
      }
      break;
  }
}

int bfs() {
  queue<point> q;
  point p, now;

  q.push(s);
  visited[s.x][s.y] = true;
  dist[s.x][s.y] = 0;

  while (!q.empty()) {
    now = p = q.front();
    q.pop();

    // go up, decrease y
    while (--p.y >= 0) {
      if (map[p.x][p.y] == WALL)
        break;
      else if (!visited[p.x][p.y]) {
        visited[p.x][p.y] = true;
        dist[p.x][p.y] = dist[now.x][now.y] + 1;
        if (map[p.x][p.y] == TARGET)
          return dist[p.x][p.y];
        q.push(p);
      }
    }
    p = now;
    // go down, increase y
    while (++p.y < h) {
      if (map[p.x][p.y] == WALL)
        break;
      else if (!visited[p.x][p.y]) {
        visited[p.x][p.y] = true;
        dist[p.x][p.y] = dist[now.x][now.y] + 1;
        if (map[p.x][p.y] == TARGET)
          return dist[p.x][p.y];
        q.push(p);
      }
    }
    p = now;
    // go left, decrease x
    while (--p.x >= 0) {
      if (map[p.x][p.y] == WALL)
        break;
      else if (!visited[p.x][p.y]) {
        visited[p.x][p.y] = true;
        dist[p.x][p.y] = dist[now.x][now.y] + 1;
        if (map[p.x][p.y] == TARGET)
          return dist[p.x][p.y];
        q.push(p);
      }
    }
    p = now;
    // go left, increase x
    while (++p.x < w) {
      if (map[p.x][p.y] == WALL)
        break;
      else if (!visited[p.x][p.y]) {
        visited[p.x][p.y] = true;
        dist[p.x][p.y] = dist[now.x][now.y] + 1;
        if (map[p.x][p.y] == TARGET)
          return dist[p.x][p.y];
        q.push(p);
      }
    }
  }

  return dist[t.x][t.y];
}

int main() {
  char ch;

  cin >> w >> h;
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x) {
      cin >> ch;
      set_map(x, y, ch);
      dist[x][y] = INT_MAX; // really need this?
    }

  cout << bfs() << endl;

  // for (int y = 0; y < h; ++y) {
  //   for (int x = 0; x < w; ++x) {
  //     if (dist[x][y] == INT_MAX)
  //       cout << 'x' << ' ';
  //     else
  //       cout << dist[x][y] << ' ';
  //   }
  //   cout << endl;
  // }
  // for (int y = 0; y < h; ++y) {
  //   for (int x = 0; x < w; ++x) {
  //     cout << map[x][y] << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << "source: " << s.x << ' ' << s.y << endl;
  // cout << "target: " << t.x << ' ' << t.y << endl;
  return 0;
}