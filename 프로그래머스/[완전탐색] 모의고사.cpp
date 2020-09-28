/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42840
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> temp;
	vector<int> one = { 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5 };
	vector<int> two = { 2,1,2,3,2,4,2,5, 2,1,2,3,2,4,2,5, 2,1,2,3,2,4,2,5, 2,1,2,3,2,4,2,5, 2,1,2,3,2,4,2,5 };
	vector<int> three = { 3,3,1,1,2,2,4,4,5,5, 3,3,1,1,2,2,4,4,5,5, 3,3,1,1,2,2,4,4,5,5, 3,3,1,1,2,2,4,4,5,5 };
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int index = 0;
	int max = 0;

	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == one[index]) count1++;
		if (answers[i] == two[index]) count2++;
		if (answers[i] == three[index]) count3++;

		index++;

		if (index > 39) index = 0;
	}

	temp.push_back(count1); temp.push_back(count2); temp.push_back(count3);
	sort(temp.begin(), temp.end());
	max = temp[2];

	if (max == count1)
		answer.push_back(1);
	if (max == count2)
		answer.push_back(2);
	if (max == count3) 
		answer.push_back(3);

	return answer;
}
