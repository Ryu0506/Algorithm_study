/*문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42576
개념 정리 : */

// 해시를 이용한 방법
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> um;
	for (auto name : participant) {
		um[name]++;
	}
	for (auto name : completion) {
		um[name]--;
	}
	for (auto name : participant) {
		if (um[name] > 0) {
			answer = name;
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

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	for (int i = 0; i < participant.size(); i++) {
		if (participant[i] != completion[i]) {
			answer = participant[i];
			break;
		}
	}
	return answer;
}
