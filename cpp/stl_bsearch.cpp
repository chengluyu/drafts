#include <algorithm>
#include <array>
#include <functional>
#include <iostream>

using namespace std;

int main() {
  array<int, 6> a = { 0, 2, 2, 2, 5, 6 };
  array<int, 6>::iterator lb = lower_bound(a.begin(), a.end(), 2),
      ub = upper_bound(a.begin(), a.end(), 2),
      lbc = lower_bound(a.begin(), a.end(), 2, less_equal<int>());
  for (int v : a)
    cout << v << ' ';
  cout << endl;
  cout << distance(a.begin(), lb) << endl
       << distance(a.begin(), ub) << endl
       << distance(a.begin(), lbc) << endl;
  return 0;
}