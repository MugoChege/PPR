#include<iostream>
#include<string>

using namespace std;

bool is_palindrome (string sub){
	int len_sub = sub.size();
	int mir = len_sub / 2;
	bool out = false;
	
	for (int i = 0; i < mir; i++){
		if (i == 0){
			out = (sub[i] == sub[len_sub - 1 - i]);
		} else {
			out = out && (sub[i] == sub[len_sub - 1 - i]);
		}
	}
	
	return (out);
}

string longest_substring (string text){
	int len_text = text.size();
	string longest_text = "";
	
	for (int i = 0; i < len_text; i++){
		for (int j = (len_text - i); j >= 0; j--){
			string substring = text.substr(i, j);
			
			if (is_palindrome(substring)){
				if (longest_text.size() < substring.size()){
					longest_text = substring;
					break;
				}
			}
		}
	}
	
	return (longest_text);
}

int main (){
	string word = "bbob";
	cout << "This is the handy work of C++.\n\n\n";
	cout << longest_substring(word);
	cout << "\n\n\n";
	
	return (0);
}
