#include <iostream>
#include <string>
#include <vector>

using namespace std;

string combinations[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int to_integer (char let){
	return ((int) let - 48);
}

string word_from_odo (string relevant_digits, int* digits_odo){
	string nje = "";
	int length = relevant_digits.size();
	
	for (int i = 0; i < length; i++){
		int dig = to_integer(relevant_digits[i]) % 10;
		nje += combinations[dig][digits_odo[i]];
	}
	
	return (nje);
}

void word_fill (string relevant_digits, int* digits_odo, int depth, vector<string> &sample_space){
	int len_letter_options = combinations[to_integer(relevant_digits[depth])].size();
	int max_depth = relevant_digits.size();
	
	for (int i = 0; i < len_letter_options; i++){
		digits_odo[depth] = i;
		if (depth < (max_depth - 1)){
			word_fill (relevant_digits, digits_odo, (depth + 1), sample_space);
		} else {
			string word = word_from_odo (relevant_digits, digits_odo);
			sample_space.push_back(word);
		}
	}
}

vector<string> get_letter_combinations(string digits){
	vector<string> nje = {};
	
	int len_digits = digits.size();
	int odo_length = 0;
	string useable_digits = "";
	
	for (int i = 0; i < len_digits; i++){
		int len_letters = combinations[to_integer(digits[i])].size();
		
		if (len_letters == 0){
			continue;
		}
		
		useable_digits += digits[i];
		odo_length += 1;
	}
	
	int odo[odo_length];
	
	for (int i = 0; i < odo_length; i++){
		odo[i] = 0;
	}
	
	word_fill (useable_digits, odo, 0, nje);
	
	return (nje);	 
}

int main (){
	string digits = "68072";
	vector<string> words = get_letter_combinations(digits);
	
	cout << "This is the handy work of C++.\n\n";
	
	for (int i = 0; i < words.size(); i++){
		cout << words[i] << endl;
	}
	
	cout << "\n\n";
	
	return (0);
}
