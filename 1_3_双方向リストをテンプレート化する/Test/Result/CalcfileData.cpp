///*
//  @brief ファイルのデータを扱う関数のセット
//  @author 岩熊一樹
//  @date 10/15
// */
//
//#include "CalcfileData.h"
//
//
///*
//  @fn
//  @brief　ファイルの読み込み
//　@param　（std::ifstream &file）ファイルのデータ
//　@param　（CList m_List）挿入先のリスト
//
// */
//void DataInList(std::ifstream &file, CList m_List)
//{
//	std::string line;//読み込み用（1行ずつ）
//
//	CIterator it = m_List.GetEndIter();
//
//	while (std::getline(file, line)) {  // 1行ずつ読み込む
//		int lineNum = 0;
//		std::string lineName;
//		int NumPlace = 1;//桁の重み
//		int EndScoreNum = line.find("\t"); //line.find("\t")で数字列が終わる文字列を検索
//
//		for (int i = EndScoreNum - 1; i >= 0; i--)//数字列が終わる手前＝＝数字列を数値化する
//		{
//			lineNum += (line[i] - '0')*NumPlace;//文字列の一部を数字に変換し、桁の重みを掛けて代入
//			NumPlace *= 10;//桁を上げる
//		}
//		//残りの文字列がプレイヤー名
//		lineName = line.substr(EndScoreNum);
//
//		TRecord lineData = { lineNum, lineName };
//		//リストに追加
//		m_List.Insert(it, lineData);
//		it = m_List.GetEndIter();
//	}
//
//	//リストの先頭から描画
//	for (CIterator i = m_List.GetFirstIter(); i.m_node->m_next != m_List.GetFirstIter().m_node; i.GoNextNode())
//	{
//		std::cout << i.m_node->m_record.m_score;
//		std::cout << i.m_node->m_record->m_name << std::endl;
//	}
//}
