/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42839
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int num1, int num2) {
	return num1 > num2;
}

int solution(string numbers) {
	int answer = 0;

	sort(numbers.begin(), numbers.end(), desc);
	int max = stoi(numbers);
	
	bool *numberset = new bool[max + 1];
	for (int i = 0; i <= max; i++)
		numberset[i] = false;
	numberset[1] = true;

	for (int i = 2; i*i <= max; i++) {
		if (numberset[i]==false) {
			for (int j = i * i; j <= max; j += i) {
				numberset[j] = true;
			}
		}
	}
	
	for (int index = 2; index <= max; index++) {
		if (numberset[index] == false) {
			int prime = index;
			int j;
			char temp[8], orit[8];

			numbers.copy(temp, sizeof(temp) - 1);
			temp[numbers.size()] = '\0';

			for (j = 0; j < 8; j++) {
				orit[j] = (prime % 10) + '0';
				prime /= 10;
				if (prime == 0)
					break;
			}

			int count = -1;

			for (int i = 0; i <= j; i++) {
				for (int k = 0; k < numbers.size(); k++) {
					if (orit[i] == temp[k]) {
						temp[k] = -1;
						count++;
						break;
					}
				}
			}
			if (count == j)
				answer++;
		}	
	}
	return answer;
}
