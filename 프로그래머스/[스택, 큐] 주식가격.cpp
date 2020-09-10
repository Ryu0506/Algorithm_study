/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42584
개념 정리 : 
*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	stack<int> s;
	for (int i = 0; i < prices.size()-1;i++) {
		while (!s.empty())
			s.pop();
		s.push(prices[i]);
		for (int j = i+1; j < prices.size(); j++) {
			if (prices[i] > prices[j]) {
				s.push(prices[j]);
				break;
			}
			s.push(prices[j]);
		}
		answer.push_back(s.size()-1);
	}
	answer.push_back(0);

	return answer;
}
