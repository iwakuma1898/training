#include "../List/TNode.h"
#include "../List/CList.h"

#include "../List/CalcfileData.h"

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
	for (TNode *i = myList.GetDummy_First()->m_next; i != myList.GetDummy_End(); i = i->m_next)
	{
		std::cout << i->m_record.m_score;
		std::cout << i->m_record.m_name << std::endl;
	}


	getchar();

	//���X�g�̍폜
	myList.Exit();

	return 0;
}


