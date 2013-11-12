#include <fstream>

using namespace std;

#define PID "wordpow"
ifstream cin(PID ".in");
ofstream cout(PID ".out");

const int N = 1000 + 1, M = 100 + 1;

string cow_names[N], power_names[M];
int n, m, power[N] = { 0 };

void lowercase(string & str) {
  for (size_t i = 0; i < str.size(); ++i)
    if ('A' <= str[i] && str[i] <= 'Z')
      str[i] = str[i] - 'A' + 'a';
}

bool match(const string & str, const string & sub) {
  int k = 0;
  for (size_t i = 0; i < str.size(); ++i)
    if (str[i] == sub[k])
      if (++k == sub.size())
        return true;
  return k == sub.size();
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> cow_names[i];
    lowercase(cow_names[i]);
  }
  for (int i = 0; i < m; ++i) {
    cin >> power_names[i];
    lowercase(power_names[i]);
  }
  
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (match(cow_names[i], power_names[j]))
        ++power[i];
  
  for (int i = 0; i < n; ++i) {
    cout << power[i] << endl;
  }
  return 0;
}
/*
5 3
Bessie
Jonathan
Montgomery
Alicia
Angola
se
nGo
Ont
*/
