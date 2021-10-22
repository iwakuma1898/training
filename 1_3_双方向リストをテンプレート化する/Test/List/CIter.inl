#pragma once


//===========================CConstIterator
/*
  @breif	コンストラクタ
 */
template<class T>
CConstIterator<T>::CConstIterator(TNode<T>* p)//番地を指定し、どこから始めるのかを指定
	: m_node(p)
{
	//m_node = p;
}

/*
  @breif　　リストの先頭に向かって１つ進める（）
  @return
 */
template<class T>
void CConstIterator<T>::GoPrevNode()
{
	m_node = m_node->m_prev;
}

/*
  @breif　　リストの末尾に向かって１つ進める（）
  @return
 */
template<class T>
void CConstIterator<T>::GoNextNode()
{
	m_node = m_node->m_next;
}

/*
  @breif　　イテレータの指す要素を取得する[const版]（）
  @return　　イテレータの指す要素[const版]（）
 */
template<class T>
//const T& CConstIterator<T>::GetRecord()const { return m_node->m_record; }
const T* CConstIterator<T>::GetRecord()const { return m_node->m_record; }


//===========================CIterator


/*
  @breif　　イテレータの指す要素を取得する[非const版]（）
  @return　　イテレータの指す要素[非const版]（）
 */
template<class T>
//T& CIterator<T>::GetRecord() { return m_node->m_record; }
T* CIterator<T>::GetRecord() { return m_node->m_record; }