let combinations= [" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

function wordFromOdo (relevantDigits, digitsOdo){
	let out = "";
	
	for (let i = 0; i < relevantDigits.length; i++){
		out += combinations[Number(relevantDigits[i])][digitsOdo[i]];
	}
	
	return out;
}

function wordFill (relevantDigits, digitsOdo, depth, maxDepth, sampleSpace){
	let letterOptions = combinations[Number(relevantDigits[depth])];
	let lenLetterOptions = letterOptions.length;
	
	for (let i = 0; i < lenLetterOptions; i++){
		digitsOdo[depth] = i;
		if (depth < (maxDepth - 1)){
			wordFill (relevantDigits, digitsOdo, (depth + 1), maxDepth, sampleSpace);
		} else {
			sampleSpace.push(wordFromOdo(relevantDigits, digitsOdo));
		}
	}
}

function getLetterCombinations (digits){
	let out = [];
	
	let lenDigits = digits.length;
	let odo = [];
	
	let useableDigits = "";
	let sampleSize = 0;
	
	for (let i = 0; i < lenDigits; i++){
		if (combinations[Number(digits[i])] == 0){
			continue;
		}
		
		useableDigits += digits[i];
		odo.push(0);
	}
	
	let lenUseableDigits = useableDigits.length;
	
	wordFill (useableDigits, odo, 0, lenUseableDigits, out);
	
	return (out);
}

digits = "6872"
console.log(getLetterCombinations(digits))
