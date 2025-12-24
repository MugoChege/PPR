function longestCommonPrefix (list){
	let out = "";
	let shortestWordLen = 0;
	
	for (i of list){
		if (i == list[0]){
			shortestWordLen = i.length;
		}
		
		if ((0 - i.length) > (-1 * shortestWordLen)){
			shortestWordLen = i.length;
		}
	}
	
	for (let letter_index = 0; letter_index < shortestWordLen; letter_index++){
		let letter = "";
		let common = true;
		
		for (word of list){
			if (word == list[0]){
				letter = word[letter_index]
			} else {
				if (letter != word[letter_index]){
					common = false
					break;
				}
			}

		}
					
		if (common){
			out += letter;
			common = true;
		}
	}
	
	return (out);
}

let strings = ["flower", "flow", "flight"]
console.log (longestCommonPrefix(strings));
console.log ("\n\n\n\n")
