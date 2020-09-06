/*
문제 주소 : https://programmers.co.kr/learn/courses/30/lessons/42578?language=cpp
개념 정리 :  
*/

//중복 제거 따로 한 경우
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> hash;
	for (int i = 0; i < clothes.size(); i++)
	{
		string cloth = clothes[i][1];
		hash[cloth] += 1;
	}
	vector <string> no_dupli;
	for (int i = 0; i < clothes.size(); i++)
		no_dupli.push_back(clothes[i][1]);

	sort(no_dupli.begin(), no_dupli.end());
	no_dupli.erase(unique(no_dupli.begin(), no_dupli.end()), no_dupli.end());

	for (auto cloth : no_dupli)
		answer *= (hash[cloth] + 1);
	
	return answer - 1;
}

//조건문을 통한 중복 제거
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> hash;
	vector <string> no_dupli;

	for (int i = 0; i < clothes.size(); i++)
	{
		string cloth = clothes[i][1];
		if (hash[cloth] == 0) 
		{
			hash[cloth] = 1;
			no_dupli.push_back(cloth);
		}
		else 
			hash[cloth] += 1;
	}

	for (auto cloth : no_dupli)
		answer *= (hash[cloth] + 1);
	
	return answer - 1;
}
