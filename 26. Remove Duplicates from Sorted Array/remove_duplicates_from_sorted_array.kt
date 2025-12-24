fun duplicates_shifting_remove (list: Array<Int>) : Int{
	var counter: Int = 0;
	val len_list: Int = list.size;
	
	list.sort();
	
	for (i in (len_list - 1) downTo 0){
		val element: Int = list[i];
		var unique: Boolean = true;
		
		for (j in 0 until i){
			if (element == list[j]){
				unique = false;
				break;
			}
		}
		
		if (unique == false){
			counter += 1;
			val holder: Int = list[i];
			
			for (j in i until (len_list - 1)){
				list[j] = list[j + 1];
			}
			
			list[len_list - 1] = holder;
		}
	}
	
	return (counter);
}

fun main () {
	var nums: Array<Int> = arrayOf(0,0,1,1,1,2,2,3,3,4);
	val lenNums: Int = nums.size;
	
	val rem: Int = duplicates_shifting_remove(nums);
	
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
