#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> zigzag (string text, int rows){
	vector<string> out;
	
	for (int i = 0; i < rows; i++){
		out.push_back("");
	}
	
	int len_text = text.size();
	bool straight = true;
	int text_cursor = 0;
	
	while (text_cursor < len_text){
		if (straight){
			for (int row_cursor = 0; row_cursor < rows; row_cursor++){
				if (text_cursor < len_text){
					out[row_cursor] += text[text_cursor];
					text_cursor++;
				} else {
					break;
				}
			}
			straight = false;
		} else {
			for (int term = 0; term < (rows - 2); term++){
				for (int row_cursor = 0; row_cursor < rows; row_cursor++){
					if (text_cursor < len_text){
						if (row_cursor == (rows - 2 - term)){
							out[row_cursor] += text[text_cursor];
							text_cursor++;
						} else {
							out[row_cursor] += ' ';
						}
					} else {
						break;
					}
				}
			}
			straight = true;
		}
	}
	
	return (out);
}

int main () {
	string text = "PAYPALISHIRING";
	int rows = 5;
	
	vector<string> line = zigzag(text, rows);
	
	cout << "This is the handy work of C++\n\n\n" << endl;
	
	for (int i = 0; i < line.size(); i++){
		cout << line[i] << endl;
	}
	
	cout << "\n\n\n";
	
	return (0);
}
