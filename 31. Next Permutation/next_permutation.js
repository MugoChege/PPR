function numberFromList (list){
	let out = 0;
	let lenList = list.length;
	let base = 10;
	
	for (let i = 0; i < lenList; i++){
		out += (list[i] * (Math.pow(base, (lenList - 1 - i))));
	}
	
	return out;
}

function numberToList (number, originalListLen = 0){
	let out = [];
	let base = 10;
	let runningNumber = number;
	
	while (runningNumber > 0){
		let modulo = runningNumber % base;
		runningNumber -= modulo;
		runningNumber /= base;
		out.push(modulo)
	}
	
	if (originalListLen != 0){
		while (out.length < originalListLen){
			out.push(0);
		}
	}
	
	//reverse out
	out.reverse();
	
	return out;
}

function listComparison (list1, list2){
	let out = false;
	let lenList1 = list1.length;
	let lenList2 = list2.length;
	
	if (lenList1 != lenList2){
		return out;
	}
	
	let list1BoolMap = [];
	let list2BoolMap = [];
	
	for (let i = 0; i < lenList1; i++){
		list1BoolMap.push(false);
		list2BoolMap.push(false);
	}
	
	for (let i = 0; i < lenList1; i++){
		for (let j = 0; j < lenList1; j++){
			if ((list1BoolMap[i] == false) && (list2BoolMap[j] == false)){
				if (list1[i] == list2[j]){
					list1BoolMap[i] = true;
					list2BoolMap[j] = true;
					break
				}
			}
		}
	}
	
	let boolCounter = 0;
	
	for (let i = 0; i < lenList1; i++){
		if (list1BoolMap[i] && list2BoolMap[i]){
			boolCounter += 1;
		}
	}
	
	return (list1BoolMap.length == boolCounter);
}

function appears (element, array){
	let out = -1;
	
	for (let i = 0; i < array.length; i++){
		if (element == array[i]){
			out += 1;
		}
	}
	
	return out;
}

let nums = [0, 0, 5];
let lenNums = nums.length;
let numNums = numberFromList(nums);

//nums sort
//nums reverse
nums.sort();
nums.reverse();

let upperLimitNumNums = numberFromList(nums);

console.log(numNums);
console.log(upperLimitNumNums);

let runningNumber = numNums;

let nextPermutation = [];

while (runningNumber <= upperLimitNumNums){
	let tempNumsList = numberToList(runningNumber, lenNums);
	if ((listComparison(tempNumsList, nums)) && (runningNumber != numNums)){
		nextPermutation = tempNumsList;
		break;
	}
	runningNumber ++;
}

console.log(nextPermutation);

console.log("\n\n\n");
