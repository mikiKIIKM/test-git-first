#include <iostream>
using namespace std;

long long clim(int n){
    if (n<=1){
        return 1;

    }
    return clim(n-1)+clim(n-2);
}

int main(){
    int n =0;
    cout <<"请输入n的数值"<<endl;
    cin >> n;
    long long  end =clim(n);
    cout <<end;

}
