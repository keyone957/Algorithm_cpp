#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int board[51][51];
bool visited[51][51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];   // 0 = �� ĭ, 1 = ��
		}
	}

	// ����: 0=��, 1=��, 2=��, 3=��
	// dx, dy �� (��������) ������ ������ �θ�
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1,  0 };

	int y = r, x = c, dir = d;
	int cleaned = 0;

	while (true) {
		// 1) ���� ĭ û��
		if (board[y][x] == 0 && !visited[y][x]) {
			visited[y][x] = true;
			cleaned++;
		}

		// 2) �� ���� �� û���� ĭ�� �ִ��� Ž��
		bool moved = false;
		for (int i = 0; i < 4; i++) {
			// �ݽð�(����)�� 90�� ȸ��
			dir = (dir + 3) % 4;
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			// ���� �˻�, �� ĭ�̰� ���� û�� �� ������ �̵�
			if (ny >= 0 && ny < N && nx >= 0 && nx < M
				&& board[ny][nx] == 0 && !visited[ny][nx]) {
				y = ny;
				x = nx;
				moved = true;
				break;
			}
		}
		if (moved) continue;

		// 3) �� ���� ��� û�ҵǾ��ų� ���̸� �ڷ� �� ĭ ����
		int back = (dir + 2) % 4;
		int by = y + dy[back];
		int bx = x + dx[back];
		// ������ ���̸� ����
		if (by < 0 || by >= N || bx < 0 || bx >= M || board[by][bx] == 1) {
			break;
		}
		// ������ �ϰ� ������ ����
		y = by;
		x = bx;
	}

	cout << cleaned << "\n";
	return 0;
}