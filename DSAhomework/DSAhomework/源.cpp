#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

map<char, int> operatorPriority;

string Transform(const string& str) {
	int len = str.length();
	char rt[90];
	int cnt = 0;
	stack<char> oper;
	for (int i = 0; i < len; ++i) {
		if (str[i] == '-')
			i = i;
		if (str[i] == ' ')
			continue;
		else if (isalnum(str[i]))
			rt[cnt++] = str[i];
		else { /* is an operator */
			switch (str[i])
			{
			case'(':
				oper.push('(');
				break;
			case')':
				while (oper.top() != '(') {
					rt[cnt++] = oper.top();
					oper.pop();
				}
				oper.pop();
				break;
				/* + - * operator */
			default:
				if (!oper.empty()) {
					char top = oper.top();
					if (operatorPriority[top] >= operatorPriority[str[i]]) {
						rt[cnt++] = top;
						oper.pop();
					}
				}
				oper.push(str[i]);
				break;
			}
		}
	}
	while (!oper.empty()) {
		rt[cnt++] = oper.top();
		oper.pop();
	}
	rt[cnt] = '\0';
	return string(rt);
}


int Calculate(string r) {
	int len = r.length(), a, b;
	stack<int> cal;
	for (int i = 0; i < len; ++i) {
		if (isalnum(r[i])) {
			if (isdigit(r[i]))
				cal.push(r[i] - '0');
			else
				cal.push(r[i]);
		}
		else {
			a = cal.top();
			cal.pop();
			b = cal.top();
			cal.pop();
			switch (r[i]) {
			case '+':
				cal.push(b + a);
				break;
			case '-':
				cal.push(b - a);
				break;
			case '*':
				cal.push(b * a);
			}
		}
	}
	return cal.top();
}

int main() {

	operatorPriority['+'] = 1;
	operatorPriority['-'] = 1;
	operatorPriority['*'] = 2;
	operatorPriority['('] = 0;
	int cases;
	cin >> cases;
	cin.get();
	while (cases--) {
		string exp1, exp2;
		getline(cin, exp1);
		getline(cin, exp2);
		if (Calculate(Transform(exp1)) == Calculate(Transform(exp2)))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}