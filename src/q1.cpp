#include <iostream>
using namespace std;

void reversearr (int* arr, int n)
{
    int* l=arr;
    int* r=arr + n - 1;

    for (;l<r;){
    int temp = *l;
    *l=*r;
    *r=temp;
    l++;
    r--;
    
    }

}

int main(){
    int n=0;
    cout <<"请输入数组长度"<< endl;
    cin >> n;

    if (n<=0){
        return 0;
    }

    int arr[100];
    cout <<"请输入几个整数"<<endl;

    for (int i=0;i<n;i++){
        cin >> arr[i];
    }

    reversearr(arr,n);

    for(int j=0;j<n;j++){
        cout << arr[j]<<" ";

    }


}
