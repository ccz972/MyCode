
int ne[N], nextval[N], last;
char s[N], t[N];

void add(char x) { //将x加进s的末尾，并更新ne数组的值,利用nextval加快匹配过程，导致每次匹配最多log(n)次
  int j = last;
  while (j && s[ne[j] + 1] != x) j = nextval[j]; //kmp过程
  //把当前字符加进 s 
  s[++last] = x, j = ne[j] + 1; //last为字符串 s 的长度
  if (last == 1) {
    ne[1] = nextval[1] = 0;
  } else if (s[j] == x) {
    ne[last] = j;
    if (s[ne[j] + 1] == s[j + 1]) {
      nextval[last] = nextval[j];
    } else {
      nextval[last] = j;
    }
  } else {
    ne[last] = nextval[last] = 0;
  }
}