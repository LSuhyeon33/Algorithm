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
        destruct(&root);        // BST�� ��� ����� ���� �޸� ����

        if (root == NULL)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}

// ������ ����(recursion)
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

// ����(preorder)Ž��(recursion)
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

// ����(inorder)Ž��(recursion)
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

// ����(postorder)Ž��(recursion)
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

// ����� ����(recursion)
int size(struct node* root)
{
    int cnt = 0;
    if (root != NULL)
    {
        cnt = 1 + size(root->left) + size(root->right);
    }
    return cnt;
}

// ����(recursion)
int height(struct node* root)
{
    // �⺻ ���: �� Ʈ���� ���̰� 0�Դϴ�.
    if (root == NULL) {
        return -1;
    }

    // ���� �� ������ ���� Ʈ���� ���� �ݺ��ϰ� �ִ� ���̸� ����մϴ�.
    return 1 + max(height(root->left), height(root->right));
}

// �̷� �̹����� ��ȯ�ϱ�(recursion)
void mirror(struct node* root)
{
    // �⺻ ���̽�: Ʈ���� ��� �ִ� ���
    if (root == NULL) {
        return;
    }

    // ���� ���� Ʈ�� ��ȯ
    mirror(root->left);

    // ������ ���� Ʈ�� ��ȯ
    mirror(root->right);

    // ���� ����Ʈ���� ������ ����Ʈ���� ��ü
    swap(root->left, root->right);
}

// ��忡 ����� �������� ���� �� ���ϱ�(recursion)
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

// ��Ʈ������ �ܸ��������� ��� ���� �������� �ִ���(recusrion)
int maxPathWeight(struct node* root, int &result)
{
    // �⺻ ���̽�: �� Ʈ��
    if (root == NULL) {
        return 0;
    }

    // ���� �ڽĿ��� "����" �ִ� ��� �հ� ã��
    int left = maxPathWeight(root->left, result);

    // ������ �ڽĿ��� "����" �ִ� ��� �հ踦 ã���ϴ�.
    int right = maxPathWeight(root->right, result);

    // ������ ����� ��� ���� ������ ��� ������ �õ��մϴ�.
    result = max(result, root->data);
    result = max(result, root->data + left);
    result = max(result, root->data + right);
    result = max(result, root->data + left + right);

    // �־��� ��忡�� "����" �ִ� ��� �հ踦 ��ȯ�մϴ�.
    return max(root->data, root->data + max(left, right));
}

// Ʈ������� ���� �޸� �����ϱ�(recursion)
void destruct(struct node** root)
{
    if (*root == NULL)
        return;

    destruct(&((*root)->left));					//����� ����� ���� ��ȸ�������
    destruct(&((*root)->right));

    delete *root;

    *root = NULL;
}