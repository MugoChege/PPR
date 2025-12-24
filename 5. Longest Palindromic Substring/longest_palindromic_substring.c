#include<stdio.h>

struct Range;

typedef struct Range{
	int begin;
	int end;
	
	int (*compare_length)(struct Range*, struct Range*);
	void (*jaza) (struct Range*, int, int);
} Range;

int fun_compare_length (Range* a, Range* b){
	return ((a-> end - a-> begin) - (b -> end - b->begin));
}

void fun_jaza (Range* self, int beg, int end){
	self->begin = beg;
	self->end = end;
}

Range create_Range (int beg, int end){
	Range out;
	out.compare_length = fun_compare_length;
	out.jaza = fun_jaza;
	
	out.jaza(&out, beg, end);
	
	return (out);
}

Range new_Range (){
	Range out;
	out.compare_length = fun_compare_length;
	out.jaza = fun_jaza;
	
	return (out);
}

//###################################################################

int no_of_characters (char* text){
	int out = 0;
	
	while (text[out] != '\0'){
		out ++;
	}
	
	return (out);
}

void print_word(char* text, int beg, int end){
	for (int i = beg; i < end; i++){
		printf("%c", text[i]);
	}
}

Range longest_substring (char* text){
	Range out = new_Range();
	int len_text = no_of_characters(text);
	int empty_range_switch = 1;
	
	for (int i = 0; i < len_text; i++){
		int exit = 0;
		for (int j = (len_text - i); j > 0; j--){
			if (i < j){
				int mir = j / 2;
				int palindrome = 0;
				
				for (int k = 0; k < mir; k++){
					if (k == 0){
						palindrome = (text[i + k] == text[j - k - 1]);
					} else {
						palindrome = palindrome && (text[i + k] == text[j - k - 1]);
					}
				}
				
				if (palindrome){
					if (empty_range_switch){
						out.jaza(&out, i, j);
						empty_range_switch = 0;
						exit = 1;
						break;
					/*} else {
						Range comp;
						comp.jaza(&comp, i, j);
						
						if (fun_compare_length(out, comp){
							out.jaza(&out, i, j);
						}
					*/
					}
				}
			}
		}
		
		if (exit){
			break;
		}
	}
	
	return (out);
}

int main(){
	char word[] = "babob";
	printf("This is the handy work of C.\n\n\n");
	Range ran = longest_substring(word);
	print_word(word, ran.begin, ran.end);
	printf("\n\n\n");
}
