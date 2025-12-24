function absolute (number){
	return (number < 0) ? (number * -1) : (number * 1);
}

function getVolume (height1, height2, width){
	let height = (height1 < height2) ? (height1) : (height2);
	
	return (height * width);
}

function containerPoints (list){
	let lenList = list.length;
	let largestVolume = 0;
	let volumeIndexes = [];
	
	for (let a = 0; a < lenList; a++){
		for (let b = (lenList - 1); b > 0; b--){
			if (a == b){
				continue;
			} else if (b < a){
				break;
			} else {
				//let smallerElement = (list[a] < list[b]) ? (list[a]) : (list[b]);
				let interval = absolute(a - b);
				//let volume = smallerElement * interval;
				let volume = getVolume(list[a], list[b], interval);
				
				if (largestVolume < volume){
					largestVolume = volume
					volumeIndexes = [a,b];
				}
			}
		}
	}
	
	return (volumeIndexes);
}

let heightList = [1,8,6,2,5,4,8,3,7];
let heightIndices = containerPoints(heightList);
let height1 = heightList[heightIndices[0]]
let height2 = heightList[heightIndices[1]]
let interval = absolute(heightIndices[0] - heightIndices[1]);

console.log("This is the handy work of JavaScript\n\n");
console.log(heightIndices);
console.log("The heights given the points are: " + String(height1) + " on one end and " + String(height2) + " on the other end. The difference between the two points is " + String(interval) + " giving a total volume of " + String(getVolume(height1, height2, interval)) + "\n\n");
