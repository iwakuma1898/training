#include "../List/TRecord.h"

#include "../List/CList.h"

#include "../List/CIter.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


int main()
{
	CList<TRecord> myList;

	//�t�@�C���ǂݍ���
	std::ifstream file("../List/data/Scores.txt");  // �ǂݍ��ރt�@�C���̃p�X���w��
	if (!file)
	{
		std::cout << "�t�@�C���ǂݍ��݃G���[�i�ǂݍ��ރt�@�C�����͍����Ă��܂����H�j" << std::endl;

		getchar();
		return 0;
	}

	//�t�@�C���f�[�^�����X�g�ɃZ�b�g
	//DataInList(file, myList);

	//����main�֐����ł����Ⴒ����Ə����Ă��܂��Ă��܂����A����͍������ŁA�����łł͊֐������Ă܂Ƃ߂܂�

	std::string line;//�ǂݍ��ݗp�i1�s���j

	CIterator<TRecord> it = myList.GetEndIter();

	while (std::getline(file, line)) {  // 1�s���ǂݍ���
		int lineNum = 0;
		std::string lineName;
		int NumPlace = 1;//���̏d��
		int EndScoreNum = line.find("\t"); //line.find("\t")�Ő����񂪏I��镶���������

		for (int i = EndScoreNum - 1; i >= 0; i--)//�����񂪏I����O����������𐔒l������
		{
			lineNum += (line[i] - '0')*NumPlace;//������̈ꕔ�𐔎��ɕϊ����A���̏d�݂��|���đ��
			NumPlace *= 10;//�����グ��
		}
		//�c��̕����񂪃v���C���[��
		lineName = line.substr(EndScoreNum);

		TRecord lineData = { lineNum, lineName };
		//���X�g�ɒǉ�
		myList.Insert(it, lineData);
		it = myList.GetEndIter();
	}

	//���X�g�̐擪����`��
	for (CIterator<TRecord> i = myList.GetFirstIter(); i.m_node->m_next != myList.GetFirstIter().m_node; i.GoNextNode())
	{
		std::cout << i.GetRecord()->m_score;
		std::cout << i.GetRecord()->m_name << std::endl;
	}

	getchar();


	return 0;
}


