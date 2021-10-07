#include "CNode.h"
#include "CList.h"

CList myList;

int main()
{
	//�t�@�C���ǂݍ���
	std::ifstream file("data/Scores.txt");  // �ǂݍ��ރt�@�C���̃p�X���w��
	if (!file)
	{
		std::cout << "�t�@�C���ǂݍ��݃G���[�i�ǂݍ��ރt�@�C�����͍����Ă��܂����H�j" << std::endl;

		getchar();
		return 0;
	}
	std::string line;//�ǂݍ��ݗp�i1�s���j
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

		//���X�g�ɒǉ�
		myList.Insert(lineNum, lineName);
	}

	//SCORE���Ƀ\�[�g
	myList.SortScore();

	//���X�g�̐擪����`��
	for (CNode *i = myList.GetDummy_First()->GetNext(); i != myList.GetDummy_End(); i = i->GetNext())
	{
	  std::cout << i->GetScore();
	  std::cout << i->GetName() << std::endl;
	}

	getchar();

	//���X�g�̍폜
	myList.Exit();

	return 0;
}

