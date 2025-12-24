function sumOfFour(list, target = 0){
	let lenList = list.length;
	let out = [];
	
	for (let a = 0; a < lenList; a++){
		for (let b = 0; b < lenList; b++){
			if (b > a){
				for (let c = 0; c < lenList; c++){
					if (c > b){
						for (let d = 0; d < lenList; d++){
							if (d > c){
								if (a != b != c != d){
									let aa = list[a];
									let bb = list[b];
									let cc = list[c];
									let dd = list[d];
									
									//if (aa != bb != cc != dd){
									if (true){
										if ((aa + bb + cc + dd) == target){
											//let z = [a, b, c, d];
											let z = [list[a], list[b], list[c], list[d]];
											
											out.push(z);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return (out);
}

nums = [1,0,-1,0,-2,2];
console.log(JSON.stringify(sumOfFour(nums)));
console.log("\n\n\n");
