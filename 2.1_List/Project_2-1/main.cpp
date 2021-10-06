#include "CNode.h"
#include "CList.h"

List myList;

int main()
{
	myList.Init("data/Scores.txt");

	myList.Draw();

	getchar();
	return 0;
}
