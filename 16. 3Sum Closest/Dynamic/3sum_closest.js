function sumOfTheResult (list){
	let out = 0;
	
	for (i of list){
		for (j of i){
			out += j;
		}
	}
	
	return out;
}

function absoluteValue(number){
	return (number > 0) ? (number * 1) : (number * -1);
}

function sumOfThreeClosest(list, target = 0){
	let len_list = list.length;
	let out = [];
	let closest = null;
	
	for (let a = 0; a < len_list; a++){
		for (let b = 0; b < len_list; b++){
			if (b > a){
				for (let c = 0; c < len_list; c++){
					if (c > b){
						if ((a != b) && (a != c) && (b !=c)){
							let aa = list[a];
							let bb = list[b];
							let cc = list[c];
							
							////if (($aa != $bb) && ($aa != $cc) && ($bb != $cc)) //toggle this for no similar value elements
							
							if (true){
								let difference = absoluteValue((aa + bb + cc) - target);
								//console.log(String(aa) + "\t" + String(bb) + "\t" + String(cc) + "\t\t" + String(difference) + "\n");
								
								if (closest === null){
									closest = difference;
								}
								
								if (difference == closest){
									//let z = [a, b, c];
									let z = [list[a], list[b], list[c]];
									out.push(z);
								} else if (difference < closest){
									let z = [list[a], list[b], list[c]];
									//let z = [a, b, c];
									out.push(z);
									closest = distance;
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

let nums = [-1,2,1,-4];

let closest = sumOfThreeClosest(nums,1);

console.log(JSON.stringify(closest));
console.log(sumOfTheResult(closest));
console.log("\n\n\n");
