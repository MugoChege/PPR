fun removeByShifting (element: Int, list: Array<Int>) : Int {
	var count: Int = 0;
	val lenList: Int = list.size;
	
	for (i in (lenList - 1) downTo 0){
		if (list[i] == element){
			count += 1;
			var holder = list[i];
			
			for (j in i until (lenList - 1)){
				list[j] = list[j + 1];
			}
			
			list[lenList - 1] = holder;
		}
	}
	
	return (count);
}

fun main () {
	var nums: Array<Int> = arrayOf(0,1,2,2,3,0,4,2);
	val lenNums: Int = nums.size;
	val value: Int = 2;
	
	val rem = removeByShifting(value, nums);
	
	println("This is the handy work of Kotlin\n\n");
	println(rem);
	println("\n\n\n");
	
	
	print("[");
	for (i in 0 until lenNums){
		print(nums[i]);
		if (i == (lenNums - 1)){
			println ("]");
		} else {
			print(", ");
		}
	}
	
	println("\n\n");
	
	print("[");
	for (i in 0 until (lenNums - rem)){
		print(nums[i]);
		if (i == ((lenNums - rem) - 1)){
			println ("]");
		} else {
			print(", ");
		}
	}
	
	println("\n\n");
}
