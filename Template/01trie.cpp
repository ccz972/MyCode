//�ϸ�� 

#include <bits/stdc++.h>
using namespace std;

struct Trie {
  int nxt[N * 31][2], tot, v[N * 31];
  void init() {
    while (tot >= 0) {
      nxt[tot][0] = nxt[tot][1] = 0;
      -- tot;
    }
    tot = 0;
  }
  void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i -- ) {
      int &s = nxt[p][x >> i & 1];
      if (!s) s = ++ tot;
      p = s;
    }
  }

};


void init() {
  nxt[0][0] = nxt[0][1] = 0;
  cnt = 1;
}

void add(int n) {
  int cur = 0;
  for (int i = MAXBIT; i >= 0; --i) {
    int bit = (n >> i) & 1;       
    if (!nxt[cur][bit]) {
      nxt[cnt][0] = nxt[cnt][1] = 0;
      nxt[cur][bit] = cnt++;
    }
    cur = nxt[cur][bit];
  }
  val[cur] = n;
}

//yxc
const int N = 100010, M = 3100010;

int n;
int a[N], son[M][2], idx;

void insert(int x) {
  int p = 0;
  for (int i = 30; i >= 0; i -- ) {
    int &s = son[p][x >> i & 1];
    if (!s) s = ++ idx;
    p = s;
  }
}

int search(int x) {
  int p = 0, res = 0;
  for (int i = 30; i >= 0; i -- ) {
    int s = x >> i & 1;
    if (son[p][!s]) {
      res += 1 << i;
      p = son[p][!s];
    }
    else p = son[p][s];
  }
  return res;
}

