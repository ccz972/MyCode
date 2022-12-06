/***************************************************

@File    : C.cpp
@Time    : 2022/07/17 14:51:34
@Author  : Nanfeng1997 
@Url     : https://www.cnblogs.com/c972937/

奇迹会发生在那些相信并为之拼尽全力的人身上 !
***************************************************/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
#define int128 __int128
inline int128 read() {
  int128 x = 0, f = 1;
  char ch = getchar();

  while(!isdigit(ch)) {
    if(ch == '-') f = -1;
    ch = getchar();
  }

  while(isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  
  return x * f;
}

inline void print(int128 x) { 
  if(x < 0) { putchar('-'); x = -x; }
  if(x > 9) print(x / 10);
  putchar(x % 10 | 48);
}

inline void println(int128 x) {
  print(x);
  putchar('\n');
}

struct node {
  int128 a, h, x;
}f, d, v;

#define rd(x) x = read()

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  rd(f.a); rd(f.h); f.x = 1;
  rd(d.a); rd(d.h); rd(d.x);
  int128 k;
  rd(k);
  rd(v.a); rd(v.h); v.x = 1;
   
  int128 ans = 0;
  //
  if(d.x > k) {
    
    int128 cnt = (d.h + f.a - 1) / f.a; //一个怪物可以被几次攻击 Kill
    if(cnt == 1) {
      ans += d.x - k;
    } else {
      int128 HP = (cnt - 1) * d.a; //一个怪物掉的血
      int128 ct = f.h / HP;  // 最多承受几次掉血 
      if(ct <= d.x - k) {
        cout << "No Franxx!\n"; return 0;
      }
      // puts("---------");
      // println(cnt); 
      // println(d.x - k); 
      // puts("--------");
      ans += cnt * (d.x - k); //一个的次数乘以所有的次数
      f.h -= (d.x - k) * HP;


      
    }
    d.x = k;

  } 

  //d.x <= k
  
  //kill 小野怪
  if(d.x) {
    int128 cnt = (d.h + f.a - 1) / f.a; //一个怪物可以被几次攻击 Kill
    // debug(cnt);
    // puts("---------");
    // println(cnt);
    // puts("--------");
    int128 HP = (cnt - 1) * d.a + v.a * cnt; //一个怪物掉的血
    int128 ct = f.h / HP;  // 最多承受几次掉血 

    // print(ct); putchar(' '); print(d.x); putchar(' '); println(f.h);

    if(ct <= d.x) {
      cout << "No Franxx!\n"; return 0;
    }
    ans += cnt * d.x; //一个的次数乘以所有的次数
    f.h -= d.x * HP;
  }
  //kill boss

  if(f.h == 0) {
    cout << "No Franxx!\n"; return 0;
  }

  int128 cnt = (v.h + f.a - 1) / f.a;
  //需要攻击的次数
  int128 HP = (cnt - 1) * v.a; //承受伤害
  if(f.h <= HP) {
    cout << "No Franxx!\n";
  } else {
    print(ans + cnt);
  }
  

  // // cin >> f.a >> f.h; f.x = 1;
  // // cin >> d.a >> d.h >> d.x;
  // // ll k; cin >> k;
  // // cin >> v.a >> v.h;
  // int128 ans = 0;
  // if(d.x) {
  //   int128 cnt = (d.h + f.a - 1) / f.a; //一个怪物可以被几次攻击 Kill
  //   int128 HP = (cnt - 1) * d.a; //一个怪物掉的血
  //   int128 ct = f.h / HP;  // 一共能掉几次血 

  //   if(ct < d.x) { 
  //     cout << "No Franxx!\n";
  //     return 0;
  //   } else if(ct == d.x) {
  //     if(f.h % HP == 0) {
  //       cout << "No Franxx!\n";
  //       return 0;
  //     }
  //   }
  //   ans += (__int128)cnt * d.x; //一个的次数乘以所有的次数
  //   f.h -= d.x * HP;
  // } 
  
  // //f.a f.h
  // int128 cnt = (v.h + f.a - 1) / f.a;
  // //需要攻击的次数
  // int128 HP = (cnt - 1) * v.a; //承受伤害
  // if(f.h <= HP) {
  //   cout << "No Franxx!\n";
  // } else {
  //   print(ans + cnt);
  // }



  return 0;
}