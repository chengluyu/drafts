#include <algorithm>
#include <vector>

using namespace std;

template <typename InputIt, typename Compare = std::less>
size_t subseq(InputIt first, InputIt last, Compare comp = Compare()) {
#if __cplusplus < 201103L
#define TYPEOF __typeof
#else
#define TYPEOF decltype
#endif
  size_t length = std::distance(first, last), i = 0;

  vector<TYPEOF(*first)> s;
  vector<size_t> f(length);

  InputIt it = first;

  while (it != last) {
    if (s.empty() || comp(s.back()), *it) {
      s.push_back(*it);

    }
    ++i;
  }

#undef TYPEOF
}