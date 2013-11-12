#include <iostream>
#include <map>
#include <queue>

using namespace std;

typedef unsigned int cb_t;

/*
EMPTY 00
BLACK 01
WHITE 10
RESERVE 11
*/

bool is_target(cb_t cb) {
  const cb_t mask[20] = {
    0x55000000,
    0x00550000,
    0x00005500,
    0x00000055,
    0xAA000000,
    0x00AA0000,
    0x0000AA00,
    0x000000AA,
    0x40404040,
    0x10101010,
    0x04040404,
    0x01010101,
    0x80808080,
    0x20202020,
    0x08080808,
    0x02020202,
    0x40100401,
    0x80200802,
    0x01041040,
    0x02082080
  };
  for (int i = 0; i < 20; ++i)
    if (cb & mask[i] == mask[i])
      return true;
  return false;
}


cb_t make_cb() {
  cb_t res = 0;
  char ch;
  for (int i = 0; i < 16; ++i) {
    cin >> ch;
    res <<= 2;
    if (ch == 'W')
      res |= 2;
    else if (ch == 'B')
      res |= 1;
    else
      res |= 0;
  }
  return res;
}

int main() {
  cb_t s = make_cb();

  queue<cb_t> q;
  map<cb_t, int> step;

  q.push(s);
  step[s] = 0;

  while (!q.empty()) {
    cb_t c = q.top(), mask = 0xFF;

    if (is_target(c)) {
      cout << step[c] << endl;
      break;
    }

    for (int i = 0; i < 16; ++i, mask <<= 2)
      if (c & mask == 0x00) {

      }

    q.pop();
  }
  return 0;
}

/*
00 00 00 00
00 00 00 00
00 00 00 00
00 00 00 00
*/