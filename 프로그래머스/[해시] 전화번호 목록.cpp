/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42577
개념 주소 : 
*/

// 해시를 이용한 방법
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	unordered_map <string, int> hash;
	for (int i = 0; i < phone_book.size(); i++) {
		string number = "";
		for (int j = 0; j < phone_book[i].size(); j++) {
			number += phone_book[i][j];
			hash[number] += 1;
		}
	}
	for (auto num : phone_book) {
		if (hash[num] > 1) {
			answer = false;
			break;
		}
	}
	return answer;
}

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
