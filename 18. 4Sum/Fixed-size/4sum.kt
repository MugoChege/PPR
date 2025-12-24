const val number_of_elements: Int = 4;
var result_number: Int = 0;

class Result (var values: Array<Int>, var number_of_values: Int, var not_null: Boolean){
	
	constructor (): this(Array(number_of_elements) {0}, 0, false){
	}
	
	constructor (list: Array<Int>): this(list, list.size, true){
	}
	
	fun print_values(): Unit{
		for (i in 0 until number_of_values){
			print(values[i]);
			
			if (i < (number_of_values - 1)){
				print("\t");
			}
		}
		println();
	}
}

fun not_equal_list (list: Array<Int>): Boolean{
	val len_list: Int = list.size;
	var nje: Boolean = true;
	
	for (i in 0 until len_list){
		for (j in 0 until len_list){
			if (i != j){
				if (list[i] == list[j]){
					nje = false;
				}
			}
		}
	}
	return nje
}

fun factorial (number: Int): Int {
	var out: Int = 1;
	
	for (i in number downTo 1){
		out *= i;
	}
	
	return out;
}

fun sum_of_four (list: Array<Int>, target: Int, sample_size: Int): Array<Result>{
	var result_cursor: Int = 0;
	val len_list: Int = list.size;
	
	var nje: Array<Result> = Array(sample_size) {Result()};
	
	for (a in 0 until len_list){
		for (b in 0 until len_list){
			if (b > a){
				for (c in 0 until len_list){
					if (c > b){
						for (d in 0 until len_list){
							if (d > c){
								val u: Array<Int> = arrayOf(a, b, c, d);
								
								if (not_equal_list(u)){
									val aa: Int = list[a];
									val bb: Int = list[b];
									val cc: Int = list[c];
									val dd: Int = list[d];
									
									val z: Array<Int> = arrayOf(aa, bb, cc, dd);
									//if (not_equal_list(z){
									if (true){
										if ((aa + bb + cc + dd) == target){
											nje[result_cursor] = Result(z);
											
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
		}
	}
	return (nje);
}

fun main (){
	var nums: Array<Int> = arrayOf(1,0,-1,0,-2,2);
	var len_nums: Int = nums.size;
	var target: Int = 0;
	
	var sample_size: Int = (factorial(len_nums) / (factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
	
	var h: Array<Result> = sum_of_four(nums, target, sample_size);
	
	println("This is the handy work of Kotlin");
	
	for (i in 0 until len_nums){
		h[i].print_values();
	}
}
