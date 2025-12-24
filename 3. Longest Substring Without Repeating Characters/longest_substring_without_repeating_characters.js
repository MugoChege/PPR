function longestSubstring (text){
	let lenText = text.length;
	let longestText = "";
	
	for (let a = 0; a < lenText; a++){
		for (let b = a; b < (lenText - a); b++){
			let subString = text.slice(a, a + b);
			let letter = text.slice (a + b, a + b + 1);
			//console.log(subString + "\t\t\t" + letter);
			
			if (subString.includes(letter)){
				if (longestText.length < subString.length){
					longestText = subString;
				}
				break;
			}
		}
	}
	
	return (longestText);
}

let w = longestSubstring("pwwkew");
console.log(w);
console.log("\n\n\n");
