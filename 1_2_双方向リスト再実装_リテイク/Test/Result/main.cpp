#include "../List/TNode.h"
#include "../List/CList.h"

#include "CalcfileData.h"

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
	for (CIterator i = myList.GetFirstIter(); i.GetData()->m_next != myList.GetFirstIter().GetData(); i.GoNextNode())
	{
		std::cout << i.GetData()->m_record.m_score;
		std::cout << i.GetData()->m_record.m_name << std::endl;
	}



	getchar();


	myList.Clear();


	return 0;
}


