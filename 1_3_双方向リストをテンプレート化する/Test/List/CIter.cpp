//#include "CIter.h"
//
////===========================CConstIterator
///*
//  @breif	コンストラクタ
// */
//template<class T>//テンプレート化
//CConstIterator<T>::CConstIterator(TNode<T>* p)//番地を指定し、どこから始めるのかを指定
//{
//	m_node = p;
//}
//
///*
//  @breif　　リストの先頭に向かって１つ進める（）
//  @return
// */
//template<class T>//テンプレート化
//void CConstIterator<T>::GoPrevNode()
//{
//	m_node = m_node->m_prev;
//}
//
///*
//  @breif　　リストの末尾に向かって１つ進める（）
//  @return
// */
//template<class T>//テンプレート化
//void CConstIterator<T>::GoNextNode()
//{
//	m_node = m_node->m_next;
//}
//
///*
//  @breif　　イテレータの指す要素を取得する[const版]（）
//  @return　　イテレータの指す要素[const版]（）
// */
//template<class T>//テンプレート化
//TNode<T>* CConstIterator<T>::Getm_node()const { return m_node; }
//
//
//
//
////===========================CIterator
//
//
///*
//  @breif　　イテレータの指す要素を取得する[非const版]（）
//  @return　　イテレータの指す要素[非const版]（）
// */
//template<class T>//テンプレート化
//TNode<T>* CIterator<T>::Getm_node() { return m_node; }