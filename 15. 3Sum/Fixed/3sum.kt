var result_number: Int = 0;
val number_of_elements: Int = 3;

data class Result ( var values: Array<Int>, var number_of_values: Int, var not_null: Boolean){
	/*
	var values: Array<Int>
	var number_of_values: Int
	var not_null: Boolean
	
	
	constructor (list: Array<Int>, nov: Int, nn: Boolean){
		this.values = list;
		this.number_of_values = nov;
		this.not_null = true;
	}
	*/
	
	constructor (list: Array<Int>): this(list, list.size, true){
		
	}
	
	constructor (): this(Array(number_of_elements) {0}, number_of_elements, false){
		//this(Array(number_of_elements) {0}, number_of_elements, false);
		/*
		values = Array(number_of_elements){0};
		number_of_values = number_of_elements;
		not_null = false;
		*/
	}
	
	fun set_result(list: Array<Int>){
		
		for (i in 0 until list.size){
			values[i] = list[i];
		}
	}
	
	fun print_result(){
		println("This is the handy work of Kotlin");
		for (i in 0 until number_of_values){
			print(values[i]);
			if (i < number_of_values - 1){
				print("\t");
			}
		}
		println();
	}
}

fun factorial(number: Int): Int{
	var out: Int = 1;
	
	for (i in number downTo 1){
		out *= i;
	}
	
	return (out);
}

fun sum_of_three (list: Array<Int>, target: Int, sample_space: Int): Array<Result> {
	var result_pointer: Int = 0;
	var len_list: Int = list.size;
	
	//val o: Result = Result;
	
	//var out: Array<Array<Int>> = Array(20){ Array(3) {0}};
	var out: Array<Result> = Array(sample_space) {Result()};
	
	for (a in 0 until len_list){
		for (b in 0 until len_list){
			if (b > a){
				for (c in 0 until len_list){
					if (c > b){
						if ((a != b) && (a != c) && (b != c)){
							var aa = list[a];
							var bb = list[b];
							var cc = list[c];
							
							if ((aa != bb) && (aa != cc) && (bb != cc)){
								if ((aa + bb + cc) == target){
									var q: Array<Int> = arrayOf(aa, bb, cc);
									out[result_pointer] = Result(q);
									result_pointer += 1;
									
									result_number = result_pointer;
								}
							}
						}
					}
				}
			}
		}
	}
	
	return out;
}

fun main (){
	var nums: Array<Int> = arrayOf(-1,0,1,2,-1,-4);
	
	val len_nums: Int = nums.size;
	
	val sample_space: Int = (factorial(len_nums)/(factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
	
	println(sample_space);
	
	var h: Array<Result> = sum_of_three(nums, 0, sample_space);
	
	for (i in 0 until result_number){
		h[i].print_result();
	}
}
