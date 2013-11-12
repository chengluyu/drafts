#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, long long> num, base;

int main() {
  ios::sync_with_stdio(false);
  num["zero"] = 0;
  num["one"] = 1;
  num["two"] = 2;
  num["three"] = 3;
  num["four"] = 4;
  num["five"] = 5;
  num["six"] = 6;
  num["seven"] = 7;
  num["eight"] = 8;
  num["nine"] = 9;
  num["ten"] = 10;
  num["eleven"] = 11;
  num["twelve"] = 12;
  num["thirteen"] = 13;
  num["fourteen"] = 14;
  num["fifteen"] = 15;
  num["sixteen"] = 16;
  num["seventeen"] = 17;
  num["eighteen"] = 18;
  num["nineteen"] = 19;
  num["twenty"] = 20;
  num["thirty"] = 30;
  num["forty"] = 40;
  num["fifty"] = 50;
  num["sixty"] = 60;
  num["seventy"] = 70;
  num["eighty"] = 80;
  num["ninety"] = 90;
  base["hundred"] = 100;
  base["thousand"] = 1000;
  base["million"] = 1000000;
  long long val = 0;
  string str;
  bool negative = false;
  unordered_map<string, long long>::iterator it, it2;

  cin >> str;
  if (str == "negative") {
    negative = true;
    cin >> str;
  }

  while (cin) {
    it = num.find(str);
    if (it == num.end())
      break;

    cin >> str;
    it2 = base.find(str);
    if (it2 == num.end())
      val += it->second;
    else
      val += it->second * it2->second;
  }

  cout << (negative ? -val : val);
  return 0;
}