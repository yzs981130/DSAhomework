#include <iostream>  
#include <map>  
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i != n; ++i) {
		map <int, int> p;
		int ex, value, cnt = 0;
		while (cin >> value >> ex) {
			if (ex < 0)
				cnt++;
			else 
			{
				pair <map <int, int>::iterator, bool> ret = p.insert(make_pair(ex, value));
				if (!ret.second)
					ret.first->second += value;
			}
			if (cnt == 2)
				break;
		}
		for (map <int, int>::reverse_iterator riter = p.rbegin(); riter != p.rend(); ++riter)
			if (riter->second != 0)
				cout << "[ " << riter->second << ' ' << riter->first << " ] ";
		cout << endl;
	}
	system("pause");
	return 0;
}