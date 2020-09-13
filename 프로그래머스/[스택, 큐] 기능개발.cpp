/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42586
개념 정리 : 
*/

#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q1, q2;
	int d = 1;
	
	for (int i = 0; i < progresses.size(); i++) {
		q1.push(progresses[i]);
		q2.push(speeds[i]);
	}

	while (!q1.empty()) {
		int cnt = 0;
		int k = q1.size();
		for (int j = 0; j < k; j++) {
			if (q1.front() + (q2.front() * d) >= 100) {
				cnt++;
				q1.pop();
				q2.pop();
			}
		}
		if (cnt > 0)
			answer.push_back(cnt);
		d++;
	}
	return answer;
}
