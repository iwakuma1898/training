/*
  @brief スタックのクラス
  @author 岩熊一樹
  @date 10/8
 */

#include "CQueue.h"

void CQueue::Init()
{
	m_InputEndFg = false;
	m_DataCnt = 1;

	printf("\n");
	printf("<キューを用いた先入れ先出しプログラム>\n");
	printf("\n");
}

void CQueue::Update()
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

void CQueue::Draw()
{
	printf("\n");
	printf("<先入れ先出し順に出力>\n");
	for (CNode *i = m_List.GetDummy_First()->GetNext(); i != m_List.GetDummy_End(); i = i->GetNext())
	{
		std::cout << i->GetNum() << "番目：";
		std::cout << i->GetName() << std::endl;
	}
}

void CQueue::Clear()
{
	printf("\n");
	printf("エンターキーで終了\n");
	rewind(stdin);//キーボード バッファをクリア
	getchar();

	//リストの削除
	m_List.Clear();
}