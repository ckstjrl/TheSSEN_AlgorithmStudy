// solved(BOJ1991 / S1): 트리 순회

#include <bits/stdc++.h>

using namespace std;

struct Child {
    char left;
    char right;
};

unordered_map<char, Child> un_map;

void preOrder(char root, Child child) {

    cout << root;
    if (child.left != '.') {
        preOrder(child.left, un_map[child.left]);
    }
    if (child.right != '.') {
        preOrder(child.right, un_map[child.right]);
    }
}

void inOrder(char root, Child child) {
    if (child.left != '.') {
        inOrder(child.left, un_map[child.left]);
    }
    cout << root;
    if (child.right != '.') {
        inOrder(child.right, un_map[child.right]);
    }
}

void postOrder(char root, Child child) {
    if (child.left != '.') {
        postOrder(child.left, un_map[child.left]);
    }
    if (child.right != '.') {
        postOrder(child.right, un_map[child.right]);
    }
    cout << root;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        char a, b, c;
        cin >> a >> b >> c;
        un_map.insert({ a,{b,c} });
    }
    preOrder('A', un_map['A']);
    cout << '\n';
    inOrder('A', un_map['A']);
    cout << '\n';
    postOrder('A', un_map['A']);
    return 0;
}
