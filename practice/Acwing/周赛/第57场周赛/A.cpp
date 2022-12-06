#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<int> a(n), b(n);
  ll s1 = 0, s2 = 0;
  for(int &x: a) {
    cin >> x;
    s1 += x;
  } 
  for(int &x: b) {
    cin >> x;
    s2 += x;
  } 
  if(s1 >= s2) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}