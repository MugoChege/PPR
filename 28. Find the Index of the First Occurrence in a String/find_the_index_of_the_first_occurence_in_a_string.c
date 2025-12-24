#include<stdio.h>

int CASE_SENSITIVE = 1;

int no_of_characters (char* text){
	int out = 0;
	
	while (text[out] != '\0'){
		out++;
	}
	
	return (out);
}

int to_upper (char* text){
	int len_text = no_of_characters(text);
	
	for (int i = 0; i < len_text; i++){
		if (((int)text[i] >= 97) && ((int)text[i] < 123)){
			text[i] -= 32;
		}
	}
}

int compare_string (char* text1, char* text2){
	int out = 0;
	int len_text1 = no_of_characters(text1);
	int len_text2 = no_of_characters(text2);
	
	if ((len_text1 == 0) && (len_text2 == 0)){
		out = 1;
		return (out);
	}
	
	if (len_text1 != len_text2){
		return (out);
	}
	
	
	char text1_c[len_text1 + 1];
	char text2_c[len_text2 + 1];
	
	for (int i = 0; i < len_text1; i++){
		text1_c[i] = text1[i];
		text2_c[i] = text2[i];
	}
	
	text1_c[len_text1] = '\0';
	text2_c[len_text1] = '\0';
	
	if (CASE_SENSITIVE){
		to_upper(text1_c);
		to_upper(text2_c);
	}
	
	for (int i = 0; i < len_text1; i++){
		if (i == 0){
			out = (text1_c[i] == text2_c[i]);
		} else {
			out = out && (text1_c[i] == text2_c[i]);
		}
	}
	
	return (out);
}

int first_occurence (char* needle, char* haystack){
	int len_needle = no_of_characters(needle);
	int len_haystack = no_of_characters(haystack);
	int out = -1;
	
	if (len_needle > len_haystack){
		out = -1;
	} else if (len_needle == len_haystack){
		out = compare_string(needle, haystack) ? 0 : -1;
	} else {
		int len_searchable = len_haystack - len_needle + 1;
		char substring[len_needle + 1];
		substring[len_needle] = '\0';
		for (int i = 0; i < len_searchable; i++){
			for (int j = 0; j < len_needle; j++){
				substring[j] = haystack[i + j];
			}
			
			if (compare_string(needle, substring)){
				out = i;
				break;
			}
		}
	}
	
	return (out);
}

int main () {
	char haystack[] = "leetcode";
	char needle[] = "et";
	
	printf("This is the handy work of C.\n\n\n%d\n\n\n", first_occurence(needle, haystack));
	
	return (0);
}
