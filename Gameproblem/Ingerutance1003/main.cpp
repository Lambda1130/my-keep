#include<iostream>
#include"class.h"
using namespace std;


int main()
{

	cout << "継承の勉強" << endl;

	ClassChikd0 testClass{100};
	ClassChikd0 testClass2;
	//継承先が持っていなくても
	//基底クラスが持つ関数を呼び出すことができる
	testClass.Func0();
	testClass.Func1();
	testClass.Func2();

	testClass2.Func0();
	testClass2.Func1();
	testClass2.Func2();

	//protectedなメンバーは
	//クラス外からアクセスできない

#if  false
	ClassBase testClass{0};

	cout << "++++++" << endl;

	ClassBase* pTestClass = new ClassBase{1};
	delete pTestClass;
#endif
	return 0;
}