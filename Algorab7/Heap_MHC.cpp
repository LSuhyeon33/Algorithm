#include <iostream>
#define MAX 1001
using namespace std;

int cnt;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void FixHeap(int root, int heap[], int n)
{
    // �θ���
    int parant = root; 
    // �ڽĳ��
    int left_child = root * 2 + 1;
    int right_child = root * 2 + 2;

    // �θ�� �ڽ� ��
    if (left_child < n) {
        cnt++;
        if (heap[parant] < heap[left_child])
            parant = left_child;
    }
    if (right_child < n) {
        cnt++;
        if (heap[parant] < heap[right_child])
            parant = right_child;
    }

    // ���ĵ� ������ �θ�� �ڽ� �ڸ� �ٲ�
    if (root != parant) {
        swap(&heap[parant], &heap[root]);
        FixHeap(parant, heap, n);
        }
}

void HeapSort(int heap[], int n)
{
    // �ִ� �� ����
    for (int i = (n / 2) - 1; i >= 0; i--) {
        FixHeap(i, heap, n);
    }

    // �ִ밪 ��� ���� �� �籸��
    for (int i = n - 1; i > 0; i--) {
        swap(&heap[0], &heap[i]);
        FixHeap(0, heap, i);
    }
}

int main() 
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        cnt = 0;
        int heap[MAX];
        int n;
        cin >> n;
        
        for (int j = 0; j < n; j++) {
            cin >> heap[j];
        }

        HeapSort(heap, n);

        cout << cnt << endl;
    }
}