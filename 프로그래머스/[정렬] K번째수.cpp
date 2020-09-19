/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42748
*/

#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++) {
		vector<int> temp;
		vector<int> ans;
		temp = commands[i];
		for (int j = temp[0] - 1; j < temp[1]; j++) 
			ans.push_back(array[j]);
	
		sort(ans.begin(), ans.end());
		answer.push_back(ans[temp[2] - 1]);
	}
	return answer;
}
