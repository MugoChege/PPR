let combinations = {
	0: " ",
	1: "",
	2: "abc",
	3: "def",
	4: "ghi",
	5: "jkl",
	6: "mno",
	7: "pqrs",
	8: "tuv",
	9: "wxyz"
	}
	
function letterCombinations (digits){
	let out = [];
	digits = String(digits);
	//console.log(digit);
	for (dig of digits){
		//console.log(dig);
		let keyLetters = combinations[Number(dig)];
		//console.log(keyLetters);
		if ((out.length == 0)){ //(out == []) && 
			for (letter of keyLetters){
				out.push(letter);
			}
		} else {
			let holder = []
			for (letter of keyLetters){
				for (outWords of out){
					holder.push(outWords + letter);
				}
			}
			
			out = holder;
		}
	}
	
	out.sort();
	
	return (out);
}

let digits = "239";
//console.log (letterCombinations(digits));

let c = letterCombinations(digits);

for (a of c){
	console.log(a);
}
