data class HeightPoint(var heightPoint1: Int, var heightPoint2: Int){
	constructor () : this (0,0){}
}

fun absolute (number: Int): Int {
	return (if (number < 0) (number * -1) else (number * 1));
}

fun get_volume (height1: Int, height2: Int, width: Int): Int{
	var height: Int = if (height1 < height2) (height1) else (height2);
	
	return (height * width);
}

fun container_points (list: Array<Int>): HeightPoint {
	var largest_volume: Int = 0;
	var nje: HeightPoint = HeightPoint();
	var len_list: Int = list.size;
	
	for (a in 0 until len_list){
		for (b in (len_list - 1) downTo 1){
			if (a == b){
				continue;
			} else if (b < a){
				break;
			} else {
				var interval: Int = absolute(a - b);
				var volume: Int = get_volume (list[a], list[b], interval);
				
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

fun main (){
	val height_list: Array<Int> = arrayOf(1,8,6,2,5,4,8,3,7);
	val len_height_list: Int = height_list.size;
	
	val height_indices: HeightPoint = container_points(height_list);
	
	val height1: Int = height_list[height_indices.heightPoint1];
	val height2: Int = height_list[height_indices.heightPoint2];
	
	val interval: Int = absolute(height_indices.heightPoint1 - height_indices.heightPoint2);
	
	println ("This is the handy work of Kotlin\n\n");
	
	val hp1: Int = height_indices.heightPoint1;
	val hp2: Int = height_indices.heightPoint2;
	
	println ("[$hp1, $hp2]\n\n");
	
	val v: Int = get_volume(height1, height2, interval);
	
	println ("The heights given the points are: $height1 on one end and $height2 on the other end. The difference between the two points is $interval giving a total volume of $v\n\n"); 
}
