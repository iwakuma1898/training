#include "../List/TNode.h"
#include "../List/CList.h"

#include "../List/CalcfileData.h"

CList myList;

int main()
{
	//ファイル読み込み
	std::ifstream file("../List/data/Scores.txt");  // 読み込むファイルのパスを指定
	if (!file)
	{
		std::cout << "ファイル読み込みエラー（読み込むファイル名は合っていますか？）" << std::endl;

		getchar();
		return 0;
	}

	//ファイルデータをリストにセット
	DataInList(file, myList);

	//リストの先頭から描画
	for (TNode *i = myList.GetDummy_First()->m_next; i != myList.GetDummy_End(); i = i->m_next)
	{
		std::cout << i->m_record.m_score;
		std::cout << i->m_record.m_name << std::endl;
	}


	getchar();

	//リストの削除
	myList.Exit();

	return 0;
}


