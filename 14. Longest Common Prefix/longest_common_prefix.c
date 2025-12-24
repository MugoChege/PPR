#include<stdio.h>
int no_of_letters (char * text){
	int out = 0;
	
	while (text[out] != '\0'){
		out ++;
	}
	
	return (out);
}

int prefix_cutoff (char* words[], int words_length){
	int out = 0;
	int evaluator = 1;
	char first_letter;
	int shortest_word_length;
	
	for (int i = 0; i < words_length; i++){
		int len_word = no_of_letters(words[i]);
		
		if (i == 0){
			shortest_word_length = len_word;
		} else {
			shortest_word_length = (shortest_word_length < len_word) ? (len_word) : (shortest_word_length);
		}
		
		//printf("%s\t\t%d\n", words[i], len_word);
	}
	
	while ((out < shortest_word_length) && (evaluator)){
		int exit = 0;
		for (int i = 0; i < words_length; i++){
			if (i == 0){
				first_letter = words[i][out];
			} else {
				if (first_letter != words[i][out]){
					exit = 1;
					evaluator = 0;
				}
				//evaluator = evaluator && (first_letter == words[i][out]);
			}
		}
		
		if (exit){
			break;
		}
		out++;
	}
	
	return (out);
}

int main (){
	char* words[] = {"flower","flow","floght","flock"};
	int len_words = sizeof(words)/ sizeof(words[0]);
	//printf("%d\n\n\n", sizeof(words));
	int prefix = prefix_cutoff(words, len_words);
	
	printf("This is the handy work of C.\n\n\nThe first %d characters are similar in the words.\n\n\n", prefix);
	
	for (int i = 0; i < prefix; i++){
		printf("%c", words[0][i]);
	}
	
	printf("\n\n\n");
	
	return (0);
}
