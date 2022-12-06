#include <bits/stdc++.h>
using namespace std;
using LL = long long;
// #define int __int128
namespace io {
constexpr int BUFFER_SIZE = 1 << 16;
char buffer[BUFFER_SIZE], *head, *tail;

char get_char() {
  if (head == tail) {
    int l = (int)fread(buffer, 1, BUFFER_SIZE, stdin);
    tail = (head = buffer) + l;
  }
  return *head++;
}

int read() {
  int x = 0, f = 1;
  char c = get_char();
  for (; !isdigit(c); c = get_char())
    if (c == '-') f = -1;
  for (; isdigit(c); c = get_char()) x = x * 10 + c - '0';
  return x * f;
}

void print(int x) {
  static int sta[1997];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}

void println(int x) { print(x), putchar('\n'); }
}  // namespace io
using namespace io;

const int N = 5e5 + 10, M = 510;
int n, m, k, block;
int lal = 1, lar = 0;
int bl[N], cnt[N], a[N];
LL ans[N], sum;
int id[N], stk[N], idx;

struct node {
  int l, r, id;
  bool operator<(const node &T) const {
    return bl[l] ^ bl[T.l] ? bl[l] < bl[T.l]
                           : ((bl[l] & 1) ? r < T.r : r > T.r);
  }
} modui[N];

void add(int x) {
  cnt[x]++;
  if (not(cnt[x] ^ 1)) {
    stk[++idx] = x;
    id[x] = idx;
  } else if (not(cnt[x] ^ 2)) {
    stk[id[x]] = stk[idx];  //将x清空，即将栈顶元素移动到 x 的位置
    id[stk[idx]] = id[x];  //将栈顶元素的 id 置为 x 的 id
    --idx;
  }
}

void del(int x) {
  cnt[x]--;
  if (not(cnt[x] ^ 1)) {
    stk[++idx] = x;
    id[x] = idx;
  } else if (!cnt[x]) {
    stk[id[x]] = stk[idx];
    id[stk[idx]] = id[x];
    --idx;
  }
}

int main() {
  n = read();
  block = sqrt(n);
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    bl[i] = (i - 1) / block;
  }
  m = read();
  for (int i = 1; i <= m; i++) {
    modui[i].l = read(), modui[i].r = read();
    modui[i].id = i;
  }

  sort(modui + 1, modui + 1 + m);

  for (int i = 1; i <= m; i++) {
    int l = modui[i].l, r = modui[i].r;
    while (lal > l) lal--, add(a[lal]);
    while (lar < r) lar++, add(a[lar]);
    while (lal < l) del(a[lal]), lal++;
    while (lar > r) del(a[lar]), lar--;
    ans[modui[i].id] = stk[idx];
  }
  for (int i = 1; i <= m; i++) {
    println(ans[i]);
  }

  return 0;
}