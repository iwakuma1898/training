#include "CTableManager.h"

CTableManager myTableManager;

int main()
{
	bool sts = myTableManager.Init("data/data.txt");
	if (sts==false)//�t�@�C���G���[
	{
		return 0;//�I��
	}

	myTableManager.Update();

	return 0;
}
