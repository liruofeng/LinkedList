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
	//�޲ι��캯��
	LinkList();
	//��������
	~LinkList();
public:
	BOOL IsEmpty();                                                //�ж������Ƿ�Ϊ�գ��շ���1�����򷵻�0
	void Clear();                                                  //�������
	DWORD GetElement(IN DWORD dwIndex, OUT T_ELE& Element);        //����������ȡԪ��
	DWORD GetElementIndex(IN T_ELE Element);                       //����Ԫ�ػ�ȡ�����е�����
	DWORD Insert(IN T_ELE Element);                                //��������
	DWORD Insert(IN DWORD dwIndex, IN T_ELE Element);              //������������Ԫ��
	DWORD Delete(IN DWORD dwIndex);                                //��������ɾ��Ԫ��
	DWORD GetSize();                                               //��ȡ������Ԫ�ص����� 



private:
	 typedef struct _NODE
	{
		T_ELE Data;
		_NODE* pNext;
	}NODE, *PNODE;
	
	PNODE GetIndexCurrentNode(DWORD dwIndex);                     //��ȡ����ΪdwIndex��ָ��
	PNODE GetIndexPreviousNode(DWORD dwIndex);                    //��ȡ����ΪdwIndex��ǰһ���ڵ��ָ��
	PNODE GetIndexNextNode(DWORD dwIndex);                        //��ȡ����ΪdwIndex����һ���ڵ��ָ��

	

private:
	PNODE m_pList;                                               //����ͷָ��
	DWORD m_dwLength;                                            //������Ԫ�ص�����

};

