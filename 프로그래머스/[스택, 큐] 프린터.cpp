/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42587
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	int temp1, temp2, p;
	int answer = 0;
	queue<int> q;

	for (int i = 0; i < priorities.size(); i++) 
		q.push(i);
	
	while (!q.empty()) {
		for (int j = 1; j < priorities.size(); j++) {
			int max = priorities[0];
			if (priorities[j] > max) {
				temp1 = q.front();
				q.pop();
				q.push(temp1);
				temp2 = priorities[0];
				priorities.erase(priorities.begin());
				priorities.push_back(temp2);
				j = 0;
			}
		}
		p = q.front();
		q.pop();
		priorities.erase(priorities.begin());
		answer++;
		if (p == location) break;
	}

	return answer;
}
