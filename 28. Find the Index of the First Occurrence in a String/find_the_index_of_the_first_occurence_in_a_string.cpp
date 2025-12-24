#include<iostream>
#include<string>

using namespace std;

bool CASE_SENSITIVE = false;

void to_upper (string &text){
	int len_text = text.size();
	
	for (int i = 0; i < len_text; i++){
		if (((int)text[i] >= 97) && ((int)text[i] < 123)){
			text[i] -= 32;
		}
	}
}

bool compare_string (string text1, string text2){
	bool out = false;
	int len_text1 = text1.size();
	int len_text2 = text2.size();
	
	if ((len_text1 == 0) && (len_text2 == 0)){
		out = true;
		return (out);
	}
	
	if (len_text1 != len_text2){
		return (out);
	}
	
	string text1_c = text1;
	string text2_c = text2;
	
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

int first_occurence (string needle, string haystack){
	int len_needle = needle.size();
	int len_haystack = haystack.size();
	int out = -1;
	
	if (len_needle > len_haystack){
		out = -1;
	} else if (len_needle == len_haystack){
		out = compare_string(needle, haystack) ? 0 : -1;
	} else {
		int len_searchable = len_haystack - len_needle + 1;
		
		for (int i = 0; i < len_searchable; i++){
			string substring = haystack.substr(i,len_needle);
			
			if (compare_string(needle, substring)){
				out = i;
				break;
			}
		}
	}
	
	return (out);
}

int main () {
	string haystack = "leetcode";
	string needle = "et";
	
	printf("This is the handy work of C++.\n\n\n%d\n\n\n", first_occurence(needle, haystack));
	
	return (0);
}
