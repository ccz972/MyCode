#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define chkmax(x, y) (x) = (x) >= (y) ? (x) : (y)
#define chkmin(x, y) (x) = (x) <= (y) ? (x) : (y)
#define PII pair<int, int>
#define SZ(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ ) 
#define debug(x) cout << #x << " : " << x << "\n"
mt19937 rng(random_device{}());
int rnd(int x) {
	return rng() % x;
}
#define int ll 
int n, m;

void Solve() {
	int ac_cnt, Time; 
	scanf("%lld %lld", &ac_cnt, &Time);
	vector<int> a;
	struct node {int op; int l, r; };
	vector<node> status(m);
	int cnt_positive = 0; //, cnt_negative = 0;
	ll error_Time = 0;
	Rep(i, 0, m) {
		char op[2]; scanf("%s", op); //cin >> op;
		if (op[0] == '+') {
			int use_Time, current_Time;
			scanf("%lld/%lld", &use_Time, &current_Time);
			error_Time += (ll)use_Time * 20 - 20 + (ll)current_Time;
			++ cnt_positive;
			status[i] = {0, use_Time, current_Time};
		} else if (op[0] == '-') {
			int Error; scanf("%lld", &Error);
			status[i] = {1, Error, -1};
		} else if (op[0] == '?') {
			int last_submit, all_submit;
			scanf("%lld %lld", &last_submit, &all_submit);
			// a.emplace_back(last_submit, all_submit);
			a.emplace_back(i);
			status[i] = {2, last_submit, all_submit};
		} else if (op[0] == '.') {
			status[i] = {3, -1, -1};
		} else {
			assert(false);
		}
	}
	
	bool Flag = (cnt_positive + SZ(a) >= ac_cnt) && (cnt_positive <= ac_cnt);
	
	if (!Flag) { puts("No"); return; }
	
	if (cnt_positive == ac_cnt) {
		if (error_Time != Time) {
			puts("No"); return ;
		} else {
			puts("Yes"); 
			for (int j = 0; j < m; j ++ ) {
				auto [op, l, all] = status[j];
				if (op == 0) {
					printf("+ %lld/%lld\n", l, all);
				} else if (op == 2) {
					printf("- %lld\n", all);
				} else if (op == 1) {
					printf("- %lld\n", l);
				} else if (op == 3) {
					puts(".");
				} else {
					assert(false);
				}
			}
			return ;
		}
	}
	
	int mm = SZ(a);
	int last_accept = ac_cnt - cnt_positive;
	bool flag = false;
	for (int i = 0; i < 1 << mm; i ++ ) if (__builtin_popcountll(i) == last_accept) {
		ll cnt_480 = 0; // Last_Error_Time = 0;
		ll low = 0, high = 0;
		for (int j = 0; j < mm; j ++ ) if (i >> j & 1) {
			cnt_480 ++;
			auto [op, l, all] = status[a[j]];
			low += (ll)(all - l) * 20;
			high += (ll)(all - 1) * 20 + 59;
		}
		
		int All_Time = cnt_480 * 240; 
		
		low += error_Time + All_Time;
		high += error_Time + All_Time;
		assert(low <= high);
		if (Time >= low && Time <= high) {
			flag = true;
			puts("Yes");
			int dist = Time - low;
			for (int j = 0; j < mm; j ++ ) if (i >> j & 1) {
				auto [op, l, all] = status[a[j]];	
				if (dist) {
					if (dist >= (l - 1) * 20 + 59) {
						dist -= (l - 1) * 20 + 59;
						status[a[j]] = {0, all, 299};
					} else {
						if (dist >= (l - 1) * 20) {
							dist -= (l - 1) * 20;
							status[a[j]] = {0, all, dist + 240};
							dist = 0;
						} else {
							int ERROR_TIME = dist / 20;
							dist %= 20;
							// printf("> %lld\n", all - l + ERROR_TIME + 1);
							assert(ERROR_TIME < l - 1);
							status[a[j]] = {0, all - l + ERROR_TIME + 1, dist + 240};
							dist = 0;
						}
					}
				} else {
					status[a[j]] = {0, all - l + 1, 240};
				}
			} else {
				auto [op, l, all] = status[a[j]];	
				status[a[j]] = {1, all, -1};
			}
			
			assert(dist == 0);
			
			int ALL_TIME = 0;
			int CNT_ACCEPT = 0;
			for (int j = 0; j < m; j ++ ) {
				auto [op, l, all] = status[j];
				if (op == 0) {
					ALL_TIME += (l - 1) * 20 + all;
					CNT_ACCEPT ++;
				}
			}
			// assert(CNT_ACCEPT == ac_cnt && ALL_TIME == Time);
			// assert(ALL_TIME <= Time);
			
			for (int j = 0; j < m; j ++ ) {
				auto [op, l, all] = status[j];
				if (op == 0) {
					printf("+ %lld/%lld\n", l, all);
				} else if (op == 1) {
					printf("- %lld\n", l);
				} else if (op == 3) {
					puts(".");
				} else {
					assert(false);
				}
			} 
			
			return ;
		}
	}
	if (!flag) {
		puts("No");
	}
}

void solve() {
	scanf("%lld %lld", &n, &m);
	
	while (n -- ) {
		Solve();
	}
}

signed main() {
	int T = 1; 
	while (T -- )
	solve();
	
	return 0;
}