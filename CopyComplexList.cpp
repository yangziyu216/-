#include<iostream>
#include<cstdio>
using namespace std;

struct ComplexListNode{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

ComplexListNode* CreateListNode(int value){
    ComplexListNode* pNode = new ComplexListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = 0;
    pNode->m_pSibling=0L;
    return pNode;
}
 
void ConnectListNode(ComplexListNode* pCurrent, ComplexListNode* pNext){
    if(pCurrent == 0){
        printf("Error to connect two nodes.\n");
        exit(1);
    }
 
    pCurrent->m_pNext = pNext;
}
//First step;
void CloneNodes(ComplexListNode *pHead){
	ComplexListNode *pNode=pHead;
	while(pNode!=0){
		ComplexListNode *pCloned=new ComplexListNode();
		pCloned->m_pNext=pNode->m_pNext;
		pCloned->m_nValue=pNode->m_nValue;
		pCloned->m_pSibling=0;
		pNode->m_pNext=pCloned;
		pNode=pCloned->m_pNext;
	}
}
//Second step
void ConnectSiblingNodes(ComplexListNode *pHead){
	ComplexListNode *pNode=pHead;
	while(pNode!=0){
		ComplexListNode *pCloned=pNode->m_pNext;
		if(pNode->m_pSibling!=0){
			pCloned->m_pSibling=pNode->m_pSibling->m_pNext;
	   }
		pNode=pCloned->m_pNext;
	}
}
//Third step
ComplexListNode* ReconnectNodes(ComplexListNode* pHead){
	ComplexListNode *pNode=pHead;
	ComplexListNode *pClonedHead=0;
	ComplexListNode *pClonedNode=0;
	if(pNode!=0){
		pClonedHead=pClonedNode=pNode->m_pNext;
		pNode->m_pNext=pClonedNode->m_pNext;
		pNode=pNode->m_pNext;
	}
	while(pNode!=0){
		pClonedNode->m_pNext=pNode->m_pNext;
		pClonedNode=pClonedNode->m_pNext;
		pNode->m_pNext=pClonedNode->m_pNext;
		pNode=pNode->m_pNext;
	}
	return pClonedHead;
}

ComplexListNode* Clone(ComplexListNode *pHead){
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	ComplexListNode* pClonedNode=ReconnectNodes(pHead);
	while(pClonedNode!=0){
		cout<<pClonedNode->m_nValue;//->m_pSibling这里输出的是位置 而不是数字 
		pClonedNode=pClonedNode->m_pNext;
	}
}
void Text(const char* textname,ComplexListNode* pHead){
	if(textname!=0){
		cout<<"start!";
	}
	Clone(pHead);
	cout<<"end!";
}
void Text1(){
	ComplexListNode *pNode1=CreateListNode(1);
	ComplexListNode *pNode2=CreateListNode(2);
	ComplexListNode *pNode3=CreateListNode(3);
	ComplexListNode *pNode4=CreateListNode(4);
	ComplexListNode *pNode5=CreateListNode(5);
	pNode5->m_pSibling=pNode1;
	pNode3->m_pSibling=pNode2;
	ConnectListNode(pNode1,pNode2);
	ConnectListNode(pNode2,pNode3);
	ConnectListNode(pNode3,pNode4);
	ConnectListNode(pNode4,pNode5);
	Text("Text1",pNode1);
}

// 鲁棒性测试
void Text5()
{
    Text("Test5", 0);
}
int main(){
	Text1();
	Text5(); 
	return 0;
}
