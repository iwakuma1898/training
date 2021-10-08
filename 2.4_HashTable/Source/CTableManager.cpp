#include "CTableManager.h"


bool CTableManager::Init(const char *fileName)
{
	InputEndFg = false;//初期化

	//ファイル読み込み
	std::ifstream file(fileName);  // 読み込むファイルのパスを指定
	if (!file)
	{
		printf("\n");
		printf("ファイル読み込みエラー（ファイル名が間違っていませんか？）\n");

		Clear();//終了処理

		return false;
	}

	std::string line;//読み込み用（1行ずつ）
	while (std::getline(file, line)) {  // 1行ずつ読み込む
		std::string lineKey;
		std::string lineName;
		int EndKey = line.find("\t"); //line.find("\t")でキーが終わる文字列を検索
		lineKey = line.substr(0, EndKey);//キー
		lineName = line.substr(EndKey);//キーに紐づいた英単語

		//リストに追加
		myTable.Insert(lineKey, lineName);
	}

	//開始の文
	printf("\n");
	printf("<チェイン法ハッシュテーブルのプログラム>\n");
	return true;
}

void CTableManager::Update()
{
	while (InputEndFg == false)
	{
		printf("\n");
		printf("<「家族」に関する日本語を、ローマ字で入力してください（例：haha）>\n");
		printf("<対応する英語を出力します。>\n");
		printf("\n");

		std::cin >> inputStr;//入力
		outputStr = myTable.Search(inputStr);//結果
		std::cout << "該当英単語：" << outputStr << std::endl;//出力

		printf("\n");
		printf("入力を続けますか？\n");
		printf("y：はい、入力を続けます\n");
		printf("n：いいえ、終了します\n");

		rewind(stdin);//キーボード バッファをクリア

		char YorN = getchar();//キーボードから入力した文字の一文字だけを変数に格納する変数

		if (YorN == 'n')//終了処理
		{
			InputEndFg = true;//処理抜け
			Clear();//終了処理
		}

		rewind(stdin);//キーボード バッファをクリア
	}
}


void CTableManager::Clear()
{
	printf("\n");
	printf("エンターキーで終了\n");
	rewind(stdin);//キーボード バッファをクリア
	getchar();

	//リストの削除
	myTable.Clear();
}