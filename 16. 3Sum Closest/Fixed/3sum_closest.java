class closest_sum_of_three{
	static int result_number = 0;
	static int number_of_elements = 3;
	
	public static class Result{
		int [] values = new int[number_of_elements];
		int number_of_values;
		boolean not_null;
		
		public void set_values(int [] list){
			not_null = true;
			number_of_values = list.length;
			
			for (int i = 0; i < number_of_values; i++){
				values[i] = list[i];
			}
		}
		
		public Result(int [] list){
			not_null = true;
			set_values(list);
		}
		
		public Result(){
			empty_values();
		}
		
		public void print_values(){
			System.out.println("This is the handy work of Java");
			int out = 0;
			
			for (int i = 0; i < number_of_elements; i++){
				System.out.print(values[i]);
				out += values[i];
				//System.out.print(values[i]);
				
				if (i < (number_of_elements - 1)){
					System.out.print("\t");
				}
			}
			
			System.out.print("\nThe sum of the values is:\t");
			System.out.println(out);
		}
		
		public void empty_values(){
			not_null = false;
			
			for (int i = 0; i < number_of_values; i++){
				values[i] = 0;
			}
			
			number_of_values = 0;
		}
	}
	
	public static int factorial (int number){
		int out = 1;
		
		for (int i = number; i > 0; i--){
			out *= i;
		}
		
		return (out);
	}
	
	public static int absolute (int number){
		return (number < 0) ? (number * -1) : (number * 1);
	}
	
	public static Result [] sum_of_three_closest (int [] list, int target, int sample_space){
		int result_cursor = 0;
		int closest_difference = 0;
		boolean first_execution = true;
		int len_list = list.length;
		Result [] out = new Result[sample_space];
		
		for (int a = 0; a < len_list; a++){
			for (int b = 0; b < len_list; b++){
				if (b > a){
					for (int c = 0; c < len_list; c++){
						if (c > b){
							if ((a != b) && (a != c) && (b != c)){
								int aa = list[a];
								int bb = list[b];
								int cc = list[c];
								
								//if ((aa != bb) && (aa != cc) && (bb != cc)){
								if (true){
									int difference = absolute(target - (aa + bb + cc));
									
									boolean update_array = false;
									
									if (first_execution){
										closest_difference = difference;
										first_execution = false;
										
										update_array = true;
									} else {
										if (difference < closest_difference){
											closest_difference = difference;
											
											if (result_cursor > 0){
												for (int i = 0; i < result_cursor; i++){
													out[result_cursor].empty_values();
												}
												result_cursor = 0;
											}
											
											update_array = true;
										} else if (difference == closest_difference){
											update_array = true;
										}
									}
									
									if (update_array){
										int [] y = {aa, bb, cc};
										out[result_cursor] = new Result(y);
										result_cursor++;
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
	
	public static void main (String [] args){
		int [] nums = {-1,2,1,-4};
		int len_nums = nums.length;
		int target = 1;
		
		int sample_space = (factorial(len_nums) / (factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
		
		Result [] h = sum_of_three_closest(nums, target, sample_space);
		
		for (int i = 0; i < result_number; i++){
			h[i].print_values();
		}
	}
}
