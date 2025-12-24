fun get_median (list: Array<Int>): Float{
	val len_list: Int = list.size;
	val even_length: Boolean = (len_list % 2 == 0);
	var median: Float = 0.0f;
	
	if (even_length){
		median = ((list[len_list / 2].toFloat() + list[(len_list / 2) - 1].toFloat()) / 2);
	} else {
		median = (list[len_list / 2]).toFloat();
	}
	
	return (median);
}

fun combine_list (list1: Array<Int>, list2: Array<Int>): Array<Int>{
	val len_list1: Int = list1.size;
	val len_list2: Int = list2.size;
	var combined_list: Array<Int> = Array(len_list1 + len_list2) {0};
	var combined_list_cursor: Int = 0;
	for (i in 0 until len_list1){
		combined_list[combined_list_cursor] = list1[i];
		combined_list_cursor += 1;
	}
	
	for (i in 0 until len_list2){
		combined_list[combined_list_cursor] = list2[i];
		combined_list_cursor += 1;
	}
	
	//sort
	combined_list.sort();
	
	return (combined_list);
}

fun main (){
	val list1: Array<Int> = arrayOf(1,3);
	val list2: Array<Int> = arrayOf(2,4);
	
	var list_combined = combine_list(list1, list2);
	
	var median = get_median(list_combined);
	
	println(median);
	println("\n\n\n");
}
