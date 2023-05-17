#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validate(int i, int c, char *txt){
	if(i > 1){
		if(txt[i-1] == '.' || txt[i-1] == ',' || txt[i-1] == '\n' || txt[i-1] == ' '){
		       if(txt[i+c] == '.' || txt[i+c] == ',' || txt[i+c] == '\n' || txt[i+c] == ' '){
		       		return 1;
		       }
		}
	}
	return 0;
}	

int searchForWord(char *word, char *txt, int size){
	int occur = 0;
	int firstChar = 1;
	for(int i = 0; i < size; i++){
		char temp = txt[i];
		int count = 0;
		for(int r = 0; r < strlen(word); r++){
			if(temp != word[r]){
				break;
			} else {
				count++;
				temp = txt[i + count];	
			}
		}
		if(count == strlen(word) && validate(i, count, txt) == 1){
			occur++;
		}

	}
	return occur;

}

int main(int argc, char *argv[]){
	int wordsUsed = argc - 2; //2 since there are 2 arguments before it

	FILE *file = fopen(argv[1], "r");
	if(file == NULL){
		printf("Error message: \"%s\" is not a valid file.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fseek(file, 0, SEEK_END);
	int size  = ftell(file);
	fseek(file, 0, SEEK_SET);
	char *B  = (char*)malloc(size);
        int *counter = (int*)malloc(sizeof(int) * (wordsUsed));
	fread(B, sizeof(char), size, file);
	for(int i = 0; i < wordsUsed; i++){
		counter[i] = 0; //setup all counters

	}
	for(int j = 0; j < wordsUsed; j++){
		counter[j]  = searchForWord(argv[j+2], B, size);
		printf("The word \"%s\" occurs %d times.\n", argv[j+2], counter[j]);
	}
	
	fclose(file);
	free(B);
	free(counter);
}
