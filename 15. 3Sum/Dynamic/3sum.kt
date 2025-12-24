val number_of_elements: Int = 3;

data class Result ( var values: Array<Int>, var number_of_values: Int, var not_null: Boolean){
	
	constructor (list: Array<Int>): this(list, list.size, true){
	}
	
	constructor (): this(Array(number_of_elements) {0}, number_of_elements, false){
	}
	
	fun set_result(list: Array<Int>){
		
		for (i in 0 until list.size){
			values[i] = list[i];
		}
	}
	
	fun print_result(){
		for (i in 0 until number_of_values){
			print(values[i]);
			if (i < number_of_values - 1){
				print("\t");
			}
		}
		println();
	}
}

fun sum_of_three (list: Array<Int>, target: Int): MutableList<Result> {
	var len_list: Int = list.size;
	
	var out: MutableList<Result> = mutableListOf();
	
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
									out.add(Result(q));
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
	
	var res: MutableList<Result> = sum_of_three(nums, 0);
	
	println("This is the handy work of Kotlin");
	
	for (i in 0 until res.size){
		res[i].print_result();
	}
}
