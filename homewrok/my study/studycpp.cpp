#include <iostream>
#include <string>
#include<stdio.h>
#include<cmath>
#include <bits/stdc++.h>
#include<vector>
using namespace std;


    
int main(void) 
{
        // 成績の入力
        int grade;
        std::cin >> grade;
        // プレゼント候補の入力
        std::vector<std::string> presents(3);
        for (int i = 0; i < 3; ++i)
        {
            std::cin >> presents[i];
        }
        // 成績に応じてソートし、対応するプレゼントを出力
        if (grade == 3) 
        {
            std::cout << presents[2] << std::endl;
        }
        else if (grade == 2)
        {
            std::cout << presents[1] << std::endl;
        }
        else
        {
            std::cout << presents[0] << std::endl;
        }
        
        return 0;
    
}

//int main(void)
//{
//    int n;
//    cin >> n;
//
//    string m(n, '*');
//
//        cout << ""<<m << endl;
//
//    return 0;


//int main(void)
//{
//    int n;
//    cin >> n;
//    int m = 24;
//
//    int a = n / m;
//    if (n % m == 0)
//    {
//        cout << "" << a << endl;
//    }
//    else
//    {
//        cout << "" << a + 1 << endl;
//    }
//    return 0;
//}



//int main(void)
//{
//    int N;
//    std::cin >> N;
//    std::string n, m;
//    bool isSucceeded = true;
//    for (int i = 0; i < N; ++i)
//    {
//        std::cin >> m;
//        if (i > 0 && n.back() != m.front())
//        {
//            std::cout << n.back() << " " << m.front() << std::endl;
//            isSucceeded = false;
//            break;
//        }
//        n = m;
//    }
//    if (isSucceeded)
//    {
//        std::cout << "Yes" << std::endl;
//    }
//    return 0;
//}


//int main(void)
//{
//    std::string n;
//    std::cin >> n;
//    int m = 0;
//    int s = 0;
//
//    for (int i = n.length() - 1; i >= 0; --i) 
//    {
//        m += (n[i]-'0') * std::pow(2, s);
//        ++s;
//    }
//    std::cout << m << std::endl;
//    return 0;
//   
//}

//int main(void)
//{
//    
//        const int daysInWeek = 7;
//        std::string dayStatus[daysInWeek];
//        // 7日間の休み情報を入力
//        for (int i = 0; i < daysInWeek; ++i) {
//            std::cin >> dayStatus[i];
//        }
//        // 有給申請が必要な日数を計算
//        int paidLeaveCount = 0;
//        for (int i = 0; i < daysInWeek; ++i) {
//            if (dayStatus[i] == "no") {
//                paidLeaveCount++;
//            }
//        }
//        // 結果を出力
//        std::cout << paidLeaveCount << std::endl;
//        return 0;
//}


//int main()
//{
//    int n = 0;
//    int m = 0;
//
//    int sum = 0;
//    cin >> n >> m;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> n;
//
//        if (n < m)
//        {
//            sum += n;
//        }
//    }
//    cout << "" << sum << endl;
//
//
//    return 0;
//}


//int main()
//{
//    int n;
//    int a,b,c,d,e,f;
//    cin >> n;
//
//    if (n<=6)
//    {
//        cin>>a>>b>>c>>d>>e>>f;
//        cout << "" << a+b+c+d+e+f << endl;
//    }
//}



//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    if (n + m >= 16)
//    {
//        cout << "HIT" << endl;
//    }
//    else if(n + m <= 16)
//    {
//        cout << "STAND" << endl;
//    }
//    return 0;
//}






//int main()
//{
//    int n, m;
//    cin >> n;
//    cin >> m;
//    if (n==11,12 && m==1.)
//    {
//        cout << "YES" << endl;
//    }
//    else
//    {
//        cout << "NO" << endl;
//    }
//    return 0;
//	
//	
//}



//int main(void)
//{
//    int n, x, y;
//    cin >> n;//5, 
//    cin >> x;//2
//    cin >> y;//4
//
//    
//    for (int i = 1; i < n + 1; i++)
//    {
//
//
//        if (i % x == 0 && i % y == 0)
//        {
//            cout << "AB" << endl;
//        }
//        else if (i % x == 0)
//        {
//            cout << "A" << endl;
//            
//        }
//        else if (i % y == 0)
//        {
//            cout << "B" << endl;
//        }
//        else
//        {
//            cout << "N" << endl;
//        }
//
//
//    }
//    return 0;
//
//}



//int main()
//{
//	string str;
//
//	getline(cin, str);
//	//オーバロード関数
//
//	string bar(str.length() +2, '+');
//    //length文字のサイズを取得する
//
//	cout << bar << endl;
//	cout << "+" << str << "+" << endl;
//	cout << bar << endl;
//
//	return 0;
//}
