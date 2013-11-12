#include <iostream>

using namespace std;

const int N = 10000000, SIZE = N + 1;

bool not_prime[SIZE] = { 0 };
int prime_count = 0, primes[SIZE], phi[SIZE];

int main() {
  phi[1] = 1;
  for (int i = 2; i <= N; ++i) {
    if (!not_prime[i]) {
      // sieve prime numbers
      primes[prime_count++] = i;
      // compute Euler's totient function
      phi[i] = i - 1;
    }
    for (int j = 0; j < prime_count && i * primes[j] <= N; ++j) {
      // sieve prime numbers
      not_prime[i * primes[j]] = true;
      // compute Euler's totient function
      if (i % primes[j])
        phi[i * primes[j]] = phi[i] * (primes[j] - 1);
      else {
        phi[i * primes[j]] = phi[i] * primes[j];
        break;
      }
    }
  }
  // output all prime numbers, using `primes` array does same matter
  for (int i = 2; i <= N; ++i)
    if (!not_prime[i])
      cout << i << ' ';
  cout << endl;
  return 0;
}