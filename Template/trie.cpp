struct Trie {
  int c[N][26], tot, v[N];
  void init() {
    while (tot) {
      v[tot] = 0;
      memset(c[tot], 0, sizeof(c[tot]));
      --tot;
    }
    memset(c[0], 0, sizeof(c[0]));
    v[0] = 0;
  }
  void insert(char s[], int len) {
    int now = 0;
    for (int i = 0; i < len; ++i) {
      int to = s[i] - 'a';
      if (!c[now][to])c[now][to] = ++tot;
      now = c[now][to];
    }
    v[now] = 1;
  }

  bool query(char s[], int len) {
    int now = 0;
    for (int i = 0; i < len; i ++ ) {
      int to = s[i] - 'a';
      if (!c[now][to])return 0;
      now = c[now][to];
    }
    return v[now];
  }

  // bool query(char s[], int len) {
  //   int now = 0;
  //   for (int i = len - 1; ~i; --i) {
  //     int to = s[i] - 'a';
  //     if (!c[now][to])return 0;
  //     now = c[now][to];
  //   }
  //   return v[now];
  // }
} A;
