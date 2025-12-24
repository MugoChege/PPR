let CASE_SENSITIVE = false;

function compareStrings(text1, text2){
	let out = false;
	
	if (CASE_SENSITIVE){
		text1 = text1.toUpperCase();
		text2 = text2.toUpperCase();
	}
	
	if (text1 === "" && text2 === ""){
		out = true;
		return out;
	}
	
	if (text1.length != text2.length){
		return out;
	}
	
	for (let i = 0; i < text1.length; i++){
		if (i == 0){
			if (text1[i] == text2[i]){
				out = true;
			} else {
				out = false;
			}
		} else {
			out = out && (text1[i] == text2[i]);
		}
	}
	
	return (out);
}

function firstOccurence (needle, haystack){
	let lenNeedle = needle.length;
	let lenHaystack = haystack.length;
	let out = -1;
	
	if (lenNeedle > lenHaystack){
		out = -1;
	} else if (lenNeedle == lenHaystack) {
		let found = compareStrings(needle, haystack);
		out = found ? 0 : -1;
	} else {
		let lenSearchable = lenHaystack - lenNeedle + 1;
		for (let i = 0; i < lenSearchable; i++){
			if (compareStrings(needle, haystack.slice(i, (i + lenNeedle)))){//complete this 
				out = i;
				break;
			}
		}
	}
	
	return (out);
}

console.log(firstOccurence("ode", "leetcode"));
