#include <iostream>
#include <string>
using namespace std;
int main() 
{
	string str, substr;
	while(cin >> str >> substr)
	{
		char max_c = str[0];
		for (int i = 1; i < str.length(); i++)
			if (str[i] > max_c)
				max_c = str[i];
		int pos = str.find(max_c);
		str.insert(pos + 1, substr);
		cout << str << endl;
	}
	system("pause");
	return 0;
}