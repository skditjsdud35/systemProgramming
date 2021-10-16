#include <setjmp.h>
#include "ourhdr.h"

static void f1(int, int, int);
static void f2(void);

static jmp_buf jmpbuffer;

int main(void) {
	int count;
	int val;
	int sum;

	count = 2;
	val = 3;
	sum = 4;

	printf("Intial values: count = %d, val = %d, sum =%d\n", count, val, sum);
	if (setjmp(jmpbuffer) != 0) {
		printf("after longjmp: count = %d, val = %d, sum = %d\n", count, val, sum);
		exit(0);
	}
	count = 97;
	val = 98;
	sum = 99;
	f1(count, val, sum);
}

static void f1(int i, int j, int k) {
	printf("in f1(): count = %d, val = %d, sum = %d\n",i, j, k);
	f2();
}

static void f2(void) {
	longjmp(jmpbuffer, 1);
}
