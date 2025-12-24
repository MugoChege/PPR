import java.util.ArrayList;

class closest_sum_of_three{
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

	public static int absolute (int number){
		return (number < 0) ? (number * -1) : (number * 1);
	}
	
	public static ArrayList<Result> sum_of_three_closest (int [] list, int target){
		int closest_difference = 0;
		boolean first_execution = true;
		int len_list = list.length;
		ArrayList<Result> out = new ArrayList<Result>();
		
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
											
											out = new ArrayList<Result>();
											
											update_array = true;
										} else if (difference == closest_difference){
											update_array = true;
										}
									}
									
									if (update_array){
										int [] y = {aa, bb, cc};
										out.add(new Result(y));
										//out[result_cursor] = new Result(y);
										//result_cursor++;
										//result_number = result_cursor;
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
		
		//int sample_space = (factorial(len_nums) / (factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
		
		ArrayList<Result> res = sum_of_three_closest(nums, target);
		
		System.out.println("This is the handy work of Java");
		
		for (int i = 0; i < res.size(); i++){
			res.get(i).print_values();
		}
	}
}
