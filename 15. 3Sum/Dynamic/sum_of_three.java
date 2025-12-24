import java.util.ArrayList;

public class sum_of_three{
	public static int number_of_elements = 3;
	
	public static class Result {
		int [] values = new int[number_of_elements];
		public boolean isNull = false;
		
		public Result (){
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
	
	public static ArrayList<Result> sum_of_three(int [] array, int target){
		int len_array = array.length;
		ArrayList<Result> out = new ArrayList<Result> ();
		
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
										Result z = new Result();
										z.set_result(y);
										//out [result_pointer] = z;
										out.add(z);
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
		int target = 0;
		
		ArrayList<Result> res = sum_of_three(nums, target);
		
		System.out.println("This is the handy work of Java");
		
		for (int i = 0; i < res.size(); i++){
			res.get(i).print();
		}
	}
}
