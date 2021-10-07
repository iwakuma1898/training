/*
  @brief 双方向リストを構成するノード（最小単位）のクラス
  @author 岩熊一樹
  @date 10/6
 */

#include "CNode.h"

//ノードクラスのメンバ変数への代入
void CNode::SetNum(const int &num) { Num = num; }
void CNode::SetName(const std::string &name) { Name = name; }
void CNode::SetPrev(CNode *prev) { Prev = prev; }
void CNode::SetNext(CNode *next) { Next = next; }

//ノードクラスのメンバ変数の参照
int CNode::GetNum()const { return Num; };
std::string CNode::GetName()const { return Name; };
CNode* CNode::GetPrev()const { return Prev; };
CNode* CNode::GetNext()const { return Next; };