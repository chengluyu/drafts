#include <algorithm>
#include <climits>
#include <fstream>

using namespace std;

const int N = 1000 + 1;

struct work {
  int t, s;
  bool operator< (const work & rhs) const {
    return s < rhs.s;
  }
} w[N];

#define PID "mtime"
ifstream cin(PID ".in");
ofstream cout(PID ".out");

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> w[i].t >> w[i].s;
  
  sort(w, w + n);
  
  int last = INT_MAX;
  
  for (int i = n - 1; i >= 0; --i) {
    if (w[i].s < last)
      last = w[i].s;
    last -= w[i].t;
  }
  
  cout << (last < 0 ? -1 : last) << endl;
  
  return 0;
}
/*
4
3 5
8 14
5 20
1 16
*/
