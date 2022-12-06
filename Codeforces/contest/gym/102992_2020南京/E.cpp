#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 

void get(int &x, int &y, char c) {
  if (c == 'U') y ++;
  if (c == 'D') y --;
  if (c == 'L') x --;
  if (c == 'R') x ++;
}

int get(char c) {
  if (c == 'U') return 0;
  if (c == 'D') return 1;
  if (c == 'L') return 2;
  return 3;
}

void solve() {
  int ax, ay; cin >> ax >> ay;
  string s; cin >> s;
  int x = 0, y = 0;
  vector<int> cnt(4, 0);
  for (char c: s) get(x, y, c), cnt[get(c)] ++;
  if ((x == ax && y == ay) || (ax == 0 && ay == 0)) return cout << "Impossible\n", void();
  x = 0, y = 0;

  string ans;

  string left, right;

  for (int i = 0; i < min(cnt[0], cnt[1]); i ++ ) {
    if (ax == 0 && abs(ay) == 1) {
      if (ay == 1) {
        left.push_back('D');
        left.push_back('U');
      } else {
        left.push_back('U');
        left.push_back('D');
      }
    } else {
      left.push_back('U');
      left.push_back('D');
    }
  }
  
  for (int i = 0; i < min(cnt[2], cnt[3]); i ++ ) {
    if (ay == 0 && abs(ax) == 1) {
      if (ax == 1) {
        right.push_back('L');
        right.push_back('R');
      } else {
        right.push_back('R');
        right.push_back('L');
      }
    } else {
      right.push_back('R');
      right.push_back('L');
    }
  }

  ans = left + right;

  bool flag1 = ((cnt[0] + cnt[1]) > 0);
  bool flag2 = ((cnt[2] + cnt[3]) > 0);

  int tmp = min(cnt[0], cnt[1]); 
  cnt[0] -= tmp, cnt[1] -= tmp;
  tmp = min(cnt[2], cnt[3]);
  cnt[2] -= tmp, cnt[3] -= tmp;

  string t = "UDLR";
  auto TTMP = cnt;
  if ((cnt[0] || cnt[1]) && (cnt[2] || cnt[3])) { 
    while (cnt[0] || cnt[1] || cnt[2] || cnt[3]) {
      if (cnt[0] || cnt[1]) {
        if (cnt[0]) {
          get(x, y, t[0]);
          if (x == ax && y == ay) {
            get(x, y, t[1]);
            if (cnt[2]) {
              get(x, y, t[2]);
              ans += t[2];
              -- cnt[2];
            } else {
              get(x, y, t[3]);
              ans += t[3];
              -- cnt[3];
            }  
          } else {
            ans += t[0];
            -- cnt[0];
          }
        } else {
          get(x, y, t[1]);
          if (x == ax && y == ay) {
            get(x, y, t[0]);
            if (cnt[2]) {
              get(x, y, t[2]);
              ans += t[2];
              -- cnt[2];
            } else {
              get(x, y, t[3]);
              ans += t[3];
              -- cnt[3];
            }  
          } else {
            ans += t[1];
            -- cnt[1];
          }
        }

        


      } else {
        if (cnt[2]) {
          get(x, y, t[2]);
          ans += t[2];
          -- cnt[2];
        } else {
          get(x, y, t[3]);
          ans += t[3];
          -- cnt[3];
        }  
      }
    }

    int px = 0, py = 0;
    bool flag = true;
    for (char c: ans) {
      get(px, py, c);
      if (px == ax && py == ay) {
        flag = false; break;
      }
    }
    // cout << flag << " !!!\n";
    if (!flag) {
      ans = left + right;
      cnt.swap(TTMP);
      x = 0, y = 0;
      while (cnt[0] || cnt[1] || cnt[2] || cnt[3]) {
        if (cnt[2] || cnt[3]) {
          if (cnt[2]) {
            get(x, y, t[2]);
            if (x == ax && y == ay) {
              get(x, y, t[3]);
              if (cnt[0]) {
                get(x, y, t[0]);
                ans += t[0];
                -- cnt[0];
              } else {
                get(x, y, t[1]);
                ans += t[1];
                -- cnt[1];
              }  
            } else {
              ans += t[2];
              -- cnt[2];
            }
          } else {
            get(x, y, t[3]);
            if (x == ax && y == ay) {
              get(x, y, t[2]);
              if (cnt[0]) {
                get(x, y, t[0]);
                ans += t[0];
                -- cnt[0];
              } else {
                get(x, y, t[1]);
                ans += t[1];
                -- cnt[1];
              }  
            } else {
              ans += t[3];
              -- cnt[3];
            }
          }
        } else {
          if (cnt[0]) {
            get(x, y, t[0]);
            ans += t[0];
            -- cnt[0];
          } else {
            get(x, y, t[1]);
            ans += t[1];
            -- cnt[1];
          }  
        }
      }
    } 
  } else if ( (cnt[0] > 0) + (cnt[1] > 0) + (cnt[2] > 0) + (cnt[3] > 0) == 1) {
    // string t = "UDLR";
    if (cnt[0]) {
      if (ax == 0 && ay > 0 && cnt[0] >= ay) {
        if (flag2) {
          ans.pop_back();
          ans.pop_back();
          ans += "L";
          string p(cnt[0], 'U');
          ans += p;
          ans += "R";  
        } else {
          // error
          return cout << "Impossible\n", void();
        }
      } else {
        string p(cnt[0], 'U');
        ans += p;
      }
    } else if (cnt[1]) {
      if (ax == 0 && ay < 0 && cnt[1] >= abs(ay)) {
        if (flag2) {
          ans.pop_back();
          ans.pop_back();
          ans += "L";
          string p(cnt[1], 'D');
          ans += p;
          ans += "R";  
        } else {
          //error
          return cout << "Impossible\n", void();
        }
      } else {
        string p(cnt[1], 'D');
        ans += p;
      }

    } else if (cnt[2]) {
      ans = right + left;
      if (ay == 0 && ax < 0 && cnt[2] >= abs(ax)) {
        if (flag1) {
          ans.pop_back();
          ans.pop_back();
          ans += "U";
          string p(cnt[2], 'L');
          ans += p;
          ans += "D";  
        } else {
          //error
          return cout << "Impossible\n", void();
        }
      } else {
        string p(cnt[2], 'L');
        ans += p;
      }
    } else if (cnt[3]) {
      ans = right + left;
      if (ay == 0 && ax > 0 && cnt[2] >= ax) {
        if (flag1) {
          ans.pop_back();
          ans.pop_back();
          ans += "U";
          string p(cnt[3], 'R');
          ans += p;
          ans += "D";  
        } else {
          //error
          return cout << "Impossible\n", void();
        }
      } else {
        string p(cnt[3], 'R');
        ans += p;
      }
    } else {
      assert(false);
    }
  } 
  cout << ax << " " << ay << "\n";
  cout << ans << "\n"; 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T; cin >> T;
  while (T -- )
  solve();
  return 0;
}