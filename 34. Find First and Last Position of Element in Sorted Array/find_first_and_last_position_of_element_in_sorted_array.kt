fun first_and_last (element: Int, list: Array<Int>) : Array<Int>{
	var find_first: Boolean = true;
	val len_list: Int = list.size;
	var out: Array<Int> = arrayOf(-1, -1);
	list.sort();
	
	for (i in 0 until len_list){
		if (element == list[i]){
			if (find_first){
				out[0] = i;
				out[1] = i;
				find_first = false;
			} else {
				out[1] = i;
			}
		}
	}
	
	return (out);
}

fun main () {
	var nums: Array<Int> = arrayOf(5,7,7,8,8,10,2);
	var target: Int = 8;
	
	var positions: Array<Int> = first_and_last (target, nums);
	
	print("This is the handy work of Java\n\n\n[");
	print(positions[0]);
	print(", ");
	print(positions[1]);
	println("]\n\n");
}
