function duplicatesShiftingRemove(list){
	let counter = 0;
	let lenList = list.length;
	
	list.sort(function (a, b) {return a - b});
	
	for (let i = (lenList - 1); i >= 0; i--){
		let element = list[i];
		let unique = true;
		
		for (let j = 0; j < i; j++){
			if (element == list[j]){
				unique = false;
				break;
			}
		}
		
		if (unique == false){
			counter += 1;
			holder = list[i];
			
			for (let j = i; j < (lenList - 1); j++){
				list[j] = list[j + 1];
			}
			
			list[lenList - 1] = holder;
		}
	}
	
	//console.log(list.slice();
	
	return (counter);
}

let nums = [0,0,1,1,1,2,2,3,3,4];
let val = duplicatesShiftingRemove(nums);

console.log(val);
console.log("\n\n[" + String(nums) + "]\n\n");
console.log(nums.slice(0, (nums.length - val)));
console.log("\n\n\n");
