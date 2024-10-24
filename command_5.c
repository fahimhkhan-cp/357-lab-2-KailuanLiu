#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) {
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			printf("Argument %d: %s\n", i, argv[i]);
		}
	}
	return 0;
}
