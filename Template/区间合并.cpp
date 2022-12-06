#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int, int> > &segs) {  //区间合并
  if (segs.empty()) return;
  vector<pair<int, int> > res;
  sort(segs.begin(), segs.end());
  int st = segs[0].first, ed = segs[0].second;
  for (auto seg : segs) {
    if (seg.first > ed) {
      res.emplace_back(st, ed);
      st = seg.first, ed = seg.second;
    } else
      ed = max(ed, seg.second);
  }
  res.emplace_back(st, ed);
  segs = res;
}

vector<pair<int, int> > intersection(vector<pair<int, int> > a,
                                     vector<pair<int, int> > b) {
  //求区间交
  vector<pair<int, int> > res;
  int i = 0, j = 0;
  while (i < a.size() && j < b.size()) {
    int l = max(a[i].first, b[j].first);
    int r = min(a[i].second, b[j].second);
    if (l <= r) res.emplace_back(l, r);
    if (a[i].second < b[j].second)
      i++;
    else
      j++;
  }
  return res;
}