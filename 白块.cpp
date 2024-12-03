#include<graphics.h>
#include<stdio.h>
#define N 5
#include<time.h>
int Map[N];

int MapX, MapY, Score = 0;

void InitBlack() {
	for(int i = 0; i< N-1; i++) {
		Map[i] = rand() % N;
		printf("%d\n", Map[i]);
	}
}
void DrawBlack() {
	for (int i = 0; i < N-1; i++) {
		fillrectangle(Map[i] * 100, i * 120, Map[i] * 100 + 100, i * 120 + 120);
	}

}
void Draw() {
	
	BeginBatchDraw();
	cleardevice();
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			fillrectangle(j * 100, i * 120, j * 100 + 100, i * 120 + 120);
		}
	}
	//fillrectangle(0, 0, 100, 120);
	setfillcolor(BLACK);
	DrawBlack();
	EndBatchDraw();

    }

bool  Play() {
	MOUSEMSG msg;
	msg = GetMouseMsg();
	switch (msg.uMsg) {
	case WM_LBUTTONDOWN:
			MapY = msg.y / 120;
			MapX = msg.x / 100;
			if (Map[3] == MapX && MapY == 3) {
				for (int i = 3; i > 0; i--) {
					Map[i] = Map[i - 1];
				}
				Map[0] = rand() % N;
				Score += 10;
				printf("你点击到了黑块！\n");
			}
			else {
				printf("未点击到黑块！\n");
				return true;
			}
			break;
	}
	return false;
}
int main() {

	srand((unsigned)time(NULL));
	initgraph(500, 480);
	InitBlack();
	while (1) {
		Draw();
		if (Play()) {
			char str[128];
			sprintf_s(str, "总计消除格子：%d,总计得分：%d", Score / 10, Score);
			MessageBox(GetHWnd(),str, "Game Over",MB_OK );
			exit(0);
		}
	}
	

	
	
	getchar();
	return 0;
}
/*while (1) {
		MOUSEMSG msg;
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) {
			printf("鼠标左键按下\n");
			printf("%d,%d\n", msg.x, msg.y);
		}
		else if (msg.uMsg == WM_RBUTTONDOWN) {
			printf("鼠标右键按下\n");
			printf("%d,%d\n", msg.x, msg.y);
		}
	}
*/