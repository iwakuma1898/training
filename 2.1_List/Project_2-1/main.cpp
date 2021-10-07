#include "CNode.h"
#include "CList.h"

CList myList;

int main()
{
	//ファイル読み込み
	std::ifstream file("data/Scores.txt");  // 読み込むファイルのパスを指定
	if (!file)
	{
		std::cout << "ファイル読み込みエラー（読み込むファイル名は合っていますか？）" << std::endl;

		getchar();
		return 0;
	}
	std::string line;//読み込み用（1行ずつ）
	while (std::getline(file, line)) {  // 1行ずつ読み込む
		int lineNum = 0;
		std::string lineName;
		int NumPlace = 1;//桁の重み
		int EndScoreNum = line.find("\t"); //line.find("\t")で数字列が終わる文字列を検索

		for (int i = EndScoreNum - 1; i >= 0; i--)//数字列が終わる手前＝＝数字列を数値化する
		{
			lineNum += (line[i] - '0')*NumPlace;//文字列の一部を数字に変換し、桁の重みを掛けて代入
			NumPlace *= 10;//桁を上げる
		}
		//残りの文字列がプレイヤー名
		lineName = line.substr(EndScoreNum);

		//リストに追加
		myList.Insert(lineNum, lineName);
	}

	//SCORE順にソート
	myList.SortScore();

	//リストの先頭から描画
	for (CNode *i = myList.GetDummy_First()->GetNext(); i != myList.GetDummy_End(); i = i->GetNext())
	{
	  std::cout << i->GetScore();
	  std::cout << i->GetName() << std::endl;
	}

	getchar();

	//リストの削除
	myList.Exit();

	return 0;
}

