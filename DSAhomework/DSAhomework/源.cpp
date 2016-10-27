#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int t = 0, cnt = 0;
enum TOKEN_TYPE
{
	TYPE_NUMBER,
	TYPE_UNIT,
	TYPE_NEGATIVE
};
struct Token
{
	string        StringValue;
	int            Value;
	TOKEN_TYPE    Type;
};
Token sTokenTable[] =
{
	{ "zero",        0, TYPE_NUMBER },
	{ "one",            1, TYPE_NUMBER },
	{ "two",            2, TYPE_NUMBER },
	{ "three",        3, TYPE_NUMBER },
	{ "four",        4, TYPE_NUMBER },
	{ "five",        5, TYPE_NUMBER },
	{ "six",            6, TYPE_NUMBER },
	{ "seven",        7, TYPE_NUMBER },
	{ "eight",        8, TYPE_NUMBER },
	{ "nine",        9, TYPE_NUMBER },
	{ "ten",            10, TYPE_NUMBER },
	{ "eleven",        11, TYPE_NUMBER },
	{ "twelve",        12, TYPE_NUMBER },
	{ "thirteen",    13, TYPE_NUMBER },
	{ "fourteen",    14, TYPE_NUMBER },
	{ "fifteen",        15, TYPE_NUMBER },
	{ "sixteen",        16, TYPE_NUMBER },
	{ "seventeen",    17, TYPE_NUMBER },
	{ "eighteen",    18, TYPE_NUMBER },
	{ "nineteen",    19, TYPE_NUMBER },
	{ "twenty",        20, TYPE_NUMBER },
	{ "thirty",        30, TYPE_NUMBER },
	{ "forty",        40, TYPE_NUMBER },
	{ "fifty",        50, TYPE_NUMBER },
	{ "sixty",        60, TYPE_NUMBER },
	{ "seventy",        70, TYPE_NUMBER },
	{ "eighty",        80, TYPE_NUMBER },
	{ "ninety",        90, TYPE_NUMBER },
	{ "hundred",        100, TYPE_UNIT },
	{ "thousand",    1000, TYPE_UNIT },
	{ "million",        1000000, TYPE_UNIT },
	{ "negative",    -1, TYPE_NEGATIVE }
};
string GetTokenStr(const string &value)
{
	cnt = 0;
	stringstream ss;
	string str[30];
	ss << value;
	while (ss)
	{
		ss >> str[cnt];
		cnt++;
	}
	if (!t)
		return str[cnt - 2];
	return str[cnt - t - 1];
}
bool GetToken(const string &value, Token &nextToken)
{
	bool bRet = false;
	string tokenStr = GetTokenStr(value);
	t++;

	for (int i = 0; i < 32; ++i)
	{
		if (tokenStr == sTokenTable[i].StringValue)
		{
			nextToken.Type = sTokenTable[i].Type;
			nextToken.Value = sTokenTable[i].Value;
			bRet = true;
			break;
		}
	}
	return bRet;
}
long Parse(const string& value)
{
	long ans = 0;
	bool neg = false;
	Token NToken;
	int CUV = 1;

	while (GetToken(value, NToken))
	{
		switch (NToken.Type)
		{
		case TYPE_NEGATIVE:
			neg = true;break;

		case TYPE_NUMBER:
			ans += NToken.Value * CUV;break;

		case TYPE_UNIT:
			if (NToken.Value >= CUV)
				CUV = NToken.Value;
			else
				CUV *= NToken.Value;
			break;
		}
		if (t == cnt)
			break;
	}
	if (neg)
		ans = -ans;
	return ans;
}
int main() 
{
	string s;
	while(getline(cin, s) && !s.empty())
	{
		t = 0;
		Token NextToken;
		GetToken(s, NextToken);
		cout << Parse(s) << endl;
	}
	system("pause");
	return 0;
}