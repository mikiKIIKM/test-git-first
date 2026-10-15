#include <iostream>
using namespace std;

long long climstairsiter(int n){
    
    if (n<=1){
        return 1;
    }

    long a=1;
    long b=1;

    for(int i=2;i<=n;i++){

    long long current= a+ b;
    a=b;
    b=current;

    }

    return b;
}

int main(){
    int n=0;
    cout<<"请输入楼梯台阶数"<<endl;
    cin >> n;

    if (n<0 || n>40){
        cout <<"error"<<endl;
        return 1;
    }
    
    long long result =climstairsiter(n);

    cout << result;

}