function sumOfThree (list, target = 0){
	let lenList = list.length;
	let out = [];
	
	for (let a = 0; a < lenList; a++){
		for (let b = 0; b < lenList; b++){
			if (b > a){
				for (let c = 0; c < lenList; c++){
					if (c > b){
						if ((a != b) && (a != c) && (b != c)){
							let aa = list[a];
							let bb = list[b];
							let cc = list[c];
							if ((aa != bb) && (aa != cc) && (bb != cc)){
								if ((aa + bb + cc) == target){
									let z = [a, b, c];
									//let z = [list[a], list[b], list[c];
									out.push(z);
								}
							}
						}
					}
				}
			}
		}
	}
	
	return out;
}

let nums = [-1,0,1,2,-1,-4];

console.log (sumOfThree(nums));
