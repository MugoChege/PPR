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

function combineList (list1Original, list2Original){
	let list1 = list1Original.sort(function (a, b){return a - b});
	let list2 = list2Original.sort(function (a, b){return a - b});
	
	let lenList1 = list1.length;
	let lenList2 = list2.length;
	
	let list1Cursor = 0;
	let list2Cursor = 0;
	
	let nje = [];
	
	while ((list1Cursor < lenList1) || (list2Cursor < lenList2)){
		let elementList1 = null;
		let elementList2 = null;
		let appendingElement = null;
		
		if (list1Cursor < lenList1){
			elementList1 = list1[list1Cursor];
		}
		
		if (list2Cursor < lenList2){
			elementList2 = list2[list2Cursor];
		}
		
		if ((elementList1 != null) && (elementList2 != null)){
			if (elementList1 < elementList2){
				appendingElement = elementList1;
				list1Cursor += 1;
			} else {
				appendingElement = elementList2;
				list2Cursor += 1;
			}
		} else if (elementList1 == null){
			appendingElement = elementList2;
			list2Cursor += 1;
		} else if (elementList2 == null){
			appendingElement = elementList1;
			list1Cursor += 1;
		}
		
		nje.push(appendingElement);
	}
	
	return (nje);
}

let list1 = [1,3,5];
let list2 = [2,4];

let list_combined = combineList(list1, list2)

let median = getMedian(list_combined);

console.log("This is the handy work of JavaScript\n\n");
console.log(median);
console.log("\n\n\n");
