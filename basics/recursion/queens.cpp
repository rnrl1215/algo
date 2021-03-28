/*
 ����:
1. ���� ������ ���� ���̳� �밢 ���� ������ ���� ���ϰ� �Ѵ�.
2. ���� ������ �Ѿ �����ϰ� �˻��Ѵ�.
3. 1~2 �� �ݺ��ϸ鼭 N���� ���� �� �����ִ��� �˻��Ѵ�.

1. 1,1 �� ���� ������ �� 1�� ���δ� �Ѽ� ���� �ȴ�.
2. �밢 ���� �˻��ϱ� ���� ��� �մܰ迡�� ������ ���� �˻��Ѵ�.
3. 2���� �迭�� �������� �ʰ� �ռ� ���° ���� ���° ������ ���������� �˻��غ���.
4. cols �迭
*/

#include<iostream>
#include<Math.h>
using namespace std;

bool promising(int level);
bool queens(int level);
int *cols;

// ���� ����
int N = 0;

int main() {
	cout << "Input queens count: ";
	cin >> N;

	cols = new int[N + 1];

	if (queens(0)) {
		cout << "����" << endl;
	} else {
		cout << "����" << endl;
	}
}

// ���� �Ѽ� �ִ��� �˻� �ϴ� �Լ�.
bool promising(int level) {
	for (int i = 0; i < level; i++) {
		// column �˻�
		if (cols[i] == cols[level]) {
			return false;
	    
		// �밢�� �˻�. �Ÿ����� 
		} else if (level - i == abs(cols[i] - cols[level])) {
			return false;
		}
	}
	return true;
}

// ���� �����δ� �Լ�
bool queens(int level) {

	// ���� �Ѽ� �ִ��� �˻�
	if (!promising(level)) {
		return false;

	// �ش� ã��.
	} else if (level == N) { 
		return true;

	// �� ������ �ִ��� ��� ȣ��
	} else {

		// ������ �ִ� queen �˻�
		for (int i = 1; i <=N; i++) {
			// �ش� ���� i ��°�� �ξ���.
			cols[level + 1] = i;

			// ��� �Լ� ȣ�� ���� true�� ���̻� ������ �˻��� ������ ����.
			if (queens(level + 1)) {
				return true;
			}
		}
	}

	// �ִ� �� ���� �غ����� �Ѽ� ����
	return false;
}
