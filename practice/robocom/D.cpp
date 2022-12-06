#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 10;

int cnt[N];
int spc[N][3];
int num[1 << 7];
// bool f[10];
// int f[N][N][N];
bool is[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int all = 0;
  for(int i = 0; i < 6; i ++ ) {
    cin >> cnt[i];
    all += cnt[i];
    // if(cnt[i]) all ++;
  } 
  // cout << all << " allllllll\n";
  for(int i = 0; i < 6; i ++ ) {
    string s; cin >> s;
    for(int j = 0; j < 3; j ++ ) {
      spc[i][j] = (s[j] - 48);
    }
  }
  string ans(6, '7');
  vector<string> f[10];
  for(int i = 0; i < 1 << 6; i ++ ) {
    bool f1 = false, f2 = false;
    bool f11 = false, f12 = false, f21 = false, f22 = false;
    string res;
    for(int j = 0; j < 6; j ++ ) if((i >> j & 1) && cnt[j]) {
      if(spc[j][0]) f1 = true;
      if(spc[j][1]) f11 = true;
      if(spc[j][2]) f12 = true;
      res.push_back((char)((j + 1) + 48));
    } else if(cnt[j]) {
      if(spc[j][0]) f2 = true;
      if(spc[j][1]) f21 = true;
      if(spc[j][2]) f22 = true;
    }
    if(!f1 || !f2) continue;
    
    if(!(f11 && f12 && f21 && f22) && is[1]) continue;
    
    if(!(f11 && f12 && f21 && f22) ) {
      //规则1不满足条件，判断是否满足规则2

      if(f12 && f22) { //规则2满足
        f[2].push_back(res);
      } else { //规则2不满足
        f[3].push_back(res);
      }
    } else {
      // f[1] = true; //找到了满足规则 1 的
      //看规则3
      // cout << res << ">>> \n";
      is[1] = true;
      f[1].push_back(res);
    }
  }

  if(is[1]) {
    if(f[1].size() == 1) {
      string l = f[1][0];
      string r;
      for(int i = 0; i < 6; i ++ ) if(cnt[i]) {
        if(l.find((char)('0' + (i + 1))) == -1) {
          r.push_back((char)('0' + (i + 1)));
        }
      }
      sort(l.begin(), l.end());
      sort(r.begin(), r.end());
      for(int p = 0; p < l.size(); p ++ ) {
        cout << l[p] << " \n"[p == l.size() - 1];
      }
      for(int p = 0; p < r.size(); p ++ ) {
        cout << r[p];
        if(p + 1 != r.size() ) cout << " ";
      }
      return 0;
    }

    int cha = INT_MAX;
    for(string &res : f[1]) {
      int ct = 0;
      sort(res.begin(), res.end());
      for(char c: res) {
        ct += cnt[(c - '0' - 1)];
      }
      cha = min(cha, abs(ct - (all - ct)));
    }
    int mx = 0;
    string tmp;
    for(string res : f[1])  {
      int ct = 0;
      for(char c: res) {
        ct += cnt[(c - '0' - 1)];
      }
      if(abs(all - ct - ct) != cha) continue;
      mx = max(mx, ct);
    }
    for(string res : f[1])  {
      int ct = 0;
      for(char c: res) {
        ct += cnt[(c - '0' - 1)];
      }
      if(ct != mx) continue;
      if(tmp.empty()) {
        tmp = res;
      } else {
        if(res < tmp) {
          tmp = res;
        }
      }
    }
    string l = tmp;
    string r;
    for(int i = 0; i < 6; i ++ ) if(cnt[i]) {
      if(l.find((char)('0' + (i + 1))) == -1) {
        r.push_back((char)('0' + (i + 1)));
      }
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    for(int p = 0; p < l.size(); p ++ ) {
      cout << l[p] << " \n"[p == l.size() - 1];
    }
    for(int p = 0; p < r.size(); p ++ ) {
      cout << r[p];
      if(p + 1 != r.size() ) cout << " ";
    }
  } else if(!f[2].empty()) {
    if(f[2].size() == 1) {
      string l = f[2][0];
      string r;
      for(int i = 0; i < 6; i ++ ) if(cnt[i]) {
        if(l.find((char)('0' + (i + 1))) == -1) {
          r.push_back((char)('0' + (i + 1)));
        }
      }
      sort(l.begin(), l.end());
      sort(r.begin(), r.end());
      for(int p = 0; p < l.size(); p ++ ) {
        cout << l[p] << " \n"[p == l.size() - 1];
      }
      for(int p = 0; p < r.size(); p ++ ) {
        cout << r[p];
        if(p + 1 != r.size() ) cout << " ";
      }
      return 0;
    }

    int cha = INT_MAX;
    for(string &res : f[2]) {
      int ct = 0;
      sort(res.begin(), res.end());
      for(char c: res) {
        ct += cnt[(c - '0' - 1)];
      }
      cha = min(cha, abs(ct - (all - ct)));
    }
    int mx = 0;
    string tmp;
    for(string res : f[2])  {
      int ct = 0;
      for(char c: res) {
        ct += cnt[(c - '0' - 1)];
      }
      if(abs(all - ct - ct) != cha) continue;
      mx = max(mx, ct);
    }
    for(string res : f[2])  {
      int ct = 0;
      for(char c: res) {
        ct += cnt[(c - '0' - 1)];
      }
      if(ct != mx) continue;
      if(tmp.empty()) {
        tmp = res;
      } else {
        if(res < tmp) {
          tmp = res;
        }
      }
    }
    string l = tmp;
    string r;
    for(int i = 0; i < 6; i ++ ) if(cnt[i]) {
      if(l.find((char)('0' + (i + 1))) == -1) {
        r.push_back((char)('0' + (i + 1)));
      }
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    for(int p = 0; p < l.size(); p ++ ) {
      cout << l[p] << " \n"[p == l.size() - 1];
    }
    for(int p = 0; p < r.size(); p ++ ) {
      cout << r[p];
      if(p + 1 != r.size() ) cout << " ";
    }
  } else if(!f[3].empty()) {
    if(f[3].size() == 1) {
      string l = f[3][0];
      string r;
      for(int i = 0; i < 6; i ++ ) if(cnt[i]) {
        if(l.find((char)('0' + (i + 1))) == -1) {
          r.push_back((char)('0' + (i + 1)));
        }
      }
      sort(l.begin(), l.end());
      sort(r.begin(), r.end());
      for(int p = 0; p < l.size(); p ++ ) {
        cout << l[p] << " \n"[p == l.size() - 1];
      }
      for(int p = 0; p < r.size(); p ++ ) {
        cout << r[p];
        if(p + 1 != r.size() ) cout << " ";
      }
      return 0;
    }

    int cha = INT_MAX;
    for(string &res : f[3]) {
      int ct = 0;
      sort(res.begin(), res.end());
      for(char c: res) {
        ct += cnt[(c - '0' - 1)];
      }
      cha = min(cha, abs(ct - (all - ct)));
    }
    int mx = 0;
    string tmp;
    for(string res : f[3])  {
      int ct = 0;
      for(char c: res) {
        ct += cnt[(c - '0' - 1)];
      }
      if(abs(all - ct - ct) != cha) continue;
      mx = max(mx, ct);
    }
    for(string res : f[3])  {
      int ct = 0;
      for(char c: res) {
        ct += cnt[(c - '0' - 1)];
      }
      if(ct != mx) continue;
      if(tmp.empty()) {
        tmp = res;
      } else {
        if(res < tmp) {
          tmp = res;
        }
      }
    }
    string l = tmp;
    string r;
    for(int i = 0; i < 6; i ++ ) if(cnt[i]) {
      if(l.find((char)('0' + (i + 1))) == -1) {
        r.push_back((char)('0' + (i + 1)));
      }
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    for(int p = 0; p < l.size(); p ++ ) {
      cout << l[p] << " \n"[p == l.size() - 1];
    }
    for(int p = 0; p < r.size(); p ++ ) {
      cout << r[p];
      if(p + 1 != r.size() ) cout << " ";
    }
  } else {
    cout << "GG\n";
  }

  return 0;
}