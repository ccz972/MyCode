#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
long long f[30];
int n;
long long dfs(int sum) {
  if(sum == n) return 1;
  long long ret = 0;
  for(int i = 1; sum + i <= n; i ++ ) {
    ret += dfs(sum + i);
  }
  return ret;
}

int main()
{
  
  cin >> n;
  cout << dfs(0);
  return 0;
}
