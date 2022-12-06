#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve3() {
  int l, r; cin >> l >> r;
  int n = __lg(r) + 1;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i ++ ) {
    a[n - i - 1] = (l >> i & 1);
    b[n - i - 1] = (r >> i & 1);
  }

  if (l <= 2 && 2 <= r) {
    cout << "2" ;
    return ;
  }

  if (l == r) {
    if (__builtin_popcount(l) == __builtin_ctz(r)) {
      cout << l ;
    } else {
      cout << "-1" ;
    }
    return ;
  }

  if (__builtin_popcount(l) == __builtin_ctz(l)) {
    cout << l ; return ;
  }

  if (__builtin_popcount(r) == __builtin_ctz(r)) {
    cout << r ; return ;
  }

  auto judge = [] (vector<int> &x, vector<int> &y) {
    int n = x.size();
    for (int i = 0; i < n; i ++ ) {
      if (x[i] > y[i]) return 1;
      else if (x[i] < y[i]) return -1;
    }
    return 0;
  };

  auto print = [] (vector<int> &x) {

    int now = 0;
    for (int P: x) now = now * 2 + P;
    cout << now;
  };


  for (int i = 2; i <= n / 2; i ++ ) {
    //构造值为 i 的，并且 >= l 的最小的数字
    auto now = a;

    int flag = 0; 
    //flag = -1 表示后缀变小了
    //flag = 1 表示后缀变大了
    for (int j = 0; j < i; j ++ ) {
      //n - 1 - j
      if (now[n - 1 - j] == 1) {
        flag = -1;
        now[n - 1 - j] = 0;
      }
    }

    if (now[n - 1 - i] == 0) {
      flag = 1;
      now[n - 1 - i] = 1;
    }

    for (int j = 0; j < n - 1 - i; j ++ ) now[j] = 0;
    
    int use = i - 1; //i - 1个1分配给前面的
    
    if (flag == 1 || flag == 0) {
      //保证前面的位是大于等于 b 的
      //[0, n - 2 - i], use 个 1
      int zero = 0;
      while (a[zero] == 0) ++ zero;
      for (int j = 0; j < zero; j ++ ) {
        auto nnow = now;
        auto nuse = use;
        nnow[0] = 1;
        //use - 1 
        bool flag = true;
        for (int k = n - 2 - i, l = 0; l < use - 1; k --, l ++ ) {
          if (k <= j) {
            flag = false;
            break;
          }
          nnow[k] = 1;
        }
        
        if (flag && judge(nnow, a) >= 0 && judge(b, nnow) >= 0) {
          //Print(nnow);
          print(nnow); return ;
        }
      }
      
      for (int j = zero; j < n - 1 - i; j ++ ) {
        if (a[j] == 1) {
          now[j] = 1;
          -- use;
          zero = j;
        } else {
          break;
        }
      }

      if (use < 0) {
        continue;
      }

      if (use > 0) {
        for (int j = zero + 1; j < n - 1 - i; j ++ ) {
          auto nnow = now;
          auto nuse = use;
          nnow[j] = 1;
          //use - 1 
          bool flag = true;
          for (int k = n - 2 - i, l = 0; l < use - 1; k --, l ++ ) {
            if (k <= j) {
              flag = false;
              break;
            }
            nnow[k] = 1;
          }
          if (flag && judge(nnow, a) >= 0 && judge(b, nnow) >= 0) {
            //Print(nnow);
            print(nnow); return ;
          }
        }
      } else {
        if (judge(now, a) >= 0 && judge(b, now) >= 0) {
          //Print(nnow);
          print(now); return ;
        }
      }
      
      
    } else {
      //保证前面的位是大于 b 的
      //保证前面的位是大于等于 b 的
      //[0, n - 2 - i], use 个 1
      int zero = 0;
      while (a[zero] == 0) ++ zero;
      for (int j = 0; j < zero; j ++ ) {
        auto nnow = now;
        auto nuse = use;
        nnow[0] = 1;
        //use - 1 
        bool flag = true;
        for (int k = n - 2 - i, l = 0; l < use - 1; k --, l ++ ) {
          if (k <= j) {
            flag = false;
            break;
          }
          nnow[k] = 1;
        }
        
        if (flag && judge(nnow, a) >= 0 && judge(b, nnow) >= 0) {
          //Print(nnow);
          print(nnow); return ;
        }
      }
      
      for (int j = zero; j < n - 1 - i; j ++ ) {
        if (a[j] == 1) {
          now[j] = 1;
          -- use;
          zero = j;
        } else {
          break;
        }
      }

      if (use <= 0) {
        continue;
      }

      for (int j = zero + 1; j < n - 1 - i; j ++ ) {
        auto nnow = now;
        auto nuse = use;
        nnow[j] = 1;
        //use - 1 
        bool flag = true;
        for (int k = n - 2 - i, l = 0; l < use - 1; k --, l ++ ) {
          if (k <= j) {
            flag = false;
            break;
          }
          nnow[k] = 1;
        }
        if (flag && judge(nnow, a) == 1 && judge(b, nnow) == 1) {
          print(nnow); return ;
        }
      }
    }



    


  }
  
  cout << "-1";

}



int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // freopen("1.txt", "w", stdout);
  int T = 1; cin >> T;
  for (int i = 1; i <= T; i ++ ) {
    if (i != 1) cout << "\n" ;
    solve3();
  }
  return 0;
}