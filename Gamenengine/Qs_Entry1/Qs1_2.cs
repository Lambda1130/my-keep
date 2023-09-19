using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qs_Entry1
{
    internal class Qs1_2
    {
        static void Main(string[] args)
        {
            /*関数の作成と実行(out参照渡し)*/
            //事前に初期化が必要ない。
            void CheckOutReference(out int a, out float b, out string c)
            {
                a = 8;
                b = 8.2f;
                c = "papas";
            }
            //実行
            Console.WriteLine("【関数の作成と実行(out参照渡し)：】");
            //初期化せずに使える。
            CheckOutReference(out int a2, out float b2, out string c2);
            Console.WriteLine("a:{0}, b:{1}, c:{2}", a2, b2, c2);

            /*重要コメント！*/
            //C#では殆どの型（値型以外）が参照渡しになっており、
            //C++のようにポインタや参照を乱用するのは宜しくない。
            //(意識しなくても参照型で渡した方が良いものは殆ど参照型)
            //参照渡しはそれでしか難しい場合以外はなるべく使わないように。
            //可読性向上のため、基本的にreturnで返しましょう。


            /*配列を扱う関数*/
            //配列は参照渡しになっている点に注意
            //C#では配列は値型でなく、参照型です。
            int ASum(int[] a)
            {
                int ans = 0;
                //forでも書けるが、foreachだと超楽
                foreach (int s in a)
                {
                    ans += s;
                }

                a[3] = 0;//第2引数の書き換え

                return ans;
            }
            //実行
            Console.WriteLine("【配列を扱う関数(配列は参照渡し)：】");
            int[] ar = { 1, 2, 3, 4 };
            Console.WriteLine("ASum:{0}", ASum(ar));
            //参照渡しなので、a[1]を書き換えるとar[1]も書き換えられ結果が変化している。
            Console.WriteLine("ASum(2回目):{0}", ASum(ar));



            /*可変引数の関数*/
            int ASum2(params int[] a)
            {
                int ans = 0;
                //forでも書けるが、foreachだと超楽
                foreach (int s in a)
                {
                    ans += s;
                }

                a[1] = 0;//第2引数の書き換え

                return ans;
            }
            //実行
            Console.WriteLine("【可変引数の関数：】");
            //いちいち配列を作ってそれを送らなくても配列変数として渡せる。
            Console.WriteLine(ASum2(1, 2, 3, 4));

            /*オーバーロードの実行*/
            Console.WriteLine("【関数のオーバーロード：】");
            Console.WriteLine(Add(1, 2));
            Console.WriteLine(Add(1, 2, 3));
            Console.WriteLine(Add(1.1f, 2.1f));
            Console.WriteLine(Add(1.1f, 2.1f, 3.1f));


        }
       
         /*関数のオーバーロード*/
        //Main()内ではオーバーロードできないので外に出す。
        //ProgramクラスにAdd()メソッドを作成し、機能を４つ持たせている。
        //今回はインスタンスを作らず使いたいので、staticを付ける。
        //以下のように同じ名前の関数に別々の引数を渡すことで、
        //別々の異なったふるまいをさせることができる。
        //このようなやり方を多態性を持たせると言う。
        static int Add(params int[] a)
        {

            int ans = 0;
            //forでも書けるが、foreachだと超楽
            foreach (int s in a)
            {
                ans += s;
            }

            a[1] = 0;//第2引数の書き換え

            return ans;
        }

        static float Add(params float[] a)
        {
            float ans = 0;
            //forでも書けるが、foreachだと超楽
            foreach (float s in a)
            {
                ans += s;
            }

            a[1] = 0;//第2引数の書き換え

            return ans;



        }


    }

    
        
    
}
