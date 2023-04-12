#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void insert(struct node** root, int data);
void preOrder(struct node* root);
void inOrder(struct node* root);
void postOrder(struct node* root);
int size(struct node* root);
int height(struct node* root);
int sumOfWeight(struct node* root);
int maxPathWeight(struct node* root, int &result);
void mirror(struct node* root);
void destruct(struct node** root);

int main()
{
    int numTestCases;
    cin >> numTestCases;

    for(int j = 0; j < numTestCases; j++)
    {
        int num;
        int h = 0;
        int result = 0;
        struct node* root = NULL;
        cin >> num;

        for (int i = 0; i < num; i++)
        {
            int data;
            cin >> data;
            insert(&root, data); 
        }

        cout << size(root) << endl;
        cout << height(root) << endl;
        cout << sumOfWeight(root) << endl;
        cout << maxPathWeight(root, result) << endl;

        mirror(root);
        preOrder(root); 
        cout << endl;
        inOrder(root); 
        cout << endl;
        postOrder(root); 
        cout << endl;
        destruct(&root);        // BST의 모든 노드의 동적 메모리 해제

        if (root == NULL)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}

// 데이터 삽입(recursion)
void insert(struct node** root, int data)
{
    node* tmp = new node;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = data;

    if (*root == NULL) {
        *root = tmp;
        return;
    }
    else {
        if ((*root)->data > data) {
            insert(&((*root)->left), data);
        }
        else if ((*root)->data < data) {
            insert(&((*root)->right), data);
        }
    }
}

// 전위(preorder)탐색(recursion)
void preOrder(struct node* root)
{
    if (root == NULL) /* base case */
        return;
    else /* recursive step */
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 중위(inorder)탐색(recursion)
void inOrder(struct node* root)
{
    if (root == NULL) /* base case */
        return;
    else /* recursive step */
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// 후위(postorder)탐색(recursion)
void postOrder(struct node* root)
{
    if (root == NULL) /* base case */
        return;
    else /* recursive step */
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// 노드의 개수(recursion)
int size(struct node* root)
{
    int cnt = 0;
    if (root != NULL)
    {
        cnt = 1 + size(root->left) + size(root->right);
    }
    return cnt;
}

// 높이(recursion)
int height(struct node* root)
{
    // 기본 경우: 빈 트리의 높이가 0입니다.
    if (root == NULL) {
        return -1;
    }

    // 왼쪽 및 오른쪽 하위 트리에 대해 반복하고 최대 깊이를 고려합니다.
    return 1 + max(height(root->left), height(root->right));
}

// 미러 이미지로 변환하기(recursion)
void mirror(struct node* root)
{
    // 기본 케이스: 트리가 비어 있는 경우
    if (root == NULL) {
        return;
    }

    // 왼쪽 하위 트리 변환
    mirror(root->left);

    // 오른쪽 하위 트리 변환
    mirror(root->right);

    // 왼쪽 서브트리를 오른쪽 서브트리로 교체
    swap(root->left, root->right);
}

// 노드에 저장된 데이터의 값의 합 구하기(recursion)
int sumOfWeight(struct node* root)
{

    if (root->left == NULL && root->right == NULL) {
        return root->data;
    }
    else {
        if (root->left != NULL && root->right != NULL) {
            return root->data + sumOfWeight(root->left) + sumOfWeight(root->right);
        }
        else if (root->left != NULL && root->right == NULL) {
            return root->data + sumOfWeight(root->left);
        }
        else if (root->left == NULL && root->right != NULL) {
            return root->data + sumOfWeight(root->right);
        }
    }
}

// 루트노드부터 단말노드까지의 경로 상의 데이터의 최대합(recusrion)
int maxPathWeight(struct node* root, int &result)
{
    // 기본 케이스: 빈 트리
    if (root == NULL) {
        return 0;
    }

    // 왼쪽 자식에서 "시작" 최대 경로 합계 찾기
    int left = maxPathWeight(root->left, result);

    // 오른쪽 자식에서 "시작" 최대 경로 합계를 찾습니다.
    int right = maxPathWeight(root->right, result);

    // 최적의 결과를 얻기 위해 가능한 모든 조합을 시도합니다.
    result = max(result, root->data);
    result = max(result, root->data + left);
    result = max(result, root->data + right);
    result = max(result, root->data + left + right);

    // 주어진 노드에서 "시작" 최대 경로 합계를 반환합니다.
    return max(root->data, root->data + max(left, right));
}

// 트리노드의 동적 메모리 해제하기(recursion)
void destruct(struct node** root)
{
    if (*root == NULL)
        return;

    destruct(&((*root)->left));					//지우는 방식은 후위 순회방식으로
    destruct(&((*root)->right));

    delete *root;

    *root = NULL;
}