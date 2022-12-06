struct SuffixArray {
	static const int N = 200010;

	int sa[N], rk[N], ht[N];
	bool t[N << 1];
	int hv[19][N];

	bool islms(const int i, const bool *t) {
		return i > 0 && t[i] && !t[i - 1];
	}

	template<class T> 
	inline void sort(T s, int *sa, const int len, const int sz, const int sigma, 
																						bool *t, int *b, int *cb, int *p) {
		memset(b, 0, sizeof (int)*sigma);
		memset(sa, -1, sizeof (int)*len);
		for(int i = 0; i < len; i ++ ) b[(int)s[i]] ++;
		cb[0] = b[0];
		for(int i = 1; i < sigma; i ++ ) cb[i] = cb[i - 1] + b[i];
		for(int i = sz - 1; i >= 0; i -- ) sa[-- cb[(int)s[p[i]]]] = p[i];
		for(int i = 1; i < sigma; i ++ ) cb[i] = cb[i - 1] + b[i - 1];
		for(int i = 0; i < len; i ++ ) if(sa[i] > 0 && !t[sa[i] - 1]) 
			sa[cb[(int)s[sa[i] - 1]] ++] = sa[i] - 1;
		cb[0] = b[0];	
		for(int i = 1; i < sigma; i ++ ) cb[i] = cb[i - 1] + b[i];
		for(int i = len - 1; i >= 0; i -- ) if(sa[i] > 0 && t[sa[i] - 1])
			sa[-- cb[(int)s[sa[i] - 1]]] = sa[i] - 1;

	}
	template<class T> 
	inline void sais(T s, int *sa, const int len, bool *t, int *b, int *b1, const int sigma) {
		int p = -1, *cb = b + sigma;
		t[len - 1] = 1;
		for(int i = len - 2; i >= 0; i -- ) t[i] = s[i] < s[i + 1] || (s[i] == s[i + 1] && t[i + 1]);
		int sz = 0, cnt = 0;
		for(int i = 1; i < len; i ++ ) if(t[i] && !t[i - 1]) b1[sz ++ ] = i;
			
	}
}