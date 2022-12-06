#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif
#define rep(i, a, b) for(int i(a); i < b; ++ i)
template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

constexpr int N = 10;

int sum[N][N][N][N][N][N];

int get(char c) {
  return c - '0';
}

void add(string s) {
  sum[get(s[0])][get(s[1])][get(s[2])][get(s[3])][get(s[4])][get(s[5])] ++;
  // debug(get(s[0]), get(s[1]), get(s[2]), get(s[3]), get(s[4]), get(s[5]));
}

int Sum(string s) {
  return sum[get(s[0])][get(s[1])][get(s[2])][get(s[3])][get(s[4])][get(s[5])];
}


void solve() {
  int n; cin >> n;
  vector<string> a(n), b(n);
  for(int i = 0; i < n; i ++ ) {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    while(s.size() < 6) s.push_back('0');
    reverse(s.begin(), s.end());
    a[i] = s;
    add(s);
    for(int j = 0; j < 6; j ++ ) {
      char &c = s[j];
      c = ('9' - c) + '0';
    }
    
    b[i] = s;
    // debug(a[i], b[i]);
  }

  rep(i1, 1, 10) {
    rep(i2, 0, 10) {
      rep(i3, 0, 10) {
        rep(i4, 0, 10) {
          rep(i5, 0, 10) {
            rep(i6, 0, 10) {
              sum[i1][i2][i3][i4][i5][i6] += sum[i1 - 1][i2][i3][i4][i5][i6];
            }
          }
        }
      }
    }
  }

  rep(i1, 0, 10) {
    rep(i2, 1, 10) {
      rep(i3, 0, 10) {
        rep(i4, 0, 10) {
          rep(i5, 0, 10) {
            rep(i6, 0, 10) {
              sum[i1][i2][i3][i4][i5][i6] += sum[i1][i2 - 1][i3][i4][i5][i6];
            }
          }
        }
      }
    }
  }
  rep(i1, 0, 10) {
    rep(i2, 0, 10) {
      rep(i3, 1, 10) {
        rep(i4, 0, 10) {
          rep(i5, 0, 10) {
            rep(i6, 0, 10) {
              sum[i1][i2][i3][i4][i5][i6] += sum[i1][i2][i3 - 1][i4][i5][i6];
            }
          }
        }
      }
    }
  }
  rep(i1, 0, 10) {
    rep(i2, 1, 10) {
      rep(i3, 0, 10) {
        rep(i4, 1, 10) {
          rep(i5, 0, 10) {
            rep(i6, 0, 10) {
              sum[i1][i2][i3][i4][i5][i6] += sum[i1][i2][i3][i4 - 1][i5][i6];
            }
          }
        }
      }
    }
  }
  rep(i1, 0, 10) {
    rep(i2, 1, 10) {
      rep(i3, 0, 10) {
        rep(i4, 0, 10) {
          rep(i5, 1, 10) {
            rep(i6, 0, 10) {
              sum[i1][i2][i3][i4][i5][i6] += sum[i1][i2][i3][i4][i5 - 1][i6];
            }
          }
        }
      }
    }
  }
  rep(i1, 0, 10) {
    rep(i2, 1, 10) {
      rep(i3, 0, 10) {
        rep(i4, 0, 10) {
          rep(i5, 0, 10) {
            rep(i6, 1, 10) {
              sum[i1][i2][i3][i4][i5][i6] += sum[i1][i2][i3][i4][i5][i6 - 1];
            }
          }
        }
      }
    }
  }
  vector<int> ans1(n);
  ll sum = 0;
  for(int i = 0; i < n; i ++ ) {
    bool flag = true;
    for(int j = 0; j < 6; j ++ ) {
      if((a[i][j] - '0') + (a[i][j] - '0') > 9) {
        flag = false;
      }
    }
    if(flag) sum --;
    sum += Sum(b[i]);
  }

  cout << sum / 2;

}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
#ifdef LOCAL
  clock_t ends = clock();
  cout << "\n\nRunning Time : " << (double) (ends - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
  return 0;
}
