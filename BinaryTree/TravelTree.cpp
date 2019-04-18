#include<cstdio>
#include<iostream>
#include"C:\Users\Administrator\Desktop\code\jianzhi\BinaryTree\BinaryTree.h"
using namespace std;

void PreOrderTravel(BinaryTreeNode* pNode){
	if(pNode!=0){
		cout<<pNode->value<<" ";
         PreOrderTravel(pNode->pLeft);
	     PreOrderTravel(pNode->pRight);
	 }
}
void InOrderTravel(BinaryTreeNode* pNode){
	if(pNode!=0){
		InOrderTravel(pNode->pLeft);
		cout<<pNode->value<<" ";
		InOrderTravel(pNode->pRight);
	}
}


void PosOrderTravel(BinaryTreeNode* pNode){
	if(pNode!=0){
		PosOrderTravel(pNode->pLeft);
		PosOrderTravel(pNode->pRight);
		cout<<pNode->value<<" ";
	}
}

void Test1(){
	BinaryTreeNode* pNode1=CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode2=CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode3=CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4=CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5=CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6=CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode7=CreateBinaryTreeNode(16);
	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, pNode6, pNode7);
	PreOrderTravel(pNode1);
	cout<<endl;
	InOrderTravel(pNode1);
	cout<<endl;
	PosOrderTravel(pNode1);
}







int main(){
	Test1();
	return 0;
}
