#include <cstdio>
#include <stack>
#include<iostream>
using namespace std;
bool IsPopOrder(const int* pPush,const int* pPop,int nLength){
	bool bPossible=false;
	if(pPush!=0&&pPop!=0&&nLength>0){
		const int*pNextPush=pPush;
		const int*pNextPop=pPop;
		std::stack<int>stackData;
		while(pNextPop-pPop<nLength){
			while(stackData.empty()||stackData.top()!=*pNextPop){
				if(pNextPush-pPush==nLength)
				    break;
				stackData.push(*pNextPush);
				pNextPush++;
			}
			if(stackData.top()!=*pNextPop)
			    break;
		stackData.pop();
		pNextPop++;
		}  
		if(stackData.empty()&&pNextPop-pPop==nLength)
		    bPossible=true; 
	}
	return bPossible;
}
void Test(const char*textName,const int* pPush,const int* pPop,int nLength,bool expected){
	if(textName!=0){
		cout<<"start!";
	}
	if(IsPopOrder(pPush,pPop,nLength)==expected){
		cout<<"true!";
	}
	else
	   cout<<"false";
}
void Test1(){
	int nLenth=5;
	int pPush[5]={1,2,3,4,5};
	int pPop[5]={5,4,3,2,1};
	Test("Text1",pPush,pPop,5,"true");
}
int main(){
	Test1();
	return 0;
}
