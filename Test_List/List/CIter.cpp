#include "CIter.h"


////==============================================================
//// �^�X�N�C�e���[�^�i�C�e���[�^�[�y�����q�z�Ƃ́A���X�g�Ȃǂ̃f�[�^�\�����ȒP�ɒH���d�g�݁j
//CIter::CTaskIter(CTaskList* list)
//	: List(list), Task(list->ActiveTask)
//{}
//
////���̃^�X�N�����鎞�ɐ^��Ԃ�
//bool CIter::HasNext() {
//	return Task->Next != List->ActiveTask;
//}
////���̃^�X�N�����o��
//CTask* CIter::Next() {
//	return Task = Task->Next;
//}
////���O�ɎQ�Ƃ����^�X�N���폜����
//void CIter::Remove() {
//	Task = Task->Prev;
//	delete Task->Next;
//}