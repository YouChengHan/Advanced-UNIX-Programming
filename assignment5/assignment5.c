#include <stdio.h>

/*
original code:

int f1(int val) {
	int num=0;
	int *ptr=&num;
	if(num==0) { // text had val == 0, but val is not in scope
		int val;
		val=5;
		ptr=&val;
	}
	return (*ptr+1);
}

not correct since the scope of val is restricted in the if statement.
*/

int *f1(int *val) {
	int num=0;
	int *ptr=&num;
	if(num==0)
		ptr=val;
	return ptr;
}

int main() {
	int val=5;
	int *ret=f1(&val);
	printf("Value %d is at %p\n", *ret, ret);
	return 0;
}
