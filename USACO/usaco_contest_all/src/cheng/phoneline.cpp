#include <algorithm>
#include <iostream>
#define PID "phoneline"

using namespace std;

const int V = 1000 + 1, P = (10000 + 1) * 2;

struct edge {
  int a, b, l;
  edge * next;
  static edge data[P];
};

inline void * operator new(size_t size) {
  static int curr = 0;
  return reinterpret_cast<void *>(edge::data + (curr ++));
}

edge * first[V] = { 0 };

inline void insert_single_edge(int a, int b, int l) {
  edge * e = new edge;
  e->a = a;
  e->b = b;
  e->l = l;
  e->next = first[a];
  first[a] = e;
}

void insert_edge(int a, int b, int l) {
  insert_single_edge(a, b, l);
  insert_single_edge(b, a, l);
}

// test spfa

int main() {
  cin >> n >> p >> k;
  int u, v, w;
  for (int i = 0; i < n; ++i) {
    cin >> u >> v >> w;
    insert_edge(u, v, w);
  }
  
  return 0;
}

