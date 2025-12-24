function getTarget (nums, target){
	let lenNums = nums.length();
	let out = null;
	
	for (let a = 0; a < lenNums; a++){
		let exit_loop = false;
		for (let b = 0; b < lenNums; b++){
			if (b == a){
				continue;
			} else {
				if ((nums[a] + nums[b]) == target){
					out = [a,b];
					exit_loop = true;
					break;
				}
			}
		}
		
		if (exit_loop){
			break
		}
	}
	
	return out;
}

numberList = [1,2,3,4,5,6,7,8,9];
target = 16;

let indices = getTarget(numberList, target);
console.log (indices);

if (!(indices === null)){
	console.log (numberList[indices[0]]);
	console.log (numberList[indices[1]]);
}
