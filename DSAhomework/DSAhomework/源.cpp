#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	char digits[1001];
	cin >> t;
	while (t--)
	{
		cin >> digits;
		int len = strlen(digits);
		int cnt = 1;
		for (int i = 0; i < len; i++)
		{
			if (digits[i] == digits[i + 1])
				cnt++;
			else 
			{
				cout << cnt << digits[i];
				cnt = 1;
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}