#include <bits/stdc++.h>
using namespace std;

struct node{
    char left;
    char right;
}typedef Node;

Node tree[26];

void preorder(char a){
    
    if(a == '.') return;
    cout << a;

    preorder(tree[a-'A'].left);
    preorder(tree[a-'A'].right);

}

void postorder(char a){
    if(a == '.') return;

    postorder(tree[a-'A'].left);
    postorder(tree[a-'A'].right);
    cout << a;
}

void inorder(char a){
    
    if(a == '.') return;
    inorder(tree[a-'A'].left);
    cout << a;
    inorder(tree[a-'A'].right);
}

int main(){
    int N;
    char c1,c2,c3;
    cin >> N;

    for(int i =0 ;i<N; ++i){
        cin >> c1 >> c2 >> c3;
        tree[c1-'A'].left = c2;
        tree[c1-'A'].right = c3;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');

}