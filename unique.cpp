#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
class GT_cls
{
public:
	GT_cls(std::string st=""):str(st){}
	bool operator()(const std::string& s){
		return s>str;
	}
private:
	std::string str;
};
template <class T>
class EQ_cls
{
public:
	EQ_cls(T val):value(val){}
	bool operator()(T spval){
		return value==spval;
	}
private:
	T value;
};

void Test(){
	std::vector<int> ivec;
	int ival;
	cout<<"Enter numbers (ctrl+z to end) :"<<endl;
	while(cin>>ival)
		ivec.push_back(ival);
	cin.clear();//使流重新有效
	int replacedVal,newVal;
	cout<<"Enter a value that will be replaced :";
	cin>>replacedVal;
	cout<<"Enter a new value :";
	cin>>newVal;
	replace_if(ivec.begin(),ivec.end(),EQ_cls<int>(replacedVal),newVal);
	cout<<"New sequence :"<<endl;
	for(vector<int>::const_iterator iter=ivec.begin();iter!=ivec.end();iter++)
		cout<<*iter<<endl;
} 

//page451 习题14.35

bool isShorter(const string&s1,const string&s2){
	return s1.size()<s2.size();
}
class BET_cls
{
public:
	BET_cls(string::size_type len1,string::size_type len2){
		if(len1<len2){
			minLength=len1;
			maxLength=len2;
		}
		else{
			minLength=len2;
			maxLength=len1;
		}
	}
	bool operator()(const string& s){
		return s.size()>=minLength&&s.size()<=maxLength;
	}
private:
	string::size_type minLength;
	string::size_type maxLength;
};

//如果ctrl不为1，则返回word的复数版本
string make_plural(size_t ctr,const string&word,const string&ending){
	return (ctr==1)? word:word+ending;
}

void TestBET_cls(const char* fileptr){
	ifstream inFile;
	inFile.open(fileptr);
	if(!inFile){
		cerr<<"Can not open the input file"<<endl;
		exit(1);
	}
	vector<string> words;
	string word;
	//读输入文件
	while(inFile>>word){
		words.push_back(word);
	}
	//对输入排序，以便除去重复的单词
	sort(words.begin(),words.end());
	//除去相同的单词
	words.erase(unique(words.begin(),words.end()),words.end());
	//按照单词长度排序，相同长度按字典序排序
	stable_sort(words.begin(),words.end(),isShorter);
	//统计数量
	//for(vector<string>::const_iterator iter=words.begin();iter!=words.end();iter++)
		//cout<<*iter<<endl;
	vector<string>::size_type wc=count_if(words.begin(),words.end(),BET_cls(1,9));
	cout<<wc<<" "<<make_plural(wc,"word","s")<<" are of sizes 1 through 10 inclusice"<<endl;

}
