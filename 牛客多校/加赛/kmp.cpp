#include <bits/stdc++.h>

#ifdef LOCAL
	#include <debugger>
#endif

int main() {
	int n; 
	std::cin >> n;

	std::string p;
	std::cin >> p;

	p = " " + p;

	std::vector<int> next(n + 1);

	for(int j = 1, k = 0; j < n; ) {
		if (k == 0 || p[j] == p[k]) {
			++ j, ++ k;
			next[j] = k;
		} else {
			k = next[k];
		}
	}
  // debug(next);
	int m; 
	std::cin >> m;

	std::string s;
	std::cin >> s;
	s = " " + s;

  if (n == 1) {
    for (int i = 1; i <= m; i ++ ) if (s[i] == p[1]) {
      std::cout << i - 1 << " ";
    }
    return 0;
  }

	for(int i = 1, j = 1; i < m ;  ) {

		if (j == 0 || s[i] == p[j]) {
			++ i, ++ j;
		} else {
			j = next[j];
		}
    std::cout << i << " " << j << "\n";
		if (j == n) {
			std::cout << i - n << "\n";
			j = next[j];
		}
	}

	return 0;
}