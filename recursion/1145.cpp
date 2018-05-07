#include <iostream>
/*
 * 使用递归，pnu判断当前是否读到左节点或右节点为空
 */
using namespace std;
bool scanTree(int num,int tmp,bool& pnu){
    char c;
    int n;
    bool lr=false,pnu1=false,pnu2=false;
    cin>>c;
    pnu=(bool)(cin>>n);//判断能够读到数字
    if(pnu){
        tmp+=n;
        lr=scanTree(num,tmp,pnu1)|scanTree(num,tmp,pnu2);//只要找到一个符合即为真
        if(!pnu1&&!pnu2){
            lr=(tmp==num);//判断根节点到叶节点和是否等于目标节点
        }
    }
    cin.clear();//消除输入问题
    cin>>c;
    return lr;
}
int main()
{
    int num;
    bool bnu;
    while(cin>>num){
        cout << (scanTree(num, 0, bnu) ? "yes" : "no") << endl;
    }

    return 0;
}