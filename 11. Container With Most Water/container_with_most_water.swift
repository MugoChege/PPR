struct HeightPoint{
	var heightPoint1: Int;
	var heightPoint2: Int;
}

func absolute (number: Int) -> Int{
	return ((number < 0) ? (number * -1) : (number * 1));
}

func get_volume (height1: Int, height2: Int, width: Int) -> Int{
	var height: Int =  (height1 < height2) ? (height1) : (height2);
	
	return (height * width);
}

func container_points(list: Array<Int>) -> HeightPoint {
	var largest_volume: Int = 0;
	var nje: HeightPoint = HeightPoint(heightPoint1: 0, heightPoint2: 0);
	var len_list: Int = list.count;
	
	for a in 0..<len_list{
		for b in stride(from: (len_list - 1), to: 1, by: -1){
			if a == b{
				continue;
			} else if b < a{
				break;
			} else {
				var interval = absolute(number: (a - b));
				var volume = get_volume (height1: list[a], height2: list[b], width: interval);
				
				if (largest_volume < volume){
					largest_volume = volume;
					
					nje.heightPoint1 = a;
					nje.heightPoint2 = b;
				}
			}
		}
	}
	
	return (nje);
}

let height_list: Array<Int> = [1,8,6,2,5,4,8,3,7];
let len_height_list: Int = height_list.count;
let height_indices: HeightPoint = container_points(list: height_list);

let height1: Int = height_list[height_indices.heightPoint1];
let height2: Int = height_list[height_indices.heightPoint2];

let interval = absolute (number: (height_indices.heightPoint1 - height_indices.heightPoint2));
let volume = get_volume (height1: height1, height2: height2, width: interval);
print ("This is the handy work of Swift\n\n");

print (height_indices);

print ("\n\nThe heights given the points are: \(height1) on one end and \(height2) on the other end. The difference between the two points is \(interval) giving a total volume of \(volume).\n\n");
