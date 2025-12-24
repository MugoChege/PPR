#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strslice (char* text, int start, int end){
	int cursor = 0;
	for (int a = start; a < end; a++){
		text[cursor] = text[a];
		cursor++;
	}
	
	text[cursor] = 0;
	
}

int strfind (char* text, char* l){
	int out = 0;
	int cursor = 0;
	
	while (*(text + cursor) != (char)0){
		if (*(text + cursor) == *l){
			out = 1;
			break;
		}
		
		cursor++;
	}
	
	return (out);
}

void longest_substring (char* text,char* out){ //out should be a pointer to a char memory location
	int len_text = strlen(text);
	char* substring = (char*) calloc (len_text + 1, sizeof(char));
	strcpy(substring, text);
	
	for (int a = 0; a < len_text; a++){
		for (int b = a; b < (len_text - a); b++){
			if ((a + b) >= len_text){
				break;
			}
			strslice(substring, a, a + b);
			char letter_d = text[a + b];
			char* letter = &letter_d;
			printf("%s\t\t\t%s\n", substring, letter);
			
			if (strfind(substring, letter)){
				if (strlen(out) < strlen(substring)){
					strcpy(out, substring);
				}
				break;
			}
			strcpy(substring, text);
		}
	}
	
	free(substring);
}

int main () {
	char f[] = "pwwkew";
	int len_f = strlen(f);
	char* ret;
	
	ret = (char *) calloc((len_f + 2), sizeof(char));
	
	longest_substring(f, ret);
	
	printf("\n\n%s\n\n", ret);
	
	free(ret);
	
	return 0;
}
