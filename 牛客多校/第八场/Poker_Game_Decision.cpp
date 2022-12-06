// #pragma GCC optimize(3)
// #pragma GCC target("avx")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-fhoist-adjacent-loads")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")
// #pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;

#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// map<char, int> mp;
int mp[1000];
// vector<int> ret[10];
int cnt0, cnt1;

int check(vector<string> a, vector<string> b) {
  sort(a.begin(), a.end(), [&](string x, string y) {
    if(mp[x[0]] != mp[y[0]]) return mp[x[0]] < mp[y[0]];
    return x[1] < y[1];
  });
  sort(b.begin(), b.end(), [&](string x, string y) {
    if(mp[x[0]] != mp[y[0]]) return mp[x[0]] < mp[y[0]];
    return x[1] < y[1];
  });
  
  //按照数字排序，花色从小到大

  bool shunzi_a = true, shunzi_b = true;

  for(int i = 1; i < 5; i ++ ) {
    if(mp[a[i][0]] != mp[a[i - 1][0]] + 1) {
      shunzi_a = false;
    }
  }

  for(int i = 1; i < 5; i ++ ) {
    if(mp[b[i][0]] != mp[b[i - 1][0]] + 1) {
      shunzi_b = false;
    }
  }

  string s = "2345A";

  if(shunzi_a == false) {
    bool flag = true;
    for(int i = 0; i < 5; i ++ ) {
      if(a[i][0] != s[i]) {
        flag = false;
      }
    }
    shunzi_a = flag;
  }

  if(shunzi_b == false) {
    bool flag = true;
    for(int i = 0; i < 5; i ++ ) {
      if(b[i][0] != s[i]) {
        flag = false;
      }
    }
    shunzi_b = flag;
  }
  
  //
  bool same_a = true, same_b = true;

  for(int i = 1; i < 5; i ++ ) {
    if(a[i][1] != a[0][1]) same_a = false;
  }  

  for(int i = 1; i < 5; i ++ ) {
    if(b[i][1] != b[0][1]) same_b = false;
  }  

  bool four_a = (a[0][0] == a[3][0]) | (a[1][0] == a[4][0]);
  bool four_b = (b[0][0] == b[3][0]) | (b[1][0] == b[4][0]);

  // debug([0]a, b[0][0]);
  bool full_a = (a[0][0] == a[1][0] && a[2][0] == a[4][0]) | (a[0][0] == a[2][0] && a[3][0] == a[4][0]);
  bool full_b = (b[0][0] == b[1][0] && b[2][0] == b[4][0]) | (b[0][0] == b[2][0] && b[3][0] == b[4][0]);


  bool flush_a = same_a;
  bool flush_b = same_b;


  bool three_a = false, three_b = false;

  for(int i = 0; i + 2 < 5; i ++ ) {
    if(a[i][0] == a[i + 2][0]) {
      three_a = true;
    }
  }
  
  for(int i = 0; i + 2 < 5; i ++ ) {
    if(b[i][0] == b[i + 2][0]) {
      three_b = true;
    }
  }

  bool two_pair_a = false, two_pair_b = false;
  
  for(int i = 0; i < 2; i ++ ) {
    for(int j = i + 1; j < 3; j ++ ) if(a[i][0] == a[j][0]) {
      for(int k = j + 1; k < 4; k ++ ) {
        for(int l = k + 1; l < 5; l ++ ) {
          if(a[k][0] == a[l][0]) {
            two_pair_a = true;
          }
        }
      }
    }
  }
  //1234
  for(int i = 0; i < 2; i ++ ) {
    for(int j = i + 1; j < 3; j ++ ) if(b[i][0] == b[j][0]) {
      for(int k = j + 1; k < 4; k ++ ) {
        for(int l = k + 1; l < 5; l ++ ) {
          if(b[k][0] == b[l][0]) {
            two_pair_b = true;
          }
        }
      }
    }
  }


  bool pair_a = false, pair_b = false;

  for(int i = 0; i < 4; i ++ ) {
    if(a[i][0] == a[i + 1][0]) pair_a = true;
    if(b[i][0] == b[i + 1][0]) pair_b = true;
  }

  int rank_a = -1, rank_b = -1;

  if(shunzi_a && same_a && a[0][0] == 'T') {
    rank_a = 10;
  } else if(shunzi_a && same_a) {
    rank_a = 9;
  } else if(four_a) {
    rank_a = 8;
  } else if(full_a) {
    rank_a = 7;
  } else if(flush_a) {
    rank_a = 6;
  } else if(shunzi_a) {
    rank_a = 5;
  } else if(three_a) {
    rank_a = 4;
  } else if(two_pair_a) {
    rank_a = 3;
  } else if(pair_a) {
    rank_a = 2;
  } else {
    rank_a = 1;
  }

  if(shunzi_b && same_b && b[0][0] == 'T') {
    rank_b = 10;
  } else if(shunzi_b && same_b) {
    rank_b = 9;
  } else if(four_b) {
    rank_b = 8;
  } else if(full_b) {
    rank_b = 7;
  } else if(flush_b) {
    rank_b = 6;
  } else if(shunzi_b) {
    rank_b = 5;
  } else if(three_b) {
    rank_b = 4;
  } else if(two_pair_b) {
    rank_b = 3;
  } else if(pair_b) {
    rank_b = 2;
  } else {
    rank_b = 1;
  }
  // debug(a); debug(b); 
  // debug(rank_a, rank_b);


  if(rank_a > rank_b) {
    return 1;
  } else if(rank_a < rank_b) {
    return -1;
  }

  
  if(rank_a == 10) {
    return 0;    
  } else if(rank_a == 9) {
    int cnt1 = min(mp[a[0][0]], (a.back()[0] == 'A') ? 1 : mp[a.back()[0]]);
    int cnt2 = min(mp[a[0][0]], (b.back()[0] == 'A') ? 1 : mp[b.back()[0]]);;
    if(cnt1 > cnt2) {
      return 1;
    } else if(cnt1 < cnt2) {
      return -1;
    } else {
      return 0;
    }
  } else if(rank_a == 8) {
    int cnt1 = mp[a[1][0]], cnt2 = mp[b[1][0]];
    if(cnt1 > cnt2) {
      return 1;
    } else if(cnt1 < cnt2) {
      return -1;
    } else {
      int cnt3 = (a[0][0] == a[3][0]) ? mp[a[4][0]] : mp[a[0][0]];
      int cnt4 = (b[0][0] == b[3][0]) ? mp[b[4][0]] : mp[b[0][0]];
      if(cnt3 == cnt4) {
        return 0;
      } else if(cnt3 > cnt4) {
        return 1;
      } else if(cnt4 > cnt3) {
        return -1;
      }
    }
  } else if(full_a) {
    // bool full_a = (A[0] == A[1] && A[2] == A[4]) | (A[0] == A[2] && A[3] == A[4]);
    // bool full_b = (B[0] == B[1] && B[2] == B[4]) | (B[0] == B[2] && B[3] == B[4]);
    int cnta1 = mp[a[2][0]], cntb1 = mp[b[2][0]];
    // int cnta2 = mp[A[1]], cntb2 = mp[B[1]];
    if(cnta1 > cntb1) {
      return 1;
    } else if(cnta1 < cntb1) {
      return -1;
    } else {
      int cnta2 = (a[0][0] == a[2][0]) ? mp[a[3][0]] : mp[a[0][0]];
      int cntb2 = (b[0][0] == b[2][0]) ? mp[b[3][0]] : mp[b[0][0]];
      if(cnta2 == cntb2) {
        return 0;
      } else if(cnta2 > cntb2) {
        return 1;
      } else if(cntb2 > cnta2) {
        return -1;
      }
    }

  } else if(flush_a) {
    for(int i = 4; i >= 0; i -- ) if(mp[a[i][0]] > mp[b[i][0]]) {
      return 1;
    } else if(mp[a[i][0]] < mp[b[i][0]]) {
      return -1;
    } 

    return 0;

  } else if(shunzi_a) {
    int cnt1 = min(mp[a[0][0]], a.back()[0] == 'A' ? 1 : mp[a.back()[0]]);
    int cnt2 = min(mp[b[0][0]], b.back()[0] == 'A' ? 1 : mp[b.back()[0]]);;
    if(cnt1 > cnt2) {
      return 1;
    } else if(cnt1 < cnt2) {
      return -1;
    } else {
      return 0;
    }

  } else if(three_a) {
    int cnt1[3], cnt2[3];

    for(int i = 0; i + 2 < 5; i ++ ) {
      if(a[i][0] == a[i + 2][0]) {
        // three_a = true;
        cnt1[0] = mp[a[i][0]];
        if(i == 0) {
          cnt1[1] = mp[a[i + 3][0]];
          cnt1[2] = mp[a[i + 4][0]];
        } else if(i == 1) {
          cnt1[1] = mp[a[0][0]];
          cnt1[2] = mp[a[4][0]];
        } else {
          cnt1[1] = mp[a[0][0]];
          cnt1[2] = mp[a[1][0]];
        }
        if(cnt1[1] < cnt1[2]) swap(cnt1[1], cnt1[2]);
      }
    }
    
    for(int i = 0; i + 2 < 5; i ++ ) {
      if(b[i][0] == b[i + 2][0]) {
        cnt2[0] = mp[b[i][0]];
        if(i == 0) {
          cnt2[1] = mp[b[i + 3][0]];
          cnt2[2] = mp[b[i + 4][0]];
        } else if(i == 1) {
          cnt2[1] = mp[b[0][0]];
          cnt2[2] = mp[b[4][0]];
        } else {
          cnt2[1] = mp[b[0][0]];
          cnt2[2] = mp[b[1][0]];
        }
        if(cnt2[1] < cnt2[2]) swap(cnt2[1], cnt2[2]);
      }
    }

    for(int i = 0; i < 3; i ++ ) if(cnt1[i] > cnt2[i]) {
      return 1;
    } else if(cnt1[i] < cnt2[i]) {
      return -1;
    }

    return 0;

  } else if(two_pair_a) {

    int cnt1[3], cnt2[3];

    for(int i = 0; i < 2; i ++ ) {
      for(int j = i + 1; j < 3; j ++ ) if(a[i][0] == a[j][0]) {
        for(int k = j + 1; k < 4; k ++ ) {
          for(int l = k + 1; l < 5; l ++ ) {
            if(a[k][0] == a[l][0]) {
              // two_pair_a = true;
              cnt1[1] = mp[a[i][0]];
              cnt1[0] = mp[a[k][0]];
              
              int x = 0 ^ 1 ^ 2 ^ 3 ^ 4 ^ i ^ j ^ k ^ l;
              cnt1[2] = mp[a[x][0]];

            }
          }
        }
      }
    }

    for(int i = 0; i < 2; i ++ ) {
      for(int j = i + 1; j < 3; j ++ ) if(b[i][0] == b[j][0]) {
        for(int k = j + 1; k < 4; k ++ ) {
          for(int l = k + 1; l < 5; l ++ ) {
            if(b[k][0] == b[l][0]) {
              cnt2[1] = mp[b[i][0]];
              cnt2[0] = mp[b[k][0]];
              
              int x = 0 ^ 1 ^ 2 ^ 3 ^ 4 ^ i ^ j ^ k ^ l;
              cnt2[2] = mp[b[x][0]];
            }
          }
        }
      }
    }
    for(int i = 0; i < 3; i ++ ) if(cnt1[i] > cnt2[i]) {
      return 1;
    } else if(cnt1[i] < cnt2[i]) {
      return -1;
    }

    return 0;
    

  } else if(pair_a) {
    int cnt1[4], cnt2[4];

    for(int i = 0; i < 4; i ++ ) {
      if(a[i][0] == a[i + 1][0]) {
        cnt1[0] = mp[a[i][0]];
        int p = 1;
        for(int j = 4; j >= 0; j -- ) if(j != i && j != i + 1) {
          cnt1[p ++ ] = mp[a[j][0]];
        }
      }
      if(b[i][0] == b[i + 1][0]) {
        cnt2[0] = mp[b[i][0]];
        int p = 1;
        for(int j = 4; j >= 0; j -- ) if(j != i && j != i + 1) {
          cnt2[p ++ ] = mp[b[j][0]];
        }
      }
    }

    for(int i = 0; i < 4; i ++ ) if(cnt1[i] > cnt2[i]) {
      return 1;
    } else if(cnt1[i] < cnt2[i]) {
      return -1;
    }

    return 0;


  } else {

    for(int i = 4; i >= 0; i -- ) if(mp[a[i][0]] > mp[b[i][0]]) {
      return 1;
    } else if(mp[a[i][0]] < mp[b[i][0]]) {
      return -1;
    }

    return 0;
  }
  return 0;
}

vector<string> a, b, c;
bool st[10];
// 1 必胜 0 draw -1 必负
int dfs(int dep)
{
  if(dep == 5) {
    for(int i = 0; i < 6; i ++ ) if(!st[i]) {
      b[dep/2+2] = c[i];
    }
    int ans = -check(a, b);
    return ans;
  }

  int cnt[3] = {0, 0, 0};
  for(int i=0;i<6;i++) if(!st[i]) {
    st[i] = 1;
    if(dep&1) b[dep/2+2] = c[i];
    else a[dep/2+2] = c[i];
    int t = dfs(dep+1);
    if(t == -1) {
      st[i] = 0;
      return 1;
    }
    cnt[t + 1] ++;
    st[i] = 0;
  }
  // if(cnt[0]) return 1;
  if(cnt[1]) return 0;
  return -1;

} 


void solve() {
  cin >> a[0] >> a[1];
  cin >> b[0] >> b[1];
  for(int i = 0; i < 6; i ++ ) {
    cin >> c[i];
  }
  memset(st, 0, sizeof st);

  int ans;
  ans = dfs(0);

  if(ans == 1) {
    cout << "Alice\n";
  } else if(ans == -1) {
    cout << "Bob\n";
  } else {
    cout << "Draw\n";
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("data.txt", "r", stdin);
  // freopen("B.txt", "w", stdout);
  mp['A'] = 14;
  mp['2'] = 2;mp['3'] = 3;mp['4'] = 4;mp['5'] = 5;mp['6'] = 6;
  mp['7'] = 7;mp['8'] = 8;mp['9'] = 9;mp['T'] = 10;mp['J'] = 11;
  mp['Q'] = 12;mp['K'] = 13;

  a.resize(5), b.resize(5), c.resize(6);
  
  int T = 1; cin >> T;
  while(T -- ) solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;

}