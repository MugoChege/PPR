var result_number: Int = 0;
const val number_of_elements: Int = 3

data class Result (var values: Array<Int>, var number_of_values: Int, var not_null: Boolean){
	
	public fun set_values(list: Array<Int>): Unit{
		not_null = true;
		number_of_values = values.size;
		
		for (i in 0 until number_of_values){
			values[i] = list[i];
		}
	}
	
	constructor (list: Array<Int>): this(list, list.size, true){
	}
	
	constructor (): this(Array(number_of_elements){0}, 0, false){
	}
	
	public fun print_values(): Unit{
		println ("This is the hand work of Kotlin");
		var out: Int = 0;
		
		for (i in 0 until number_of_elements){
			print (values[i]);
			out += values[i];
			
			if (i < (number_of_values - 1)){
				print ("\t");
			}
		}
		
		print("\nThe sum of the values is:\t");
		println(out);
	}
	
	public fun empty_result(): Unit{
		not_null = false;
		
		for (i in 0 until number_of_values){
			values[i] = 0;
		}
		
		number_of_values = 0;
	}
}

fun factorial (number: Int): Int{
	var out: Int = 1;
	
	for (i in number downTo 1){
		out *= i;
	}
	
	return (out);
}

fun absolute (number: Int) : Int {
	return if (number < 0) (number * -1) else (number * 1);
}

fun sum_of_three_closest (list: Array<Int>, target: Int, sample_size: Int): Array<Result>{
	var result_cursor: Int = 0;
	var closest_difference: Int = 0;
	var first_execution: Boolean = true;
	var len_list: Int = list.size;
	var out: Array<Result> = Array(sample_size) {Result()};
	
	for (a in 0 until len_list){
		for (b in 0 until len_list){
			if (b > a){
				for(c in 0 until len_list){
					if (c > b){
						if ((a != b) && (a != c) && (b != c)){
							var aa: Int = list[a];
							var bb: Int = list[b];
							var cc: Int = list[c];
							
							//if ((aa != bb) && (aa != cc) && (bb != cc)){
							if (true){
								var difference: Int = absolute(target - (aa + bb + cc));
								var update_array: Boolean = false;
								
								if (first_execution){
									closest_difference = difference;
									first_execution = false;
									
									update_array = true;
								} else {
									if (difference < closest_difference){
										closest_difference = difference;
										
										if (result_cursor > 0){
											for (i in 0 until result_cursor){
												out[result_cursor].empty_result();
											}
											result_cursor = 0;
										}
										
										update_array = true;
									} else if (difference == closest_difference){
										update_array = true;
									}
								}
								
								if (update_array){
									var y: Array<Int> = arrayOf(aa, bb, cc);
									out[result_cursor] = Result(y);
									result_cursor += 1;
									result_number = result_cursor;
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

fun main (){
	val nums: Array<Int> = arrayOf(-1,2,1,-4);
	val len_nums: Int = nums.size;
	val target: Int = 1;
	
	val sample_space = (factorial(len_nums) / (factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
	
	var h: Array<Result> = sum_of_three_closest(nums, target, sample_space);
	
	for (i in 0 until result_number){
		h[i].print_values();
	}
}
