// #define int __int128

namespace io {
  constexpr int BUFFER_SIZE = 1 << 16;
  char buffer[BUFFER_SIZE], *head, *tail;

  char get_char() {
    if (head == tail) {
      int l = (int) fread(buffer, 1, BUFFER_SIZE, stdin);
      tail = (head = buffer) + l;
    }
    return *head++;
  }

  __int128 read() {
    __int128 x = 0, f = 1;
    char c = get_char();
    for (; !isdigit(c); c = get_char())
      if (c == '-') f = -1;
    for (; isdigit(c); c = get_char()) x = x * 10 + c - '0';
    return x * f;
  }

  void print(__int128 x) {
    if(x < 0) x = -x, putchar('-');
    constexpr long long P = 1E18;
    if(x < P) {
      cout << ll(x) << " ";
    } else {
      cout << ll(x / P) << setw(18) << setfill('0') << ll(x % P) << " ";
    }
  }

  void println(__int128 x) { print(x), putchar('\n'); }

  __int128 sqrt(__int128 x) {
    __int128 l = 0, r = (__int128)10000000000000; 
    while(l < r) {
      __int128 mid = (l + r + 1) / 2;
      if(mid * mid > x) r = mid - 1;
      else l = mid;
    }
    return l;
  }

}  // namespace io

using namespace io;

