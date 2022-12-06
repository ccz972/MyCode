#include <bits/stdc++.h>
using namespace std;

int f[100], g[100];

void init(){
	g[1] = 1;
	for(int i = 2; i < 10; i ++)
		g[i] = 2 * g[i - 1] + 1;
}



void solve(){
	init();
	f[1] = 1;
	for(int i = 2; i < 10; i ++){
		f[i] = g[i];
		for(int j = 1; j <= i - 1; j ++){
			f[i] = min(f[i], 2 * g[j] + g[i - j]);
		}
	}
	for(int i = 1; i < 6; i ++)
		cout << f[i] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
