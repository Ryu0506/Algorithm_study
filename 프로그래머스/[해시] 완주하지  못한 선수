//정렬을 이용한 방법

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

//해시를 이용한 방법 <추가 예정>
