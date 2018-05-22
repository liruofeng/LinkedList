#include "stdafx.h"
#include <Windows.h>
#include "LinkList.h"

//无参构造函数，初始化成员
template<class T_ELE>
LinkList<T_ELE>::LinkList()
	:m_pList(NULL), m_dwLength(0){}

//析构函数
template<class T_ELE>
LinkList<T_ELE>::~LinkList()
{
	Clear();
	printf("析构函数已调用！\n");
	
}

//判断链表是否为空
template<class T_ELE>
BOOL LinkList<T_ELE>::IsEmpty()
{
	if (m_pList == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//清空链表
template<class T_ELE>
void LinkList<T_ELE>::Clear()
{
	if (m_pList == NULL || m_dwLength == 0)//when the list is enpty.
	{
		
		return;
	}
	
	//2.循环删除链表的节点
	
	PNODE TemNode = m_pList;
	PNODE next_Node = NULL;

for (int k = 0;k < m_dwLength - 1;k++)
{
	next_Node = TemNode->pNext;
	delete TemNode;
	TemNode = next_Node;
}
 
    m_dwLength = 0;
    m_pList = NULL;
	
}

template<class T_ELE>
DWORD LinkList<T_ELE>::GetElement(IN DWORD dwIndex, OUT T_ELE & Element)
{
	PNODE aim_NODE = GetIndexCurrentNode(dwIndex);
	memcpy(Element, &aim_NODE->Data, sizeof(T_ELE));
	return SUCCESS;
}

template<class T_ELE>
DWORD LinkList<T_ELE>::GetElementIndex(IN T_ELE Element)
{
	PNODE TemNode = m_pList;
	for(int m = 0;m<m_dwLength-1;m++)
	{
		if (!memcmp(&Element, &TemNode->Data, sizeof(T_ELE)))
		{
			printf("索引：%x", m+1);
			return m;
		}
		TemNode = TemNode->pNext;
	}
	printf("当前要查找的元素不存在!");
	return INDEX_ERROR;
}

//在尾部新增节点
template<class T_ELE>
DWORD LinkList<T_ELE>::Insert(IN T_ELE Element)
{

	PNODE pNewNode = new NODE;
	memset(pNewNode, 0, sizeof(NODE));
	memcpy(&pNewNode->Data, &Element, sizeof(T_ELE));
	//1.判断链表是否为空
	if (m_pList == NULL || m_dwLength == 0)//when the list is enpty.
	{
		m_pList = pNewNode;
		m_dwLength++;
		return SUCCESS;
	}
	//2.链表中存在其他元素
	PNODE TemNode = m_pList;
	for(int i = 0;i<m_dwLength-1;i++)
	{
		TemNode = TemNode->pNext;
	}
	TemNode->pNext = pNewNode;
	m_dwLength++;
	
	return SUCCESS;
	
}

template<class T_ELE>
DWORD LinkList<T_ELE>::Insert(IN DWORD dwIndex, IN T_ELE Element)
{
	if (dwIndex <= 0 || dwIndex >= m_dwLength)
	{
		printf("插入链表时请输入合理的范围");
		return INDEX_ERROR;
	}
	
	
	PNODE pNewNode = new NODE;
	memset(pNewNode, 0, sizeof(NODE));
	memcpy(&pNewNode->Data, &Element, sizeof(T_ELE));

	//1.判断链表是否为空
	if (m_pList == NULL || m_dwLength == 0)//when the list is enpty.
	{
		m_pList = pNewNode;
		m_dwLength++;
		return SUCCESS;
	}
	PNODE previous_NODE = GetIndexPreviousNode(dwIndex);
	PNODE IndexNext_NODE = GetIndexCurrentNode(dwIndex);
	previous_NODE->pNext = pNewNode;
	pNewNode->pNext = IndexNext_NODE;
	m_dwLength++;
	return SUCCESS;
}

template<class T_ELE>
DWORD LinkList<T_ELE>::Delete(IN DWORD dwIndex)
{
	
	if (m_pList == NULL || m_dwLength == 0 )//when the list is enpty.
	{
		return SUCCESS;
	}
	PNODE de_NODE = GetIndexCurrentNode(dwIndex);//要删除的节点
	PNODE previous_NODE = GetIndexPreviousNode(dwIndex);//要删除的节点的前一个节点
	PNODE de_next_NODE = GetIndexNextNode(dwIndex);//要删除的节点的下一个节点
	previous_NODE->pNext = de_next_NODE;
	delete de_NODE;
	de_NODE = NULL;
	m_dwLength--;
	return SUCCESS;



	
}

template<class T_ELE>
DWORD LinkList<T_ELE>::GetSize()
{
	return m_dwLength;
}

template<class T_ELE>
typename LinkList<T_ELE>::PNODE LinkList<T_ELE>::GetIndexCurrentNode(DWORD dwIndex)
{
	PNODE temnode = m_pList;
	for (int n = 0;n < dwIndex - 1;n++)
	{
		temnode = temnode->pNext;
	}
	return temnode;
}

template<class T_ELE>
typename LinkList<T_ELE>::PNODE LinkList<T_ELE>::GetIndexPreviousNode(DWORD dwIndex)
{
	PNODE temnode = m_pList;
	for (int n = 0;n < dwIndex - 2;n++)
	{
		temnode = temnode->pNext;
	}
	return temnode;
}

template<class T_ELE>
typename LinkList<T_ELE>::PNODE LinkList<T_ELE>::GetIndexNextNode(DWORD dwIndex)
{
	PNODE temnode = m_pList;
	for (int n = 0;n < dwIndex ;n++)
	{
		temnode = temnode->pNext;
	}
	return temnode;
}




void test()
{
	LinkList<int>* pLink = new LinkList<int>();

	pLink->Insert(1);
	pLink->Insert(2);
	pLink->Insert(3);



}


int main()
{
	test();
	return 0;
	
}

