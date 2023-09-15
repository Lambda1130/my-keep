#include<stdio.h>

typedef struct Student
{
	int no;
	float height;
	float weight;

}Student;


int main(void)
{
	Student stu[3];

	stu[0].no = 1;
	stu[0].height = 160.0f;
	stu[0].weight = 55.5f;

	stu[1].no = 2;
	stu[1].height = 170.0f;
	stu[1].weight = 65.5f;

	stu[2].no = 3;
	stu[2].height = 150.0f;
	stu[2].weight = 45.5f;

	for (int i = 0; i < 3; i++)
	{
		printf("%d: 身長%fcm　体重%fkg\n", stu[i].no,stu[i].height,stu[i].weight);
	}

	return 0;
}







/*
//構造体の復習

typedef struct TestScore
{
	int kokugo;
	int sansu;
	int rika;
	int syakai;
}TestScore;

//構造体の宣言
typedef struct StudentDate
{
	int no;        
	float height;
	float weight;

	TestScore score;
}StudentDate;

//生徒のデータを表示する関数
void disaStudentDate(StudentDate date)
{
	printf("出席番号%d\n", date.no);
	printf("身長%f\n", date.height);
	printf("算数の点数%d\n", date.score.sansu);
}

//生徒の出席番号を変更する関数
//date: 出席番号を変更したい生徒のデータ
//nextNo: どの出席番号に変更したいか
void changeStudentNo(StudentDate* pDate, int nextNo)
{
//	date.no = nextNo;     //与えられた生徒のデータの出席番号を引数の値に変更する
	pDate->no = nextNo;
}

int main(void)
{
	StudentDate student1 = { 10,155.5f,45.8f,{50,60,70,80} };
	 //構造体のメンバにアクセスする
	 student1.no = 7;
	 student1.height = 160.5f;
	 student1.weight = 55.5f;
	 student1.score.kokugo = 50;
	 student1.score.sansu = 60;
	 student1.score.rika = 70;
	 student1.score.syakai = 80;

	 StudentDate student2;

	 student2 = student1;
	
	 disaStudentDate(student2);
	 changeStudentNo(&student2, 99);   //生徒の出席番号を変更
	 disaStudentDate(student2);       //正しく変更できたかを確認


	return 0;
}
*/

