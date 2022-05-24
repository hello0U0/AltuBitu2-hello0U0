//5639 이진 검색 트리
#include <iostream>

using namespace std;

struct node_info {      
    int data;           //값
    node_info* left;    
    node_info* right;
};

node_info* makeTree(node_info* node, int data) {
    if (node == NULL) { //이번 노드가 들어가게될 위치
        node = new node_info(); //동적 할당
        node->data = data;
        node->left = node->right = NULL; //리프노드라 비어있음
    }
    else if (node->data > data) {      //값이 작으면 
        node->left = makeTree(node->left, data);    //왼쪽으로 저장
    }
    else if (node->data < data) {   //값이 크면
        node->right = makeTree(node->right, data);  //오른쪽으로 저장
    }
    return node;
}

//후위 순회
void postorder(node_info* node) {
    if (node == NULL) {         //출력할 것이 없으면 끝
        return;
    }
    postorder(node->left);      //왼쪽 출력
    postorder(node->right);     //오른쪽 출력
    cout << node->data << '\n'; // 부모 출력
}

/**
 * 맵과 셋 PPT 중 BST 노드 삽입 과정 참고
 *
 * [이진 검색 트리]
 *
 * 1. 포인터로 왼쪽, 오른쪽 서브트리를 가리키는 구조체 선언
 * 2. NULL 만날 때까지 조건에 따라 왼쪽 또는 오른쪽으로 이동
 * 3. 노드가 들어갈 위치를 찾으면 동적할당 후 노드 만들기
 * 4. 완성한 트리를 후위 순회
 */

int main() {
    int input;

    //입력 & 연산
    node_info* root = NULL;    //트리   
    while (cin >> input) {
        root = makeTree(root, input);   //트리에 값을 저장
    }

    //출럭
    postorder(root);
    return 0;
}