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

  void print(long long x) {
    static int sta[1997];
    int top = 0;
    do {
      sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
  }

  void println(long long x) { print(x), putchar('\n'); }
}  // namespace io
using namespace io;

const int N = 3e4 + 10, M = 1E5 + 10;
int n, m, k, block;
int lal = 1, lar = 0;
int bl[N], a[N], b[N];
int num[N];
long long ans[M], sum;
map<int, int> mp;

struct node {
	int l, r, id;
	bool operator < (const node &T) const {
    return bl[l] ^ bl[T.l] ? bl[l] < bl[T.l] : ((bl[l] & 1) ? r < T.r : r > T.r);
	}
} modui[M];

void add(int x) {
  num[b[x]] ++;
  if (num[b[x]] == 1) sum += a[x];
}

void del(int x) {
  num[b[x]] --;
  if (!num[b[x]]) sum -= a[x];
}


void solve() {
  n = read(); block = sqrt(n);
  vector<int> all;
	for(int i = 1; i <= n; i ++ ) { a[i] = read(); all.emplace_back(a[i]); bl[i] = (i - 1) / block; } 
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  for (int i = 1; i <= n; i ++ ) {
    b[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
  }
  
  m = read();
	for(int i = 1; i <= m; i ++ ) {
    modui[i].l = read(), modui[i].r = read(); modui[i].id = i;
	}	
	
	sort(modui + 1, modui + 1 + m);
	
	for(int i = 1; i <= m; i ++ ) {
		int l = modui[i].l, r = modui[i].r;
		while(lal > l) lal --, add(lal);
		while(lar < r) lar ++, add(lar);
		while(lal < l) del(lal), lal ++;
		while(lar > r) del(lar), lar --;
		ans[modui[i].id] = sum;
	}
  
	for(int i = 1; i <= m; i ++ ) {
    println(ans[i]);
	}

  mp.clear();
  sum = 0;
  lar = lal = 0;
  for (int i = 1; i <= n; i ++ ) num[i] = 0;
}

int main() {
	int T = read();
  while (T -- ) solve();
	
  
	
  return 0;
}