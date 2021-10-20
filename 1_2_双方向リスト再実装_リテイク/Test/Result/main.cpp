#include "../List/TNode.h"
#include "../List/CList.h"

#include "CalcfileData.h"

CList myList;

int main()
{
	//�t�@�C���ǂݍ���
	std::ifstream file("../List/data/Scores.txt");  // �ǂݍ��ރt�@�C���̃p�X���w��
	if (!file)
	{
		std::cout << "�t�@�C���ǂݍ��݃G���[�i�ǂݍ��ރt�@�C�����͍����Ă��܂����H�j" << std::endl;

		getchar();
		return 0;
	}

	//�t�@�C���f�[�^�����X�g�ɃZ�b�g
	DataInList(file, myList);

	//���X�g�̐擪����`��
	for (CIterator i = myList.GetFirstIter(); i.GetData()->m_next != myList.GetFirstIter().GetData(); i.GoNextNode())
	{
		std::cout << i.GetData()->m_record.m_score;
		std::cout << i.GetData()->m_record.m_name << std::endl;
	}



	getchar();


	myList.Clear();


	return 0;
}


