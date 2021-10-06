#pragma once
#include <string>

class CNode
{
private:
	int Score;
	std::string Name;

	CNode *Prev, *Next;//�^�X�N�̑O��֌W���w���|�C���^

public:

	void SetScore(int score) { Score = score; }
	void SetName(std::string name) { Name = name; }
	void SetPrev(CNode *prev) { Prev = prev; }
	void SetNext(CNode *next) { Next = next; }

	int GetScore() { return Score; };
	std::string GetName(){ return Name; };
	CNode* GetPrev() { return Prev; };
	CNode* GetNext() { return Next; };
};


