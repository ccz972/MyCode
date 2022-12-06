// Problem: D. Fixed Point Guessing
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int>PII;

int n;
bool st[100004];

int query(int l,int r){
	cout<<"? "<<l<<' '<<r<<endl;
	for(int i=l;i<=r;i++)st[i]=false;
	for(int i=1;i<=r-l+1;i++){
		int x;
		cin>>x;
		if(x>r)st[x]=false;
		else st[x]=true;
	}
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)st[i]=true;
	int r=n;
	while(1){
		if(r&1)r=(r+1)/2;
		else r=r/2;
		query(1,r);
		if(r<=1){
			break;
		}
	}
	for(int i=1;i<=n;i++)if(st[i]){
		cout<<"! "<<i<<endl;
	}
}

signed main()
{
	int T=1;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
