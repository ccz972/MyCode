#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

constexpr int N = 1e5 + 10;
int n; 
char s[N];
int stk[N];
int f[N];
bool st[N];
int nxt[N];
// int x;
// void dfs(int idx) {
//   x = idx;
//   if(idx >= n) {
//     return ;
//   }
//   if(s[idx] == '-' || s[idx] == ')') {
//     nxt[idx] = idx + 1;
//     dfs(idx + 1);
//     return ;
//   } else {
//     nxt[idx] = idx + 1;
//     nxt[f[idx]] = idx;
//     dfs(idx + 1);
//   }
// }

void dfs(int idx, int r) {
  if(idx > n) {
    return ;
  }
  if(idx == r) {
    st[idx] = true;
    cout << idx << " ";
    return ;
  }
  if(s[idx] == '-') {
    st[idx] = true;
    cout << idx << " ";
    dfs(idx + 1, r);
  } else if (s[idx] == '(') {
    dfs(idx + 1, f[idx]);
    cout << idx << " ";
    dfs(f[idx] + 1, r);
    
  }
}

int main()
{
  scanf("%d", &n);
  scanf("%s", s + 1); 
  int tt = 0;
  for(int i = 1; i <= n; i ++ ) {
    if (s[i] == '(') {
      stk[++ tt] = i;
    } else if (s[i] == ')') {
      int top = stk[tt --];
      f[i] = top;
      f[top] = i;
    }
  }
  // for(int i = 1; i <= n; i ++ ) if(f[i] > i) {
  //   cout << i << " " << f[i] << "\n";
  // }
  dfs(1, n + 1);

  return 0;
}
