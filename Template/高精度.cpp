vector<int> operator + (vector<int> &a, vector<int> &b) {
  //顺序是反过来的  低位到高位
  vector<int> ans;
  int n = a.size(), m = b.size();
  int t = 0;
  for(int i = 0; i < n || i < m; i ++ ) {
    if(i < n) t += a[i];
    if(i < m) t += b[i];
    ans.push_back(t % 10);
    t /= 10;
  }
  if(t) ans.push_back(t);
  while(ans.back() == 0) ans.pop_back();
  if(ans.empty()) ans.push_back(0);
  return ans;
}

void print(vector<int> &a) {
  while(a.back() == 0) a.pop_back();
  for(int i = a.size() - 1; i >= 0; i -- ) {
    cout << a[i];
  }
  // cout << "\n";
}