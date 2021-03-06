/*
  @brief スタックのクラス
  @author 岩熊一樹
  @date 10/8
 */

#include "CStack.h"

void CStack::Init()
{
	m_InputEndFg = false;
	m_DataCnt = 1;

	printf("\n");
	printf("<スタックを用いた後入れ先出しプログラム>\n");
	printf("\n");
}

void CStack::Update()
{
	while (m_InputEndFg == false)
	{
		printf("\n");
		printf("%d人目のデータを入力\n", m_DataCnt);
		printf("名前を入力してください：");

		std::cin >> m_str;//入力
		m_List.Insert(m_DataCnt, m_str);//ノードを生成し挿入する

		printf("\n");
		printf("入力を続けますか？\n");
		printf("y：はい、入力を続けます\n");
		printf("n：いいえ、終了します\n");

		rewind(stdin);//キーボード バッファをクリア

		char YorN = getchar();//キーボードから入力した文字の一文字だけを変数に格納する変数

		if (YorN == 'n')//終了処理
		{
			m_InputEndFg = true;
		}

		m_DataCnt++;
	}
}

void CStack::Draw()
{
	printf("\n");
	printf("<後入れ先出し順に出力>\n");
	for (CNode *i = m_List.GetDummy_End()->GetPrev(); i != m_List.GetDummy_First(); i = i->GetPrev())
	{
		std::cout << i->GetNum() << "番目：";
		std::cout << i->GetName() << std::endl;
	}
}

void CStack::Clear()
{
	printf("\n");
	printf("エンターキーで終了\n");
	rewind(stdin);//キーボード バッファをクリア
	getchar();

	//リストの削除
	m_List.Clear();
}