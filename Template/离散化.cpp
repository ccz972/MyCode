template<typename T> 
inline void Discrete (vector<T> &all) {
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
}

auto find = [&] (int x) { //不一定是 int  记得改
  return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
};
