function firstAndLast (element, list){
	let findFirst = true;
	let out = [-1,-1];
	list.sort(function (a, b) {return a - b});
	//console.log(list);
	
	for (let i = 0; i < list.length; i++){
		let e = list[i];
		if (e == element){
			if (findFirst){
				out[0] = i;
				out[1] = i;
				findFirst = false;
			} else {
				out[1] = i;
			}
		}
	}
	
	return (out);
}

let nums = [5,7,7,8,8,10,2];
let target = 8;

console.log(firstAndLast (target, nums));
