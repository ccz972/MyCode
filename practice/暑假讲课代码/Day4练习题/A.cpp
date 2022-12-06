#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

int a[N];

void solve1() {

  int n, k; scanf("%d%d", &k, &n);

  map<int, int> mp;

  for(int i = 0; i < n; i ++ ) {
    scanf("%d", a + i);
    mp[a[i]] ++;
  }

  sort(a, a + n);

  bool flag = false;
  
  for(int i = 0; i < n; i ++ ) if(mp[a[i]]) {
    mp[a[i]] --;  
    if(mp[k - a[i]]) {
      printf("%d %d\n", a[i], k - a[i]);
      mp[k - a[i]] --;
      flag = true;
    }
  }

  if(!flag) puts("No Solution");
}

void solve2() {

  int n, k; scanf("%d%d", &k, &n);

  map<int, int> mp;

  for(int i = 0; i < n; i ++ ) {
    scanf("%d", a + i);
    mp[a[i]] ++;
  }

  sort(a, a + n);

  bool flag = false;
  
  for(int i = 0; i < n - 1; i ++ ) {
    int l = i + 1, r = n - 1;
    while(l < r) {
      int mid = (l + r) / 2;
      //a[mid] >= k - a[i] 
      if(a[mid] + a[i] >= k) r = mid;
      else l = mid + 1;
    }

    if(a[l] + a[i] == k) {
      printf("%d %d\n", a[i], a[l]);
      flag = true;
    }

  }

  if(!flag) puts("No Solution");

}

void solve3() {

  int n, k; scanf("%d%d", &k, &n);

  // map<int, int> mp;

  for(int i = 0; i < n; i ++ ) {
    scanf("%d", a + i);
    // mp[a[i]] ++;
  }

  sort(a, a + n);

  bool flag = false;
  
  //0 -->   <--  n - 1

   


  for(int i = 0, j = n - 1; i < j; ) {
    if(a[i] + a[j] == k) {
      printf("%d %d\n", a[i], a[j]);
      ++ i, -- j;
      flag = true;
    } else if(a[i] + a[j] > k) {
      -- j;
    } else {
      ++ i;
    }
  }

  if(!flag) puts("No Solution");

}





int main() {
  // solve1();
  // solve2();
  // solve3();


  return 0;
}