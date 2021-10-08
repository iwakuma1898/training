/*
  @brief 双方向リストを構成するノード（最小単位）のクラス
  @author 岩熊一樹
  @date 10/6
 */

#include "CNode.h"

//ノードクラスのメンバ変数への代入
void CNode::SetKey(const std::string &key) { Key = key; }
void CNode::SetEngName(const std::string &name) { EngName = name; }
void CNode::SetPrev(CNode *prev) { Prev = prev; }
void CNode::SetNext(CNode *next) { Next = next; }

//ノードクラスのメンバ変数の参照
const std::string& CNode::GetKey()const { return Key; };
const std::string& CNode::GetEngName()const { return EngName; };
CNode* CNode::GetPrev()const { return Prev; };
CNode* CNode::GetNext()const { return Next; };


