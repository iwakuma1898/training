///*
//  @brief �t�@�C���̃f�[�^�������֐��̃Z�b�g
//  @author ��F���
//  @date 10/15
// */
//
//#include "CalcfileData.h"
//
//
///*
//  @fn
//  @brief�@�t�@�C���̓ǂݍ���
//�@@param�@�istd::ifstream &file�j�t�@�C���̃f�[�^
//�@@param�@�iCList m_List�j�}����̃��X�g
//
// */
//void DataInList(std::ifstream &file, CList m_List)
//{
//	std::string line;//�ǂݍ��ݗp�i1�s���j
//
//	CIterator it = m_List.GetEndIter();
//
//	while (std::getline(file, line)) {  // 1�s���ǂݍ���
//		int lineNum = 0;
//		std::string lineName;
//		int NumPlace = 1;//���̏d��
//		int EndScoreNum = line.find("\t"); //line.find("\t")�Ő����񂪏I��镶���������
//
//		for (int i = EndScoreNum - 1; i >= 0; i--)//�����񂪏I����O����������𐔒l������
//		{
//			lineNum += (line[i] - '0')*NumPlace;//������̈ꕔ�𐔎��ɕϊ����A���̏d�݂��|���đ��
//			NumPlace *= 10;//�����グ��
//		}
//		//�c��̕����񂪃v���C���[��
//		lineName = line.substr(EndScoreNum);
//
//		TRecord lineData = { lineNum, lineName };
//		//���X�g�ɒǉ�
//		m_List.Insert(it, lineData);
//		it = m_List.GetEndIter();
//	}
//
//	//���X�g�̐擪����`��
//	for (CIterator i = m_List.GetFirstIter(); i.m_node->m_next != m_List.GetFirstIter().m_node; i.GoNextNode())
//	{
//		std::cout << i.m_node->m_record.m_score;
//		std::cout << i.m_node->m_record->m_name << std::endl;
//	}
//}
