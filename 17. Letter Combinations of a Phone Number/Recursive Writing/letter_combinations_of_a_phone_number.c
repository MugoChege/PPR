#include<stdio.h>

char combinations[][5] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int sample_space_cursor = 0;
int useable_word_length;

int no_of_letters (char * text){
	int out = 0;
	while (text[out] != '\0'){
		out += 1;
	}
	
	return (out);
}

int to_integer (char let){
	return ((int) let - 48);
}

void word_from_odo (char* relevant_digits, int* digits_odo, char* out, int length){
	for (int i = 0; i < length; i++){
		int dig = to_integer(relevant_digits[i]) % 10;
		out[i] = combinations[dig][digits_odo[i]];
	}
}

void word_fill (char* relevant_digits, int* digits_odo, int depth, int max_depth, char sample_space[][useable_word_length]){
	int len_letter_options = no_of_letters(combinations[to_integer(relevant_digits[depth])]);
	
	for (int i = 0; i < len_letter_options; i++){
		digits_odo[depth] = i;
		if (depth < (max_depth - 1)){
			word_fill (relevant_digits, digits_odo, (depth + 1), max_depth, sample_space);
		} else {
			char word[max_depth];
			word_from_odo (relevant_digits, digits_odo, word, max_depth);
			for (int j = 0; j < max_depth; j++){
				sample_space[sample_space_cursor][j] = word[j];
			}
			sample_space[sample_space_cursor][max_depth] = '\0';
			sample_space_cursor++;
		}
	}
}

int main (){
	char digits[] = "243043";
	int size_digits = sizeof(digits)/sizeof(digits[0]);
	int len_digits = no_of_letters(digits);
	char useable_digits_temp[len_digits + 1];
	int useable_digits_cursor = 0;
	int sample_size = 0;
	
	for (int i = 0; i < (len_digits + 1); i++){
		useable_digits_temp[i] = '\0';
	}
	
	for (int i = 0; i < len_digits; i++){
		int len_letters = no_of_letters(combinations[to_integer(digits[i])]);
		
		if (len_letters == 0){
			continue;
		}
		
		if (sample_size == 0){
			sample_size = no_of_letters(combinations[to_integer(digits[i])]);
		} else {
			sample_size *= no_of_letters(combinations[to_integer(digits[i])]);
		}
		
		useable_digits_temp[useable_digits_cursor] = digits[i];
		useable_digits_cursor++;
	}

	
	printf("\n\nThe number of useable digits %s is %d from the original %s\nThe sample size that needs to be allocated is %d\n\n", useable_digits_temp, no_of_letters(useable_digits_temp), digits, sample_size);
	
	int len_useable_digits = no_of_letters(useable_digits_temp);
	int size_useable_digits = len_useable_digits + 1; //basically size of useable_digits_temp with the null terminator
	char useable_digits[len_useable_digits + 1];
	int digits_odo[len_useable_digits];
	char sample_space[sample_size][size_useable_digits];
	useable_word_length = size_useable_digits;
	
	for (int i = 0; i < len_useable_digits; i++){
		useable_digits[i] = useable_digits_temp[i];
		digits_odo[i] = 0;
	}
	
	useable_digits[len_useable_digits] = '\0';
	
	int len_digits_odo = sizeof(digits_odo)/sizeof(digits_odo[0]);
	
	word_fill(useable_digits, digits_odo, 0, len_useable_digits, sample_space);
	
	for (int i = 0; i < sample_size; i++){
		printf("%d\t\t%s\n", i + 1, sample_space[i]);
	}
	
	return (0);
}
