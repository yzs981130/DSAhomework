#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() 
{
	string a, b;
	cin >> a >> b;
	int an = a.size(), bn = b.size();
	vector< int > v(an + bn);
	for (int i = 0; i < an; ++i)
		for (int j = 0; j < bn; ++j) {
			v[i + j] += (a[an - 1 - i] - '0') * (b[bn - 1 - j] - '0');
			if (v[i + j] >= 10) {
				v[i + j + 1] += v[i + j] / 10;
				v[i + j] %= 10;
			}
		}
	int cn = an + bn - 1;
	if (v[cn]) ++cn;
	while (cn > 1 && 0 == v[cn - 1]) --cn;
	string res = "";
	for (int i = cn - 1; i >= 0; --i)
		res += char(v[i] + '0');
	cout << res << endl;
	system("pause");
	return 0;
}