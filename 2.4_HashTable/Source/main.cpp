#include "CTableManager.h"

CTableManager myTableManager;

int main()
{
	bool sts = myTableManager.Init("data/data.txt");
	if (sts==false)//ファイルエラー
	{
		return 0;//終了
	}

	myTableManager.Update();

	return 0;
}
