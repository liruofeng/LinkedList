#pragma once
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "LinkList.h"





#define SUCCESS 1
#define INDEX_ERROR -2
#define BUFFER_EMPTY -3




template<class T_ELE>
class LinkList
{
	
	
public:
	//无参构造函数
	LinkList();
	//析构函数
	~LinkList();
public:
	BOOL IsEmpty();                                                //判断链表是否为空，空返回1，否则返回0
	void Clear();                                                  //清空链表
	DWORD GetElement(IN DWORD dwIndex, OUT T_ELE& Element);        //根据索引获取元素
	DWORD GetElementIndex(IN T_ELE Element);                       //根据元素获取链表中的索引
	DWORD Insert(IN T_ELE Element);                                //新增链表
	DWORD Insert(IN DWORD dwIndex, IN T_ELE Element);              //根据索引新增元素
	DWORD Delete(IN DWORD dwIndex);                                //根据索引删除元素
	DWORD GetSize();                                               //获取链表中元素的数量 



private:
	 typedef struct _NODE
	{
		T_ELE Data;
		_NODE* pNext;
	}NODE, *PNODE;
	
	PNODE GetIndexCurrentNode(DWORD dwIndex);                     //获取索引为dwIndex的指针
	PNODE GetIndexPreviousNode(DWORD dwIndex);                    //获取索引为dwIndex的前一个节点的指针
	PNODE GetIndexNextNode(DWORD dwIndex);                        //获取索引为dwIndex的下一个节点的指针

	

private:
	PNODE m_pList;                                               //链表头指针
	DWORD m_dwLength;                                            //链表中元素的数量

};

