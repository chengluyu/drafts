#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int p1, p2, p3;

char put(char ch) {
  if (p1 == 3)
    cout.put('*');
  else if ('a' <= ch && ch <= 'z') {
    cout.put(p1 == 1 ? ch : (ch - 'a' + 'A'));
  } else if ('A' <= ch && ch <= 'Z') {
    cout.put(p1 == 1 ? (ch - 'A' + 'a') : ch);
  } else
    cout.put(ch);
}

void parse() {
  char ch, left, right;

  while (cin.peek() != char_traits<char>::eof()) {
    ch = cin.get();

    if (cin.peek() == '-') {
      cin.ignore();
      left = ch;
      right = cin.get();

      cout.put(left);

      if (left + 1 == right)
        ;
      else if (left >= right) {
        cout.put('-');
      } else if (p3 == 1) {
        while (++left < right) {
          for (int i = 0; i < p2; ++i)
            put(left);
        }
      } else if (p3 == 2) {
        char t = right;
        while (--t > left) {
          for (int i = 0; i < p2; ++i)
            put(t);
        }
      }

      cout.put(right);

    } else {
      cout.put(ch);
    }
  }
}

int main() {
  cin >> p1 >> p2 >> p3;
  while (cin.peek() != '\n')
    cin.ignore();
  cin.ignore();
  parse();
  return 0;
}