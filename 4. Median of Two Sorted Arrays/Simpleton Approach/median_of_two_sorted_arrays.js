function toInteger (number){
	return (number - (number % 1));
}

function getMedian (list){
	let lenList = list.length;
	let evenLength = (lenList % 2 == 0);
	let median = 0.0;
	
	if (evenLength){
		median = (list[toInteger(lenList / 2)] + list[toInteger(lenList / 2) - 1]) / 2; 
	} else {
		median = (list[toInteger(lenList / 2)]);
	}
	
	return (median);
}

function combineList (list1, list2){
	let combinedList = [];
	
	for (i of list1){
		combinedList.push(i);
	}
	
	for (i of list2){
		combinedList.push(i);
	}
	
	combinedList.sort(function(a, b) {return a - b})
	
	return (combinedList);
}

let list1 = [1,3,5];
let list2 = [2,4];

let list_combined = combineList(list1, list2)

let median = getMedian(list_combined);

console.log(median);
console.log("\n\n\n");
