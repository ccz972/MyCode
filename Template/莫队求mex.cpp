#include <bits/stdc++.h>
using namespace std;
using LL = long long;
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

const int N = 2e5 + 10, M = 510;

int n, m, block;
int belong[N], cnt[N], a[N], ans[N], tot[N], bl[N], br[N];

struct node {
	int l, r, id;
	bool operator < (const node &T) const {
    return belong[l] ^ belong[T.l] ? belong[l] < belong[T.l] : ((belong[l] & 1) ? r < T.r : r > T.r);
	}
} modui[N];

void add(int x) {
  if (!cnt[x]) tot[belong[x]] ++;
  cnt[x] ++;
}

void del(int x) {
  if (cnt[x] == 1) tot[belong[x]] --;
  cnt[x] --; 
}
//值域分块 每次查询sqrt(n)
int query() {
  int now = 0;
  while (tot[now] == br[now] - bl[now] + 1) ++ now;
  for (int i = bl[now]; i <= br[now]; i ++ ) {
    if (!cnt[i]) return i;
  }
  return -1;
}

int main() {
	
	n = read(); m = read(); block = sqrt(n); // 0, ...
  belong[0] = 0;
	for(int i = 1; i <= n; i ++ ) { a[i] = min(read(), n + 1); belong[i] = i / block; } 
  belong[n + 1] = (n + 1) / block; belong[n + 2] = (n + 2) / block;
	for(int i = 1; i <= m; i ++ ) {
    modui[i].l = read(), modui[i].r = read(); modui[i].id = i;
	}	

  for (int i = 0; i <= belong[n + 1]; i ++ ) {
    bl[i] = i * block;
    br[i] = bl[i] + block - 1;
  }
	  
	sort(modui + 1, modui + 1 + m);
	int lal = modui[1].l, lar = modui[1].l - 1;
	for(int i = 1; i <= m; i ++ ) {
		int l = modui[i].l, r = modui[i].r;
		while(lal > l) lal --, add(a[lal]);
		while(lar < r) lar ++, add(a[lar]);
		while(lal < l) del(a[lal]), lal ++;
		while(lar > r) del(a[lar]), lar --;
		ans[modui[i].id] = query();
	}
	for(int i = 1; i <= m; i ++ ) {
    println(ans[i]);
	}
	
  return 0;
}