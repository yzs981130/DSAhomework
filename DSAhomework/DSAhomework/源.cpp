#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <stdio.h> 
#include <string.h> 
#include <algorithm> 
#include <stdlib.h> 
#include <string> 
using namespace std;

#define max1 10005 
#define max2 16 
void find(char dic[][16], char s[], int n);
//��������ĳ�������������Ƶ��ʵ����ݽṹ(used to store all replacements of a query) 
struct box
{
	int num[10005]; //��¼���Ƶ����ڴʵ��е�λ��(record the position of all replacements) 
	int top; //���Ƶ�������(the amount of the replacements) 
};
int main()
{
	char diction[max1][max2];
	int dict_num;
	char s[16];
	//���벢�洢�ʵ�(store the dictionary) 
	cin >> s;
	dict_num = -1;
	while (s[0] != '#')
	{
		dict_num++;
		strcpy(diction[dict_num], s);
		cin >> s;
	}
	//�ڴʵ��в�ѯ����(search for the word in the dictionary) 
	cin >> s;
	while (s[0] != '#')
	{
		find(diction, s, dict_num);
		cin >> s;
	}
	system("pause");
	return 0;
}
void find(char dic[][16], char s[], int n)
{
	//�������ʣ���ͬ�����Ƶ��ʵĳ��ȣ���õ�������1 
	//property��if the query is the same as the word in dictionary, or it is a replacement, then the difference of the lengths of two words will be 1 at most 
	struct box candidate;
	candidate.top = -1;
	int i, j, exist, len, diff;
	//exist��¼�Ƿ��ҵ���ͬ���ʣ�len��¼��ѯ���ʳ��ȣ�diff��ʾ��������������ĸ�� 
	//\'exist\' is used to record if it is in the dictionary, \'len\' is used to record the length of the query, \'diff\' represents the amount of different characters between two words 
	len = strlen(s);
	exist = 0;
	//���ʵ��е�ÿһ������(each word in the dictionary) 
	for (i = 0; i <= n; i++)
	{
		if (strlen(dic[i]) == len) //������ȣ�������ͬ��Ҳ�������滻һ����ĸ(the same length, check if they are the same or the word is the replacement of the query) 
		{
			if (strcmp(dic[i], s) == 0)
			{
				exist = 1;
				break;
			}
			else
			{
				diff = 0;
				for (j = 0; j < len && diff < 2; j++) //�鿴��Ӧ����ĸ��ͬ�ĵط��Ƿ��������(//check how many different characters are there between the word and the query) 
				{
					if (s[j] != dic[i][j])
						diff++;
				}
				if (j == len && diff < 2)
				{
					candidate.top++;
					candidate.num[candidate.top] = i;
				}
			}
		}
		else
		{
			if (strlen(dic[i]) == len + 1)
			{
				diff = 0;
				for (j = 0; j < len && diff < 2; j++)
				{
					if (s[j] != dic[i][j + diff]) //��ʱ����Ҫ�����ʵ䵥���е�һλ���бȽ�(skip a character of the word in the dictionary when compare two words, if is needed) 
					{
						diff++;
						j--;
					}
				}
				if (j == len && diff < 2) //��¼���Ƶ���(//record the replacements) 
				{
					candidate.top++;
					candidate.num[candidate.top] = i;
				}
			}
			else
			{
				if (strlen(dic[i]) == len - 1)
				{
					diff = 0;
					for (j = 0; j < len - 1 && diff < 2; j++)
					{
						if (s[j + diff] != dic[i][j])
							//skip a character of the word in the dictionary when compare two words, if is needed 
						{
							diff++;
							j--;
						}
					}
					if (j == len - 1 && diff < 2)
					{
						candidate.top++;
						candidate.num[candidate.top] = i;
					}
				}
			}
		}
	}
	if (exist == 1)
	{
		cout << s << " is correct" << endl;
	}
	else
	{
		cout << s << ':';
		for (j = 0; j <= candidate.top; j++)
		{
			cout << ' ' << dic[candidate.num[j]];
		}
		cout << endl;
	}
}