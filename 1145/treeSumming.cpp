#include <iostream>
using namespace std;
bool scanTree(int num,int tmp,bool& pnu){
    char c;
    int n;
    bool lr=false,pnu1=false,pnu2=false;
    cin>>c;
    pnu=(bool)(cin>>n);
    if(pnu){
        tmp+=n;
        lr=scanTree(num,tmp,pnu1)|scanTree(num,tmp,pnu2);
        if(!pnu1&&!pnu2){
            lr=(tmp==num);
        }
    }
    cin.clear();
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