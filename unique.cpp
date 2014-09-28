//除去数组中的重复元素
#include <iostream>
using namespace std;
int UniqueArray(int * array,int len){
	int tra=0,rlt=0;
	while(tra<len){
		if(array[tra]!=array[rlt]){
			array[++rlt]=array[tra]; //核心
		}
		++tra;
	}
	return ++rlt;
}
int main(int argc, char* argv[])
{
	int array[]={12,13,13,15,15,15,17};
	int len=sizeof(array)/sizeof(int);
	int end=UniqueArray(array,len);
	for(int i=0;i<end;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	return 0;
}

