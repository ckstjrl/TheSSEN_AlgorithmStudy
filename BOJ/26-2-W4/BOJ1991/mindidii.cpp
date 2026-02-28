// 트리 순회 
# include <iostream>
using namespace std;

int N;
pair<int, int>tree[27];

void preorder(char x)
{
    if( x != '.')
    {
        cout << x;
        preorder(tree[x - 'A'].first);
        preorder(tree[x - 'A'].second);
    }
}

void inorder(char x)
{
    if( x != '.')
    {
        inorder(tree[x - 'A'].first);
        cout << x;
        inorder(tree[x - 'A'].second);
    }
}

void postorder(char x)
{
    if( x != '.')
    {
        postorder(tree[x - 'A'].first);
        postorder(tree[x - 'A'].second);
        cout << x;
    }
}

int main()
{
    cin >> N;
    char parent, right, left;

    for(int i=0; i<N; i++)
    {   
        cin >> parent >> left >> right;
        tree[parent - 'A'].first = left;
        tree[parent - 'A'].second = right;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');



    return 0;
}