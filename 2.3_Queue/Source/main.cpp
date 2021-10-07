#include "CList.h"
#include "CNode.h"


CList myList;

int main()
{
	printf("\n");
	printf("<キューを用いた先入れ先出しプログラム>\n");
	printf("\n");

	//入力
	bool InputEndFg = false;//
	int DataCnt = 1;
	std::string str;

	while (InputEndFg == false)
	{
		printf("\n");
		printf("%d人目のデータを入力\n", DataCnt);
		printf("名前を入力してください：");

		std::cin >> str;//入力
		myList.Insert(DataCnt, str);//ノードを生成し挿入する

		printf("\n");
		printf("入力を続けますか？\n");
		printf("y：はい、入力を続けます\n");
		printf("n：いいえ、終了します\n");

		rewind(stdin);//キーボード バッファをクリア

		char YorN = getchar();//キーボードから入力した文字の一文字だけを変数に格納する変数

		if (YorN == 'n')//終了処理
		{
			InputEndFg = true;
		}


		DataCnt++;
	}

	//描画
	printf("\n");
	printf("<先入れ先出し順に出力>\n");
	for (CNode *i = myList.GetDummy_First()->GetNext(); i != myList.GetDummy_End(); i = i->GetNext())
	{
		std::cout << i->GetNum()<<"番目：";
		std::cout << i->GetName() << std::endl;
	}

	printf("\n");
	printf("エンターキーで終了\n");
	rewind(stdin);//キーボード バッファをクリア
	getchar();

	//リストの削除
	myList.Exit();

	return 0;
}