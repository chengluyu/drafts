#include <algorithm>
#include <iostream>

using namespace std;

const int N = 50000;

int n, a[N], sum = 0;
bool is_prime[N + 1] = { 0 };

int gcd(int a, int b) {
  return 
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }

  fill(is_prime, is_prime + n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= 223; ++i)
    for (int j = i + i; j <= 50000; j += i)
      is_prime[N] = false;

  for (int i = 0; i < n; )

  return 0;
}