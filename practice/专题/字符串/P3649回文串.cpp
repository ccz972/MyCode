#include <bits/stdc++.h>

using namespace std;


struct PAM {
  int n, tot, last, cur;
  // int cnt[maxn], len[maxn], fail[maxn], son[maxn][27];
  vector<int> cnt, len, fail;
  vector<vector<int> > son;
  string s;
  //动态开点
  int new_node(int x) {
    len[tot] = x;
    cnt[tot] = 0;
    // cout << tot << "\n";
    return tot++;
  }
  int get_fail(int x, int n) {
    while (s[n - len[x] - 1] != s[n]) x = fail[x];
    return x;
  }
  void init(string ss, int nn) {
    // scanf("%s", s + 1);
    s = " " + ss; // t 用来哈希, s 用来 PAM
    n = nn;
    cnt.resize(n + 10);
    len.resize(n + 10);
    fail.resize(n + 10);
    son.resize(n + 10);
    for(int i = 0; i < n + 10; i ++ ) son[i].resize(27);
    tot = 0;
    new_node(0);
    new_node(-1);
    fail[0] = 1;
    last = 0;
  }
  void build() {
    // Hash H(t); // 用来哈希
    for (int i = 1; i <= n; i++) {
      int x = s[i] - 'a';
      cur = get_fail(last, i);
      if (!son[cur][x]) {
        int nw = new_node(len[cur] + 2);
        fail[nw] = son[get_fail(fail[cur], i)][x];
        son[cur][x] = nw;
      }
      last = son[cur][x];
      cnt[last]++;
      // printf("%c %d %d\n", s[i], i, len[last];
      //以 i 结尾，并且长度为 len[last] 的回文串
      // 回文串 [i - len[last] + 1, i]
            
    }
  }

  long long gen() { 
    //由于每个cnt[last]都为1(or 0)，如果要求每个回文串在整个字符串中出现的次数，需要求一下前缀和
    for (int i = tot - 1; i >= 0; i -- ) {
      cnt[fail[i]] += cnt[i];
    } 
    long long ans = 0;
    for (int i = 0; i < tot; i ++ ) {
      // cout << cnt[i] << " " << len[i] << "\n";
      ans = max(ans, 1ll * len[i] * cnt[i]);
    }
    return ans;
    // 此时 cnt[idx] 表示 idx 这个节点所代表的回文串的个数
    // 如果还要知道每个 idx 所表示的字符串是什么，
    // 可以使用 map[Hash.get(i - len[last] + 1, i)] = idx，通过遍历然后 idx = cnt[idx] 即可
  }

} pam;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s; cin >> s;
  pam.init(s, (int)s.size());
  pam.build();
  cout << pam.gen();
  // pam.build();
  
  return 0;
}