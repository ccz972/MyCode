#include<bits/stdc++.h>

using namespace std;
int n,m,a,b,h;
bool chk(int x) {
  int last = n + m - x;
  if(last < b) return false;
  int P = (h - b) * (last / b) ;
  if(P < x) return false;
  return true;
}

int main()
{
    int T;cin>>T;
    while(T--)
    {
      
      cin>>a>>b>>n>>m>>h; 
      if(n>=b) m -= min(m-1,(n+b-1)/b*(b-a));
      int l = 0, r = m - 1;
      while(l < r) {
        int mid = (l + r + 1) / 2;
        if(chk(mid)) l = mid;
        else r = mid - 1;
      }      
      //
      
    }   
    return 0;
}
