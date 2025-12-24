function isPalindrome (sub){
	let lenSub = sub.length;
	let mirror = (lenSub / 2) - ((lenSub / 2) % 1);
	let out = false;
	
	for (let a = 0; a < mirror; a++){
		if (a == 0){
			out = (sub[a] == sub[lenSub - 1 - a]);
		} else {
			out = out && (sub[a] == sub[lenSub - 1 - a]);
		}
	}
	
	return (out);
}

function longestSubString(text){
	let lenText = text.length;
	let longestText = "";
	
	for (let a = 0; a < lenText; a++){
		for (let b = 1; b < lenText; b++){
			let subString = text.substring(a, a + b + 1);
			
			if (isPalindrome(subString)){
				if (longestText.length < subString.length){
					longestText = subString;
				}
			}
		}
	}
	return (longestText);
}

let word = "babad";

console.log(longestSubString(word));
console.log("\n\n\n\n");
