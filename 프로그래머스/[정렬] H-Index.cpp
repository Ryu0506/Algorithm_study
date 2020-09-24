/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42747
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int solution(vector<int> citations) {
	int answer = 0;
	int num;

	sort(citations.begin(), citations.end(), desc);

	num = citations[0];

	for (int i = num; i >= 0;i--) {
		int count1 = 0;
		int count2 = 0;

		for (int j = 0; j < citations.size(); j++) {
			if (citations[j] >= i) 
				count1++;
			else count2++;
		}

		if (count1 >= i && count2<=i) {
			answer = i;
			break;
		}
	}
	return answer;
}
