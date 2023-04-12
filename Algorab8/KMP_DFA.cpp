#include <iostream>
#include <cstring>
#include <memory.h>
#define MAX_STRING 1000
using namespace std;

int DFA[3][MAX_STRING];   // DFA table
int Plen, Tlen;   // Pattern length, Text length   
int n0count, strcount;   // n0count: 상태 0으로 전이하지 않는 에지의 개수, strcount: 패턴 문자열 출현 횟수

void KMP(int text[]);
void constructDFA(int pattern[]);

int main()
{
	int t;
	cin >> t;

	char text[MAX_STRING] = {};
	char pattern[MAX_STRING] = {};
	for (int i = 0; i < t; i++) {
		cin >> pattern >> text;

		Tlen = strlen(text); Plen = strlen(pattern);
		n0count = 0; strcount = 0;

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

		memset(DFA, 0, sizeof(DFA));
		
		// DFA construction
		constructDFA(Ipattern);

		/*for (int i = 0; i < 3; i++) {
			for (int j = 0; j <= Plen; j++) {
				cout << DFA[i][j] << " ";
			}
			cout << endl;
		}*/

		// KMP algorithm
		KMP(Itext);

		cout << n0count << " " << strcount << endl;
		
	}
	return 0;
}

void constructDFA(int pattern[])
{
	int X = 0;
	DFA[pattern[0]][0] = 1;

	for (int j = 1; j < Plen; j++) {
		for (int c = 0; c < 3; c++) {
			DFA[c][j] = DFA[c][X];
		}

		DFA[pattern[j]][j] = j + 1;
		X = DFA[pattern[j]][X];
	}

	// 마지막 Plen열 채우기
	for (int c = 0; c < 3; c++) {
		DFA[c][Plen] = DFA[c][X];
	}

	// 0이 아닌 에지 찾기
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= Plen; j++)
			if (DFA[i][j] != 0) n0count++;
	}
}

void KMP(int text[])
{
	for (int i = 0, j = 0; i < Tlen && j <= Plen; i++) {
		j = DFA[text[i]][j];

		//cout << j << " ";
		if (j == Plen)
			strcount++;
		else
			continue;
	}
}
