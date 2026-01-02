let combinations: Array<String> = [" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];

func word_from_odo (_ relevant_digits: String,_ digits_odo: Array<Int>) -> String{
	var nje: String = "";
	for i in 0..<digits_odo.count{
		let rindex = relevant_digits.index(relevant_digits.startIndex, offsetBy: i);
		let digit: Int = Int(String(relevant_digits[rindex]))!;
		let button: String = combinations[digit];
		let nindex = button.index(button.startIndex, offsetBy: digits_odo[i]);
		nje.append(button[nindex]);
	}
	
	return (nje);
}

func word_fill(_ relevant_digits: String,_ digits_odo: Array<Int>,_ depth: Int,_ sample_space: inout Array<String>) -> (){
	let rindex = relevant_digits.index(relevant_digits.startIndex, offsetBy: depth);
	let len_letter_options: Int = combinations[Int(String(relevant_digits[rindex]))!].count;
	let max_depth: Int = relevant_digits.count;
	var temp_digits_odo: Array<Int> = digits_odo;
	
	for i in 0..<len_letter_options{
		temp_digits_odo[depth] = i;
		if (depth < (max_depth - 1)){
			word_fill (relevant_digits, temp_digits_odo, (depth + 1), &sample_space);
		} else {
			let word: String = word_from_odo (relevant_digits, temp_digits_odo);
			sample_space.append(word);
		}
	}
	
}

func get_letter_combinations (_ digits: String) -> Array<String>{
	var nje: Array<String> = [];
	
	let len_digits: Int = digits.count;
	var odo: Array<Int> = [];
	
	var useable_digits: String = "";
	
	for i in 0..<len_digits{
		let dindex = digits.index(digits.startIndex, offsetBy: i);
		let no_of_letters = combinations[Int(String(digits[dindex]))!].count;
		
		if (no_of_letters == 0){
			continue;
		}
		
		useable_digits.append(digits[dindex]);
		
		odo.append(0);
	}
	
	//let len_useable_digits = useable_digits.count;
	word_fill (useable_digits, odo, 0, &nje);
	
	return (nje);
}

let digits: String = "68072";
//let odo: Array<Int> = Array(repeating: 1, count: digits.count);
print(get_letter_combinations(digits));
