#include <iostream>

using namespace std;

int main() {
  cout << "sizeof short = " << sizeof (short) << endl;
  cout << "sizeof int = " << sizeof (int) << endl;
  cout << "sizeof long = " << sizeof (long) << endl;
  cout << "sizeof long long = " << sizeof (long long) << endl;
  cout << "sizeof pointer = " << sizeof (void *) << endl;
  cout << "sizeof float = " << sizeof (float) << endl;
  cout << "sizeof double = " << sizeof (double) << endl;
  cout << "sizeof long double = " << sizeof (long double) << endl;
  return 0;
}

/*
genearted result on my ubuntu (64 bit) computer:
sizeof short = 2
sizeof int = 4
sizeof long = 8
sizeof long long = 8
sizeof pointer = 8
sizeof float = 4
sizeof double = 8
sizeof long double = 16
*/