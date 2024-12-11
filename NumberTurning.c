#include <stdio.h>
long long n, a;
void turn(int n) {
	int x, y, z;
	x = n % 10;//个位
	y = n / 10 % 10;//十位
	z = n / 100;//百位
	if (z >= 1) {
		switch (z) {
			case 1:
				printf("one ");
				break;
			case 2:
				printf("two ");
				break;
			case 3:
				printf("three ");
				break;
			case 4:
				printf("four ");
				break;
			case 5:
				printf("five ");
				break;
			case 6:
				printf("six ");
				break;
			case 7:
				printf("seven ");
				break;
			case 8:
				printf("eight ");
				break;
			case 9:
				printf("nine ");
				break;
		}
		printf("hundred ");
		if (y > 0 || x > 0)//判定1
			printf("and ");
	}
	if (y > 0) {
		switch (y) {
			case 2://从20开始
				printf("twenty");
				break;
			case 3:
				printf("thirty");
				break;
			case 4:
				printf("forty");
				break;
			case 5:
				printf("fifty");
				break;
			case 6:
				printf("sixty");
				break;
			case 7:
				printf("seventy");
				break;
			case 8:
				printf("eighty");
				break;
			case 9:
				printf("ninety");
				break;
		}
		if (y >= 2 && x > 0)//判定2
			printf("-");
		else if (y >= 2 && x == 0)//同上
			printf(" ");
		if (y == 1) {
			switch (x) {
				case 0:
					printf("ten ");
					break;
				case 1:
					printf("eleven ");
					break;
				case 2:
					printf("twelve ");
					break;
				case 3:
					printf("thirteen ");
					break;
				case 4:
					printf("fourteen ");
					break;
				case 5:
					printf("fifteen ");
					break;
				case 6:
					printf("sixteen ");
					break;
				case 7:
					printf("seventeen ");
					break;
				case 8:
					printf("eighteen ");
					break;
				case 9:
					printf("nineteen ");
					break;
			}
		}
	}
	if (x > 0 && y != 1) {//没有十位
		switch (x) {
			case 1:
				printf("one ");
				break;
			case 2:
				printf("two ");
				break;
			case 3:
				printf("three ");
				break;
			case 4:
				printf("four ");
				break;
			case 5:
				printf("five ");
				break;
			case 6:
				printf("six ");
				break;
			case 7:
				printf("seven ");
				break;
			case 8:
				printf("eight ");
				break;
			case 9:
				printf("nine ");
				break;
		}
	}
}

int main() {
	scanf("%lld", &n);//Long long detail!
	if (n == 0) {//零单独处理
		printf("zero");
		return 0;
	}
	if (n < 0) {//负号判定+转化绝对值
		printf("minus ");
		n *= -1;
	}
	if (n >= 1000000000) {
		a = n / 1000000000;
		turn(a);
		printf("billion ");
		n %= 1000000000;
	}
	if (n >= 1000000) {
		a = n / 1000000;
		turn(a);
		printf("million ");
		n %= 1000000;
	}
	if (n >= 1000) {
		a = n / 1000;
		turn(a);
		printf("thousand ");
		n %= 1000;
	}
	turn(n);
	return 0;
}