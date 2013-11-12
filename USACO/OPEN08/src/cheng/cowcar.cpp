#include <algorithm>
#include <fstream>

using namespace std;

#define PID "cowcar"
ifstream cin(PID ".in");
ofstream cout(PID ".out");

const int N = 50000 + 1;

int n, m, d, l, ans = 0;
int s[N] = { 0 }, ks[N] = { 0 };

int main() {
  cin >> n >> m >> d >> l;
  for (int i = 0; i < n; ++i)
    cin >> s[i];
  
  sort(s, s + n);
  
  int total = 0;
  for (int i = 0; i < n; ++i)
    if (s[i] - d * (total / m) >= l)
      ++total;
  
  cout << total << endl;
  return 0;
}
/*
3 1 1 5
5
7
5
*/
