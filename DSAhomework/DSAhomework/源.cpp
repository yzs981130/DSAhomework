#include <set>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
int main()
{
	vector<set<int> > ivec;
	int N = 0;
	cin >> N;
	int i = 0;
	while (i < N) 
	{
		set<int> iset;
		int num = 0;
		cin >> num;
		int j = 0;
		int docnum = 0;
		while (j < num) 
		{
			cin >> docnum;
			iset.insert(docnum);
			++j;
		}
		ivec.push_back(iset);
		++i;
	}

	int M = 0;
	cin >> M;
	map<int, vector<int> > imap;
	i = 0;
	while (i < M) 
	{
		int p = 0;
		int j = 0;
		vector<int> jvec;
		while (j < N) 
		{
			cin >> p;
			jvec.push_back(p);
			++j;
		}
		imap[i] = jvec;
		++i;
	}

	for (int x = 0; x < imap.size(); ++x) 
	{
		set<int> iresult;
		vector<int> &xvector = imap[x];
		int xx = 0;
		for (vector<int>::iterator vec_it = xvector.begin(); vec_it != xvector.end(); ++vec_it, ++xx) 
		{
			if (*vec_it == 0 || *vec_it == -1)
				continue;
			if (iresult.empty())
				iresult.insert(ivec[xx].begin(), ivec[xx].end());
			else 
			{
				set<int> iresult2;
				for (set<int>::iterator set_it = ivec[xx].begin(); set_it != ivec[xx].end(); set_it++)
					if (iresult.find(*set_it) != iresult.end())
						iresult2.insert(*set_it);
				iresult = iresult2;
				if (iresult2.empty())
					break;
			}
		}

		xx = 0;
		for (vector<int>::iterator vec_it = xvector.begin(); vec_it != xvector.end(); ++vec_it, ++xx) 
		{
			if (*vec_it == 0 || *vec_it == 1)
				continue;
			for (set<int>::iterator set_it = ivec[xx].begin(); set_it != ivec[xx].end(); set_it++)
				iresult.erase(*set_it);
		}

		if (iresult.size() < 1) 
		{
			cout << "NOT FOUND" << endl;
			continue;
		}

		for (set<int>::iterator set_it = iresult.begin(); set_it != iresult.end(); set_it++) 
			cout << *set_it << ' ';
		cout << endl;
	}
	system("pause");
	return 0;
}