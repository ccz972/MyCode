

double binary_search(double l, double r) {
  double lmid, rmid;
  while(r - l >= eps) {
    lmid = l + (r - l) / 3;
    rmid = r - (r - l) / 3;
    //取凸函数的最大值
    if(calc(lmid) <= calc(rmid)) { 
      l = lmid;
    } else {
      r = rmid;
    }
  }
  return l;
}