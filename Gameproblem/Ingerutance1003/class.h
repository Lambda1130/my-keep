#pragma once
#include<iostream>
using namespace std;

//■継承とは？
//あるクラス基に新しいクラスを作ることができる
//これを継承という

//今回はClassBaseを基に新しいクラスを作成する
//基になるクラスのことを基底クラスと呼ぶ
class ClassBase
{
public:
	ClassBase() :
		m_num(0)
	{
		//基底クラスのコンストラクタを明示的に呼ばない場合
		//継承先のクラスのコンストラクタ呼び出し前に
		//引数無しの継承元のコンストラクタが呼び出される

		cout << "ClassChildのコンストラクタ" << m_num << endl;
	}

	ClassBase(int num):
		m_num(num)
	{
		cout << "ClassBaseのコンストラクタ" <<m_num<< endl;
	}

	~ClassBase()
	{
		cout << "ClassBaseのデストラクタ" <<m_num<< endl;
	}

	void Func0()
	{
		cout << "ClassBase::Func0" <<m_num<< endl;
	}
	void Func1()
	{
		cout << "ClassBase::Func1" << m_num << endl;
	}
	void Func2()
	{
		cout << "ClassBase::Func2" << m_num << endl;
	}

	//privateなメンバーはクラス外から参照できない
	//それは継承先のクラスでも同様
	//継承先のクラスがa基底クラスの持つ変数を変更したい場合はよくある
private:
	//位置情報や攻撃力など、基底クラスに持たせて
	//継承先でも変更を行いたい変数はいくらでもある
	
	//そういう場合はprotectedで宣言する
	//protectedな場合、関数はクラス外からは見えないが、
	//継承先のクラスからは見ることができる

	//よくわからない間は基底クラスのメンバ変数は
	//すべてprotectedでいいと思う
protected:

	void ProtectedFunc()
	{
		cout << "protectedな関数" << endl;
	}

	int m_num;
};

//ClassBaseを基に新しいクラスを作成する
//ClassBaseを継承して新しいクラスを作成する

//クラスの宣言時に継承元となるクラスを指定する必要がある
class ClassChikd0 : public ClassBase
{
public:
	ClassChikd0()
	{
		cout << "ClassChild0のコンストラクタ"<< endl;
	}
	ClassChikd0(int num) :
		ClassBase(num)  //継承先クラスのコンストラクタを明示的に呼ぶ
	{
		cout << "ClassChild0の引数付きのコンストラクタ" << endl;
	}

	~ClassChikd0()
	{
		cout << "ClassChild0のデストラクタ" << endl;

		//継承先のデストラクタが呼ばれた後.
		//継承元のデストラクタが呼ばれる
	}
};

//同じくClassBaseを継承したクラス
class ClassChild1 :public ClassBase
{
public:
	ClassChild1()
	{
		cout << "ClassChild1のコンストラクタ" << endl;
	}
	~ClassChild1()
	{
		cout << "ClassChild1のデストラクタ" << endl;
	}

	//基底クラスのFunc0を使うのではなく
	//このクラスの特殊な処理を行いたい
	void Func0()
	{
		cout << "ClassChild1の特殊なFunc0" << endl;

		//protecedな変数、関数は継承先から呼び出すことができる
		m_num = 999;
		ProtectedFunc();
	}

};