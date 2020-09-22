/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42746
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	vector<string> temp;
	string answer = "";
	string max;
	for (auto num : numbers)
		temp.push_back(to_string(num));
	sort(temp.begin(), temp.end(), desc);
	if (temp[0] == "0") return "0";
	for (auto num : temp)
		answer += num;
	return answer;
}
