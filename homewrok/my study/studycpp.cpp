#include <iostream>
#include <string>
#include<stdio.h>
#include<cmath>
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    std::string n;
    std::cin >> n;
    int m = 0;
    int s = 0;

    for (int i = n.length() - 1; i >= 0; --i) 
    {
        m += (n[i] ) * std::pow(2, s);
        ++s;
    }
    std::cout << m << std::endl;
    return 0;
   
}

//int main(void)
//{
//    
//        const int daysInWeek = 7;
//        std::string dayStatus[daysInWeek];
//        // 7���Ԃ̋x�ݏ������
//        for (int i = 0; i < daysInWeek; ++i) {
//            std::cin >> dayStatus[i];
//        }
//        // �L���\�����K�v�ȓ������v�Z
//        int paidLeaveCount = 0;
//        for (int i = 0; i < daysInWeek; ++i) {
//            if (dayStatus[i] == "no") {
//                paidLeaveCount++;
//            }
//        }
//        // ���ʂ��o��
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
//	//�I�[�o���[�h�֐�
//
//	string bar(str.length() +2, '+');
//    //length�����̃T�C�Y���擾����
//
//	cout << bar << endl;
//	cout << "+" << str << "+" << endl;
//	cout << bar << endl;
//
//	return 0;
//}
