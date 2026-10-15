#include <iostream>
using namespace std;

void preorderTraversal(const int* tree,int n,int i){
    if(i>=n || i<0 || tree[i]==-1){
        return ;
    }
    
    cout<< tree[i] <<" ";

    preorderTraversal(tree,n,i*2+1);
    preorderTraversal(tree,n,i*2+2);
}

void midorderTraversal(const int* tree,int n,int i){
    if(i>=n || i<0 || tree[i]==-1){
        return;
    }
    midorderTraversal(tree,n,i*2+1);
    cout << tree[i]<<" ";
    midorderTraversal(tree,n,i*2+2);
    
}

void buildTestTree(int* tree,int n){
    int test[]={1,2,3,4,5,-1,-1};
    for(int i=0;i<=n;i++){
        tree[i]=test[i];
    }
}

int main(){
    int tree[7];
    buildTestTree(tree,7); 
    preorderTraversal(tree,7,0);
    midorderTraversal(tree,7,0);
}