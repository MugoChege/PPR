#include<iostream>
#include<string>
#include<vector>

using namespace std;

int prefix_cutoff (vector<string> words){
	int word_length = words.size();
	bool evaluator = true;
	int out = 0;
	int shortest_word_length;
	char first_letter;
	
	for (int i = 0; i < word_length; i++){
		int len_word = words[i].size();
		
		if (i == 0){
			shortest_word_length = len_word;
		} else {
			shortest_word_length = (shortest_word_length < len_word) ? (len_word) : (shortest_word_length);
		}
	}
	
	while ((out < shortest_word_length) && (evaluator)){
		bool exit = false;
		
		for (int i = 0; i < word_length; i++){
			if (i == 0){
				first_letter = words[i][out];
			} else {
				if (first_letter != words[i][out]){
					exit = true;
					evaluator = false;
				}
			}
		}
		
		if (exit){
			break;
		}
		
		out++;
	}
	
	return (out);
}

int main () {
	vector<string> words = {"flower","flow","floght","flock"};
	int len_words = words.size();
	
	int prefix = prefix_cutoff(words);
	
	cout << "This is the handy work of C++.\n\n\nThe first " << prefix << " characters are similar in the words.\n\n\n";
	
	for (int i = 0; i < prefix; i++){
		cout << words[0][i];
	}
	
	cout << "\n\n\n";
	
	return (0);
}
