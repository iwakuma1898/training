/*
　CNodeの派生クラス
  @brief ハッシュテーブル専用のCNodeクラス
  　　　 CList* MyList;で配列に連結しているリストを把握できる
  @author 岩熊一樹
  @date 10/6
 */


#include "CNode_Table.h"
void CNode_Table::SetMyList(CList *list) { MyList = list; }
CList* CNode_Table::GetMyList()const { return MyList; };