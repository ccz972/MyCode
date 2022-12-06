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
void solve() {
	// int n, m; cin >> n >> m;
	int n, m; scanf("%d %d", &n, &m);
	while (n -- ) {
		int ac_cnt, Time; 
		// cin >> ac_cnt >> Time;
		scanf("%d %d", &ac_cnt, &Time);
		vector<int> a;
		struct node {int op; int l, r; };
		vector<node> status(m);
		int cnt_positive = 0; //, cnt_negative = 0;
		int error_Time = 0;
		Rep(i, 0, m) {
			char op[2]; scanf("%s", op); //cin >> op;
			if (op[0] == '+') {
				int use_Time, current_Time;
				scanf("%d/%d", &use_Time, &current_Time);
				error_Time += use_Time * 20 - 20 + current_Time;
				++ cnt_positive;
				status[i] = {0, use_Time, current_Time};
			} else if (op[0] == '-') {
				int Error; scanf("%d", &Error);
				status[i] = {1, Error, -1};
			} else if (op[0] == '?') {
				int last_submit, all_submit;
				scanf("%d %d", &last_submit, &all_submit);
				// a.emplace_back(last_submit, all_submit);
				a.emplace_back(i);
				status[i] = {2, last_submit, all_submit};
			} else if (op[0] == '.') {
				status[i] = {3, -1, -1};
				continue;
			} else {
				printf("%c\n", op[0]);
				exit(0);
				assert(false);
			}
		}
		
		bool Flag = (cnt_positive + SZ(a) >= ac_cnt) && (cnt_positive <= ac_cnt);
		
		if (!Flag) { cout << "No\n"; continue; }
		
		if (cnt_positive == ac_cnt) {
			if (error_Time != Time) {
				cout << "No\n"; continue;
			}
		}
		
		int mm = SZ(a);
		int last_accept = ac_cnt - cnt_positive;
		bool flag = false;
		// printf("> %d\n", error_Time);
		for (int i = 0; i < 1 << mm; i ++ ) if (__builtin_popcount(i) == last_accept) {
			int cnt_480 = 0, Last_Error_Time = 0;
			int low = 0, high = 0;
			for (int j = 0; j < mm; j ++ ) if (i >> j & 1) {
				cnt_480 ++;
				auto [op, l, all] = status[a[j]];
				low += (all - l) * 20;
				// Last_Error_Time += (all - l) * 20;
				high += (all - 1) * 20 + 60;
			}
			
			int All_Time = cnt_480 * 240; // + Last_Error_Time;
			low += error_Time + All_Time;
			high += error_Time + All_Time;
			// printf("%d %d %d\n", low, high, Time);
			if (Time >= low && Time <= high) {
				flag = true;
				cout << "Yes\n";
				int dist = Time - low;
				for (int j = 0; j < mm; j ++ ) if (i >> j & 1) {
					auto [op, l, all] = status[a[j]];	
					if (dist) {
						if (dist >= (l - 1) * 20 + 60) {
							dist -= (l - 1) * 20 + 60;
							status[a[j]] = {0, all, 300};
						} else {
							if (dist >= (l - 1) * 20) {
								dist -= (l - 1) * 20;
								status[a[j]] = {0, all, dist + 240};
							} else {
								int ERROR_TIME = dist / 20;
								dist %= 20;
								status[a[j]] = {0, all - l + ERROR_TIME + 1, dist + 240};
							}
						}
					} else {
						status[a[j]] = {0, all - l + 1, 240};
					}
				} else {
					auto [op, l, all] = status[a[j]];	
					status[a[j]] = {1, all, -1};
				}
				
				for (int j = 0; j < m; j ++ ) {
					auto [op, l, all] = status[j];
					if (op == 0) {
						printf("+ %d/%d\n", l, all);
					} else if (op == 1) {
						printf("- %d\n", l);
					} else if (op == 3) {
						puts(".");
					} else {
						assert(false);
					}
				} 
				
				break;
			}
		}
		if (!flag) {
			cout << "No\n";
		}
	}
}

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	int T = 1; // cin >> T;
	while (T -- )
	solve();
	
	return 0;
}