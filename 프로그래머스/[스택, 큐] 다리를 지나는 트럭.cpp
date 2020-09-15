/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42583
개념 정리 : 
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int w = 0;
	queue<int> q1, q2, q3;

	for (auto truck : truck_weights)
		q1.push(truck);

	while (!q1.empty()) {
		answer++;
		if ((answer - q3.front()) - bridge_length == 0) {
			w -= q2.front();
			q2.pop();
			q3.pop();
			
		}
		
		if (!q1.empty() && w + q1.front() <= weight) {
			w += q1.front();
			q3.push(answer);
			q2.push(q1.front());
			q1.pop();
		}
	}
	answer += bridge_length;

	return answer;
}
