#include <iostream>
#include<vector>
using namespace std;

int fastMaxSum(vector<int>& A, int left, int right) {
    // basic case : 구간의 길이가 1일 경우
    if (left == right) 
        return A[left];

    // 배열을 A[left ~ mid], A[mid+1 ~ right]의 두 조각으로 나눈다.
    int mid = (left + right) / 2;

    // 최댓값을 갖는 부분배열이 중간값에 걸쳐 있는 경우 
    // A[i ~ mid]의 최댓값 + A[mid+1 ~ j]의 최댓값
    // A[i ~ mid]
    int L = 0, R = 0, sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += A[i];
        L = max(L, sum);
    }
    //A[mid+1 ~ j] 형태를 갖는 최대 구간을 찾는다.
    sum = 0;
    for (int j = mid + 1; j <= right; j++) {
        sum += A[j];
        R = max(R, sum);
    }
    // 부분 배열 둘 중 하나에 완전히 포함되는 경우
    int single = max(fastMaxSum(A, left, mid), fastMaxSum(A, mid + 1, right));

    // 두 경우 중 최대치를 반환한다.
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