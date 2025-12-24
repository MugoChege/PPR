public class sum_of_4{
	public static int result_number = 0;
	public static int number_of_elements = 4;
	
	public static class Result{
		int [] values = new int [number_of_elements];
		int number_of_values;
		boolean not_null;
		
		public void print_values(){
			for (int i = 0; i < number_of_elements; i++){
				System.out.print(values[i]);
				
				if (i < (number_of_elements - 1)){
					System.out.print("\t");
				}
			}
			System.out.println();
		}
		
		public Result (){
			number_of_values = 0;
			not_null = false;
		}
		
		public Result(int [] list){
			number_of_values = list.length;
			not_null = false;
			
			for (int i = 0; i < list.length; i++){
				values[i] = list[i];
			}
		}
	}
	
	public static boolean not_equal_list (int [] list){
		int len_list = list.length;
		boolean nje = true;
		
		for (int i = 0; i < len_list; i++){
			for (int j = i; j < len_list; j++){
				if (i != j){
					if (list[i] == list[j]){
						nje = false;
					}
				}
			}
		}
		
		return (nje);
	}
	
	public static int factorial (int number){
		int nje = 1;
		
		for (int i = number; i > 0; i--){
			nje *= i;
		}
		
		return (nje);
	}
	
	static Result [] sum_of_four (int [] list, int target, int sample_size){
		int result_cursor = 0;
		int len_list = list.length;
		
		Result [] nje = new Result [sample_size];
		
		for (int a = 0; a < len_list; a++){
			for (int b = 0; b < len_list; b++){
				if (b > a){
					for (int c = 0; c < len_list; c++){
						if (c > b){
							for (int d = 0; d < len_list; d++){
								if (d > c){
									int [] u = {a, b, c, d};
									if (not_equal_list(u)){
										int aa = list[a];
										int bb = list[b];
										int cc = list[c];
										int dd = list[d];
										
										//if (not_equal_list({aa, bb, cc, dd});
										if (true){
											if ((aa + bb + cc + dd) == target){
												int [] z = {aa, bb, cc, dd};
												nje [result_cursor] = new Result(z);
												
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
			}
		}
		
		return (nje);
	}
	
	public static void main (String [] args){
		int [] nums = {1,0,-1,0,-2,2};
		int len_nums = nums.length;
		int target = 0;
		
		int sample_size = (factorial(len_nums) / (factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
		
		Result [] h = sum_of_four(nums, target, sample_size);
		
		System.out.print("This is the handy work of Java\n");
		
		for (int i = 0; i < result_number; i++){
			h[i].print_values();
		}
		
		System.out.println();
	}
}
