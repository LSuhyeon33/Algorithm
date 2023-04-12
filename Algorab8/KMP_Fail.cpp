#include <iostream>
#include <cstring>
#include <vector>
#define MAX_STRING 1000
using namespace std;

int Plen, Tlen;   // Pattern length, Text length   
int strcount;   // strcount: 패턴 문자열 출현 횟수

void KMP(int text[], int patter[]);

int main()
{
	int t;
	cin >> t;

	char text[MAX_STRING] = {};
	char pattern[MAX_STRING] = {};
	for (int i = 0; i < t; i++) {
		cin >> pattern >> text;

		Tlen = strlen(text); Plen = strlen(pattern);
		strcount = 0;

		// char -> int
		// 'A' = 0, 'B' = 1, 'C' = 2
		int Itext[MAX_STRING] = {};
		for (int i = 0; i < Tlen; i++) {
			Itext[i] = text[i] - 'A';
		}
		int Ipattern[MAX_STRING] = {};
		for (int i = 0; i < Plen; i++) {
			Ipattern[i] = pattern[i] - 'A';
		}

		// KMP algorithm
		KMP(Itext, Ipattern);
	}
	return 0;
}

vector<int> Fail_func(int pattern[])
{
	vector<int> fail(Plen, 0);
	
	for (int i = 1, j = 0; i < Plen; i++) {
		while (pattern[i] != pattern[j] && j > 0)
			j = fail[j - 1];
		if (pattern[i] == pattern[j])
			fail[i] = ++j;
	}
	return fail;
}

void KMP(int text[], int pattern[])
{
	vector<int> fail(Plen, 0);
	fail = Fail_func(pattern);

	for (int i = 0, j = 0; i < Tlen; i++) {
		while (j > 0 && text[i] != pattern[j])
			j = fail[j - 1];
		if (text[i] == pattern[j]) {
			if (j == Plen - 1) {
				strcount++;
				j = fail[j];
			}
			else
				j++;
		}
	}

	for (int i = 0; i < Plen; i++) {
		cout << fail[i] << " ";
	}
	cout << endl;

	cout << strcount << endl;
}
