#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= b; ++ i)


void solve() {
  ll a, b;
  cin >> a >> b;
  ll x = 1, y = 1;
  while (~a & 1) {
    a >>= 1;
    x <<= 1;
  }
  while (~b & 1) {
    b >>= 1;
    y <<= 1;
  }

  a = x, b = y;

  if (a & 1) {
    cout << "1 1";
  } else if (b & 1) {
    cout << "1 0";
  } else { //如果Alice说 i don't know 说明Bob一定是个偶数
    // cout << "2 0\n";
    int cnt = 1;
    while (true) {
      a /= 2, b /= 2;
      if (a & 1) {
        cout << cnt << " 1";
        break;
      } else if (b & 1) {
        cout << cnt + 1 << " 0";
        break;
      }
      ++ cnt;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; cin >> T;
  for (int i = 1; i <= T; i ++ ) {
    solve();
    if (i != T) cout << "\n";
  }
  return 0;
}

/*

4 2 (Answer is 2, 0)
Alice：
对面是2，我只能是 4 或者 1，如果对面也不知道，那我肯定是 4
- 如果我是1，Bob肯定立马就猜对了
- 如果我是4，那么Bob猜他是2或者8，

Bob：
对面是4，我只能是 2 或者 8， Alice 不知道他是谁
- 如果我是2，那Alice会猜他是1 or 4，但是我不知道，因此Alice下一轮会猜他是4
- 如果我是4，那么Bob猜他是2或者8，



8 4 

Alice：
对面是4，那我只能是2 或者 8，猜不到

- 如果我是2的话，Bob 猜他自己肯定是 4 或者 1，但是我说不知道，那么Bob肯定只能猜他是4
- 如果我是8的话，Bob 猜他自己肯定是 4 或者 16，但是我说不知道，那么Bob肯定也不知道到底是4还是16

Bob：
对面是8，那我只能是 4 或者 16，猜不到，但是Alice说他也不知道，
  if (4) {
    Alice guess 2 or 8
    但是我猜不到，如果Alice是2的话，那我是4，我一定能猜到，说明Alice会排除2，那么他只能是8
  } else if(16) {

  }

- 如果我是4 (8,4)的话，Alice猜他自己是2或者8，但是猜不到，那么Alice不可能觉得他是2，那么Alice只有可能觉得他是8

Alice
  Bob也没猜到，那么我不可能是 2，因此我是8



4 8

Alice:
对面是8，那我只能是4 或者 16，猜不到

- 如果我是4的话，那么Bob猜他是2 or 8，但是我说我不知道,
    - 如果Bob是2，那我第二轮一定可以猜到我是4的
    - 如果Bob是8，
- 如果我是16的话，那么Bob猜他是 8 or 32，但是我说我不知道,
    - 如果Bob猜他是8，// correct
    - 如果Bob猜他是32， // 先不讨论

Bob:
对面是4，那我只能是2 或者 8
- 如果我是2，那下一轮Alice就赢了，他猜到了他是4
- 如果我是8，那Alice会猜他是4或者16，
    - 如果Alice猜他是4，



8 16

Alice：
对面是16，那我只能是 32 或者 8，猜不到

- 如果我是8的话，Bob 猜他自己肯定是 4 或者 16，
- 如果我是8的话，Bob 猜他自己肯定是 4 或者 16，但是我说不知道，那么Bob肯定也不知道到底是4还是16

Bob：
对面是8，那我只能是 4 或者 16，猜不到，但是Alice说他也不知道，
  if (4) {
    Alice guess 2 or 8
    但是我猜不到，如果Alice是2的话，那我是4，我一定能猜到，说明Alice会排除2，那么他只能是8
  } else if(16) {

  }

- 如果我是4 (8,4)的话，Alice猜他自己是2或者8，但是猜不到，那么Alice不可能觉得他是2，那么Alice只有可能觉得他是8

Alice
  Bob也没猜到，那么我不可能是 2，因此我是8




*/