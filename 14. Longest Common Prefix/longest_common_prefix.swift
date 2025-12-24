func prefix_cutoff (words: Array<String>) -> Int{
	let word_length: Int = words.count;
	var evaluator: Bool = true;
	var out: Int = 0;
	var shortest_word_length: Int = 0;
	var first_letter: Character = "\0";
	
	for i in 0..<word_length{
		let len_word: Int = words[i].count;
		
		if (i == 0){
			shortest_word_length = len_word;
		} else {
			shortest_word_length = (shortest_word_length < len_word) ? (len_word) : (shortest_word_length);
		}
	}
	
	while ((out < shortest_word_length) && (evaluator)){
		var exit: Bool = false;
		
		for i in 0..<word_length{
			let index = words[i].index(words[i].startIndex, offsetBy: out);
			if (i == 0){
				first_letter = words[i][index];
			} else {
				if (first_letter != words[i][index]){
					exit = true;
					evaluator = false;
				}
			}
		}
		
		if (exit){
			break;
		}
		
		out += 1;
	}
	
	return (out);
}

let words: Array<String> = ["flower","flow","flight","flock"];
let len_words: Int = words.count;

let pref: Int = prefix_cutoff(words: words);

print ("This is the handy work of Swift.\n\n\nThe first ", terminator: "");
print (pref, terminator: "");
print (" characters are similar in the words.\n\n\n");

for i in 0..<pref{
	let index = words[0].index(words[0].startIndex, offsetBy: i);
	print(words[0][index], terminator: "")
}

print("\n\n\n");
