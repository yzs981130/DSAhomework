#include <iostream>
#include <string>
using namespace std;
int main() 
{
	int cnt;
	string str;
	cin >> cnt;
	cin.ignore();
	while(cnt--)
	{
		getline(cin, str);
		for (int i = 0; i < str.length(); i++)
		{
			if ((str[i] < 'z' && str[i] >= 'a') || (str[i] < 'Z' && str[i] >= 'A'))
				cout << char(str[i] + 1);
			else if (str[i] == 'z')
				cout << 'a';
			else if (str[i] == 'Z')
				cout << 'A';
			else
				cout << str[i];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}