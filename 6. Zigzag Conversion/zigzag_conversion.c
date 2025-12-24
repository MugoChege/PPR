#include<stdio.h>

int text_space = 0;

void zigzag (char* text, int len_text, int rows, char out[][text_space]){
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < text_space; j++){
			out[i][j] = '\0';
		}
	}
	
	int straight = 1;
	int text_cursor = 0;
	int column_cursor = 0;
	
	while (text_cursor < len_text){
		if (straight){
			for (int i = 0; i < rows; i++){
				if (text_cursor < len_text){
					out[i][column_cursor / rows] = text[text_cursor];
					text_cursor++;
					column_cursor++;
				} else {
					break;
				}
			}
			straight = 0;
		} else {
			for (int k = 0; k < (rows - 2); k++){
				for (int i = 0; i < rows; i++){
					if (text_cursor < len_text){
						if (i == (rows - 2 - k)){
							out[i][column_cursor / rows] = text[text_cursor];
							text_cursor++;
							column_cursor++;
						} else {
							out[i][column_cursor / rows] = ' ';
							column_cursor++;
						}
					} else {
						break;
					}
				}
				straight = 1;
			}
		}
	}
}

int no_of_letters (char * text){
	int out = 0;
	while (text[out] != '\0'){
		out += 1;
	}
	
	return (out);
}

int main () {
	char text[] = "PAYPALISHIRING";
	int len_text = no_of_letters(text);
	int row = 4;
	char out[row][len_text + 1];
	text_space = len_text + 1;
	
	zigzag(text, len_text, row, out);
	
	for (int i = 0; i < row; i++){
		printf("%s\n", out[i]);
	}
	
	
	
	return (0);
}
