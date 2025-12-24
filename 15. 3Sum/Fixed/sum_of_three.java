public class sum_of_three{
	public static int result_number = 0;
	public static int number_of_elements = 3;
	
	public static class result {
		int [] values = new int[number_of_elements];
		public boolean isNull = false;
		
		public result (){
			isNull = true;
		}
		
		public void set_result (int [] a){
			for (int i = 0; i < a.length; i++){
				values[i] = a[i];
			}
		}

		public void print(){
			for (int i = 0; i < values.length; i++){
				System.out.print(values[i]);
				System.out.print("\t");
			}
			System.out.println();
		}
	}
	
	public static int factorial(int number){
		int out = 1;
		
		for (int i = number; i > 0; i--){
			out *= i;
		}
		
		return (out);
	}

	public static result [] sum_of_three(int [] array, int target, int combination){
		int len_array = array.length;
		result [] out = new result [combination];
		int result_pointer = 0;
		
		for (int a = 0; a < len_array; a++){
			for (int b = a; b < len_array; b++){
				if (b > a){
					for (int c = b; c < len_array; c++){
						if (c > b){
							if ((a != b) && (b != c) && (a != c)){
								int aa = array[a];
								int bb = array[b];
								int cc = array[c];
								
								if ((aa != bb) && (bb != cc) && (aa != cc)){
									if ((aa + bb + cc) == target){
										//int [] z = [a, b, c]; //fills with the indices of the array that are valid
										int [] y = {aa, bb, cc};
										result z = new result();
										z.set_result(y);
										out [result_pointer] = z;
										result_pointer++;
										result_number = result_pointer;
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
	
	public static void main(String [] args){
		int nums[] = {-1,0,1,2,-1,-4};
		
		int len_nums = nums.length;
		
		int sample_space = (factorial(len_nums) / (factorial(len_nums - number_of_elements) * factorial(number_of_elements)));
		
		result [] h = sum_of_three(nums, 0, sample_space);
		
		for (int i = 0; i < result_number; i++){
			h[i].print();
		}
	}
}
