#include<stdio.h>

int main() {
	int h, m, s, q, t, c, clock;
	scanf_s("%d %d %d %d", &h, &m, &s, &q);
	//초단위 시간으로 변경
	clock = h * 3600 + m * 60 + s;

	for (int i = 0; i < q; i++) {
		scanf_s("%d", &t);
		if (t == 3) {	//시간 출력
			h = clock / 3600;
			m = (clock % 3600) / 60;
			s = clock % 60;
			printf("%d %d %d\n", h, m, s);
		}
		else {
			scanf_s("%d", &c);
			//시간을 앞이나 뒤로 돌리기
			if (t == 2) clock -= c;	
			else clock += c;
			//24시간(0~86400)초 사이로 범위 맞추기
			if (clock >= 86400 || clock <= -86400)clock %= 86400;
			if (clock < 0) clock += 86400;
		}
	}

	return 0;
}