#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	//open the filr 
	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}

	//variables for getline
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	//store the last two lines 
	char *last_line = NULL;
	char *second_last_line = NULL;

	while ((nread = getline(&line, &len, file)) != -1) {
		if(second_last_line) {
			free(second_last_line);
		}
		second_last_line = last_line;
		last_line = strdup(line);
	}
	
	//close the file 
	fclose(file);

	//print the last two lines if they exist
	if (second_last_line) {
		printf("%s", second_last_line);
	}
	if (last_line) {
		printf("%s", last_line);
	}

	free(second_last_line);
	free(last_line);
	free(line);

	return 0;
}
