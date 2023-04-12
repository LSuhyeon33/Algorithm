#include <iostream>
#include<vector>
using namespace std;

int fastMaxSum(vector<int>& A, int left, int right) {
    // basic case : ������ ���̰� 1�� ���
    if (left == right) 
        return A[left];

    // �迭�� A[left ~ mid], A[mid+1 ~ right]�� �� �������� ������.
    int mid = (left + right) / 2;

    // �ִ��� ���� �κй迭�� �߰����� ���� �ִ� ��� 
    // A[i ~ mid]�� �ִ� + A[mid+1 ~ j]�� �ִ�
    // A[i ~ mid]
    int L = 0, R = 0, sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += A[i];
        L = max(L, sum);
    }
    //A[mid+1 ~ j] ���¸� ���� �ִ� ������ ã�´�.
    sum = 0;
    for (int j = mid + 1; j <= right; j++) {
        sum += A[j];
        R = max(R, sum);
    }
    // �κ� �迭 �� �� �ϳ��� ������ ���ԵǴ� ���
    int single = max(fastMaxSum(A, left, mid), fastMaxSum(A, mid + 1, right));

    // �� ��� �� �ִ�ġ�� ��ȯ�Ѵ�.
    return max(L + R, single);
}

int main()
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int num;
        vector<int> a;
        cin >> num;

        for (int i = 0; i < num; i++) {
            int data;
            cin >> data;
            a.push_back(data);
        }

        cout << fastMaxSum(a, 0, num - 1) << endl;
    }
}