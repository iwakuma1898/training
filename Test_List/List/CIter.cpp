#include "CIter.h"


////==============================================================
//// タスクイテレータ（イテレーター【反復子】とは、リストなどのデータ構造を簡単に辿れる仕組み）
//CIter::CTaskIter(CTaskList* list)
//	: List(list), Task(list->ActiveTask)
//{}
//
////次のタスクがある時に真を返す
//bool CIter::HasNext() {
//	return Task->Next != List->ActiveTask;
//}
////次のタスクを取り出す
//CTask* CIter::Next() {
//	return Task = Task->Next;
//}
////直前に参照したタスクを削除する
//void CIter::Remove() {
//	Task = Task->Prev;
//	delete Task->Next;
//}