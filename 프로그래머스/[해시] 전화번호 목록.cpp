/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42577
개념 주소 : 
*/

// 해시를 이용한 방법 (추가 예정)

// 정렬을 이용한 방법
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size() - 1; i++) {
		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length())) {
			answer = false;
			break;
		}
	}
	return answer;
}
