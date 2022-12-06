#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const int N = 2e5 + 10, M = 510;
const int MAXM = 1E6 + 10;
int n, m, block;
int belong[N], cnt[MAXM], a[N], ans[N], bl[N], br[N];
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
  int p, col;
} modify[N];

void add(int x) {
  ++ cnt[x];
  if (cnt[x] == 1) ++ ret;
}

void del(int x) {
  -- cnt[x];
  if (cnt[x] == 0) -- ret;
}

void update(int t, int now) {
  if (modify[t].p >= modui[now].l && modify[t].p <= modui[now].r) {
    add(modify[t].col);
    del(a[modify[t].p]);
  }
  swap(modify[t].col, a[modify[t].p]);
}

int query() {
  return ret;
}

int main() {
	ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m; block = 2500; belong[0] = 0;
	for(int i = 1; i <= n; i ++ ) {  cin >> a[i];  belong[i] = i / block;  } 
  belong[n + 1] = (n + 1) / block; belong[n + 2] = (n + 2) / block;
	for(int i = 1; i <= m; i ++ ) {
    char c; cin >> c;
    if (c == 'Q') {
      ++ m1;
      cin >> modui[m1].l >> modui[m1].r;
      modui[m1].pre = m2, modui[m1].id = m1;
    } else {
      ++ m2;
      cin >> modify[m2].p >> modify[m2].col;
    }
	}	

  for (int i = 0; i <= belong[n + 1]; i ++ ) {
    bl[i] = i * block;
    br[i] = bl[i] + block - 1;
  }
	  
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
    cout << ans[i] << "\n";
	}
	
  return 0;
}