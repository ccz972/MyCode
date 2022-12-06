#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 100010;

int n, q;
int a[N];
char s[N];

bool check(int mid) {
    int t = q;
    for (int i = mid; i < n; i ++) {
        if (a[i] > t)
            if ( -- t <= 0)
                return false;
    }
    return true;
}

int main() {
    int _;
    scanf("%d", &_);
    while (_ --) {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i ++)  scanf("%d", &a[i]);
        
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid))  r = mid;
            else  l = mid + 1;
        }
        
        for (int i = 1; i < l; i ++)
            if (a[i] <= q)  putchar('1');
            else  putchar('0');
        for (int i = l; i <= n; i ++)  putchar('1');
        puts("");
    }
    return 0;
}