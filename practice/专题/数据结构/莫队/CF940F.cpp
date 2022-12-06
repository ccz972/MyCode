#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

const int N = 2e5 + 100, M = 510; //
const int MAXM = 2E5 + 10;
int n, m, block;
int belong[N], cnt[N], tot[N], num[N], a[N], b[N], ans[N], bl[N], br[N];
//block = n / (sqrt(2m /3 )) + 1
int m1, m2, ret;
struct node1 {
	int l, r, pre, id;
	bool operator < (const node1 &T) const {
    if (belong[l] != belong[T.l]) return belong[l] < belong[T.l];
    if (belong[r] != belong[T.r]) {
      if (belong[l] & 1) return belong[r] < belong[T.r];
      else return belong[r] > belong[T.r];
    } else {
      return (belong[r] & 1) ? pre < T.pre : pre > T.pre;
    }
	}
} modui[N];

struct node2 {
  int idx, val;
} modify[N];


void add(int x) {
  if (num[cnt[x]] == 1) tot[belong[cnt[x]]] --;
  if (num[cnt[x]]) num[cnt[x]] --;
  ++ cnt[x];
  num[cnt[x]] ++;
  if (num[cnt[x]] == 1) tot[belong[cnt[x]]] ++;
}

void del(int x) { 
  //cnt[x]表示x出现的次数
  //
  if (num[cnt[x]] == 1) tot[belong[cnt[x]]] --;
  if (num[cnt[x]]) num[cnt[x]] --;
  
  -- cnt[x];
  num[cnt[x]] ++;
  if (num[cnt[x]] == 1) tot[belong[cnt[x]]] ++;
  
}

void update(int t, int now) {
  if (modify[t].idx >= modui[now].l && modify[t].idx <= modui[now].r) {
    add(modify[t].val);
    del(a[modify[t].idx]);
  }
  swap(modify[t].val, a[modify[t].idx]);
}

int query() {
  int now = 0;
  while (tot[now] == br[now] - bl[now] + 1) ++ now;
  for (int i = bl[now]; i <= br[now]; i ++ ) {
    if (!num[i]) return i;
  }
  return -1;
}

int main() {
  //easy
  n = read(), m = read(); block = 2700; belong[0] = 0;
  
	for(int i = 1; i <= n; i ++ ) {  a[i] = read(); b[i] = a[i];  belong[i] = i / block;  } 

  int nn = n;
  for (int i = n + 1; i <= n * 2 + 10; i ++ ) {
    belong[i] = i / block;
  }

	for(int i = 1; i <= m; i ++ ) {
    int op = read();
    if (op == 1) {
      ++ m1;
      modui[m1].l = read(), modui[m1].r = read();
      modui[m1].pre = m2, modui[m1].id = m1;
    } else {
      ++ m2;
      modify[m2].idx = read(), modify[m2].val = read();
      b[++ nn] = modify[m2].val;
    }
	}	

  sort(b + 1, b + 1 + nn);
  nn = unique(b + 1, b + 1 + nn) - b;

  for (int i = 1; i <= n; i ++ ) {
    a[i] = lower_bound(b + 1, b + 1 + nn, a[i]) - b;
  }

  for (int i = 1; i <= m2; i ++ ) {
    modify[i].val = lower_bound(b + 1, b + 1 + nn, modify[i].val) - b;
  }

  for (int i = 0; i <= belong[n + 1]; i ++ ) {
    bl[i] = i * block;
    br[i] = bl[i] + block - 1;
  }

  bl[0] = 1;
	  
	sort(modui + 1, modui + 1 + m1);

	int lal = modui[1].l, lar = modui[1].l - 1, ti = 0;
	for(int i = 1; i <= m1; i ++ ) {
		int l = modui[i].l, r = modui[i].r, pre = modui[i].pre;
		while(lal > l) lal --, add(a[lal]);
		while(lar < r) lar ++, add(a[lar]);
		while(lal < l) del(a[lal]), lal ++;
		while(lar > r) del(a[lar]), lar --;
    while (ti < pre) update(++ ti, i);
    while (ti > pre) update(ti --, i);
		ans[modui[i].id] = query();
	}
	for(int i = 1; i <= m1; i ++ ) {
    println(ans[i]);
	}
	
  return 0;
}