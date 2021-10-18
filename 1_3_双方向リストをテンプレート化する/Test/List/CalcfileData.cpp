/*
  @brief �t�@�C���̃f�[�^�������֐��̃Z�b�g
  @author ��F���
  @date 10/15
 */

#include "CalcfileData.h"


/*
  @fn
  @brief�@�t�@�C���̓ǂݍ���
�@@param�@�istd::ifstream &file�j�t�@�C���̃f�[�^
�@@param�@�iCList m_List�j�}����̃��X�g

 */

template<class T>//�e���v���[�g��
void DataInList(std::ifstream &file, CList<T> m_List)
{
	std::string line;//�ǂݍ��ݗp�i1�s���j

	CIterator<T> it = m_List.GetDummyEnd();

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
		m_List.Insert(it, lineData);
	}
}
