#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
#define INLINE __attribute__((optimize("O3"))) inline
const int maxN = 110010;

int Rank[maxN * 2], sa[maxN], h[maxN], text[maxN];
char s[maxN];
int N, M, L;

void getSA() {
	int rr = 0;
	for (int i = 1; i <= L; i++) {
		text[i] = s[i] - 'a' + 1;
		if (text[i] == 27) text[i] += rr++;
	}
	static int cnt[maxN], q[maxN], t[maxN];
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= L; i++) cnt[text[i]] = 1;
	for (int i = 1; i <= 30 + L; i++) cnt[i] += cnt[i - 1];
	for (int i = 1; i <= L; i++) Rank[i] = cnt[text[i]];
	for (int len = 1; len < L; len *= 2) {
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= L; i++) cnt[Rank[i + len]] ++;
		for (int i = 1; i <= L; i++) cnt[i] += cnt[i - 1];
		for (int i = 1; i <= L; i++) q[cnt[Rank[i + len]]--] = i;
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= L; i++) cnt[Rank[i]] ++;
		for (int i = 1; i <= L; i++) cnt[i] += cnt[i - 1];
		for (int i = L; i; i--) t[cnt[Rank[q[i]]]--] = q[i];
		q[1] = 1;
		for (int i = 2; i <= L; i++) q[i] = q[i - 1] + \
			(Rank[t[i]] != Rank[t[i - 1]] || Rank[t[i] + len] != Rank[t[i - 1] + len]);
		for (int i = 1; i <= L; i++) Rank[t[i]] = q[i];
	}
	for (int i = 1; i <= L; i++) sa[Rank[i]] = i;
	for (int i = 1, len = 0; i <= L; i++) {
		if (len) len--;
		while (text[i + len] == text[sa[Rank[i] - 1] + len]) len++;
		h[Rank[i]] = len;
	}
}

int a[110];

void init() {
	memset(s, 0, sizeof s);
	memset(Rank, 0, sizeof Rank);
	memset(sa, 0, sizeof sa);
	memset(h, 0, sizeof h);
	memset(text, 0, sizeof text);
	L = 0;
	a[0] = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%s\n", s + L + 1);
		L += strlen(s + L + 1) + 1;
		s[L] = 'z' + 1;
		a[i] = L;
	}
	getSA();
}

int ty[maxN];

bool check(int len) {
	if (!len) return true;
	static bool c[110];
	memset(c, 0, sizeof c);
	int cnt = 1;
	c[ty[1]] = true;
	for (int i = 2; i <= M; i++) {
		if (h[i]<len) {
			memset(c, 0, sizeof c);
			c[ty[i]] = true;
			cnt = 1;
		}
		else {
			if (!c[ty[i]]) cnt++;
			c[ty[i]] = true;
			if (cnt>N >> 1) return true;
		}
	}
	return false;
}

void printAns(int len) {
	vector<string>v;
	static bool c[110];
	memset(c, 0, sizeof c);
	int cnt = 1;
	c[ty[1]] = true;
	for (int i = 2; i <= M; i++) {
		if (h[i]<len) {
			if (cnt>N / 2) {
				v.push_back(string(s + sa[i - 1], s + sa[i - 1] + len));
			}
			memset(c, 0, sizeof c);
			c[ty[i]] = true;
			cnt = 1;
		}
		else {
			if (!c[ty[i]]) cnt++;
			c[ty[i]] = true;
		}
	}
	if (cnt>N / 2) {
		v.push_back(string(s + sa[M], s + sa[M] + len));
	}
	sort(v.begin(), v.end());
	vector<string>::iterator u = unique(v.begin(), v.end());
	for (vector<string>::iterator i = v.begin(); i != u; i++) {
		puts(i->c_str());
	}
}

void solve() {
	int le = 0, ri = 0;
	for (int i = 0; i<N; i++) ri = max(ri, a[i + 1] - a[i]);
	M = 0;
	for (int i = 1; i <= L; i++) {
		if (text[sa[i]] >= 27) break;
		M = i;
		ty[i] = lower_bound(a, a + N, sa[i]) - a + 1;
	}
	while (le + 1<ri) {
		int mid = (le + ri) / 2;
		if (check(mid)) le = mid;
		else ri = mid;
	}
	if (le)
		printAns(le);
	else
		puts("?");
	puts("");
}

int main() {
	while (scanf("%d\n", &N), N) {
		init();
		if (N == 1) {
			puts(string(s + 1, s + L).c_str());
			puts("");
		}
		else
			solve();
	}
	return 0;
}