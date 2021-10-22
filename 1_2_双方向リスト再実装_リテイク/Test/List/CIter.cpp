#include "CIter.h"

//===========================CConstIterator
/*
  @breif	コンストラクタ
 */
CConstIterator::CConstIterator(TNode* p)//番地を指定し、どこから始めるのかを指定
{
	m_node = p;
}

/*
  @breif　　リストの先頭に向かって１つ進める（）
  @return
 */
void CConstIterator::GoPrevNode()
{
	m_node = m_node->m_prev;
}

/*
  @breif　　リストの末尾に向かって１つ進める（）
  @return
 */
void CConstIterator::GoNextNode()
{
	m_node = m_node->m_next;
}

/*
  @breif　　イテレータの指す要素を取得する[const版]（）
  @return　　イテレータの指す要素[const版]（）
 */
const TRecord& CConstIterator::GetRecord()const { return m_node->m_record; }


//===========================CIterator


/*
  @breif　　イテレータの指す要素を取得する[非const版]（）
  @return　　イテレータの指す要素[非const版]（）
 */
TRecord& CIterator::GetRecord() { return m_node->m_record; }