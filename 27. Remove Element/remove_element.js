function removeByShifting (element, list){
	let count = 0;
	let lenList = list.length;
	
	for (let i = (lenList - 1); i >= 0; i--){
		if (list[i] == element){
			count += 1;
			let holder = list[i];
			
			for (let j = i; j < lenList; j++){
				list[j] = list[j + 1];
			}
			
			list[lenList - 1] = holder;
		}
	}
	
	return (count)
}

let nums = [0,1,2,2,3,0,4,2];
let val = 2;

let rem = removeByShifting(val, nums);

console.log(rem);
console.log("\n\n\n");
console.log("[" + String(nums) + "]");
console.log(nums.slice(0, (nums.length - rem)));
console.log("\n\n\n");
