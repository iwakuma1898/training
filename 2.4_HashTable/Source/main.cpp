#include "CTable.h"

CTable myTable;
std::string inputStr;
std::string outputStr;

bool InputEndFg = false;//

int main()
{
	//�t�@�C���ǂݍ���
	std::ifstream file("data/data.txt");  // �ǂݍ��ރt�@�C���̃p�X���w��
	if (!file)
	{
		printf("\n");
		printf("�t�@�C���ǂݍ��݃G���[�i�t�@�C�������Ԉ���Ă��܂��񂩁H�j\n");
		rewind(stdin);//�L�[�{�[�h �o�b�t�@���N���A
		getchar();

		//���X�g�̍폜
		myTable.Exit();
		return 0;
	}

	std::string line;//�ǂݍ��ݗp�i1�s���j
	while (std::getline(file, line)) {  // 1�s���ǂݍ���
		std::string lineKey;
		std::string lineName;
		int EndKey = line.find("\t"); //line.find("\t")�ŃL�[���I��镶���������
		lineKey = line.substr(0, EndKey);//�L�[
		lineName = line.substr(EndKey);//�L�[�ɕR�Â����p�P��

		//���X�g�ɒǉ�
		myTable.Insert(lineKey, lineName);
	}

	//�Q�[�����[�v
	printf("\n");
	printf("<�`�F�C���@�n�b�V���e�[�u���̃v���O����>\n");


	while (InputEndFg == false)
	{
		printf("\n");
		printf("<�u�Ƒ��v�Ɋւ�����{����A���[�}���œ��͂��Ă��������i��Fhaha�j>\n");
		printf("<�Ή�����p����o�͂��܂��B>\n");
		printf("\n");

		std::cin >> inputStr;//����
		outputStr = myTable.Search(inputStr);//����
		std::cout << "�Y���p�P��F" << outputStr << std::endl;//�o��

		printf("\n");
		printf("���͂𑱂��܂����H\n");
		printf("y�F�͂��A���͂𑱂��܂�\n");
		printf("n�F�������A�I�����܂�\n");

		rewind(stdin);//�L�[�{�[�h �o�b�t�@���N���A

		char YorN = getchar();//�L�[�{�[�h������͂��������̈ꕶ��������ϐ��Ɋi�[����ϐ�

		if (YorN == 'n')//�I������
		{
			InputEndFg = true;
		}
		rewind(stdin);//�L�[�{�[�h �o�b�t�@���N���A
	}



	printf("\n");
	printf("�G���^�[�L�[�ŏI��\n");
	rewind(stdin);//�L�[�{�[�h �o�b�t�@���N���A
	getchar();

	//���X�g�̍폜
	myTable.Exit();

	return 0;
}
