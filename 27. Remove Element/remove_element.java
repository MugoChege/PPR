//using System;

class remove_element{
	public static int remove_by_shifting (int element, int [] list){
		int count = 0;
		int len_list = list.length;
		
		for (int i = (len_list - 1); i >= 0; i--){
			if (list[i] == element){
				count ++;
				int holder = list[i];
				
				for (int j = i; j < (len_list - 1); j++){
					list[j] = list[j + 1];
				}
				
				list[len_list - 1] = holder;
			}
		}
		
		return (count);
		
	}
	
	public static void main (String [] args){
		int [] nums = {0,1,2,2,3,0,4,2};
		int len_nums = nums.length;
		int vals = 2;
		
		int rem = remove_by_shifting(vals, nums);
		
		System.out.println("This is the handy work of Java\n\n");
		System.out.println(rem);
		System.out.println("\n\n\n");
		
		System.out.print("[");
		for (int i = 0; i < len_nums; i++){
			System.out.print(nums[i]);
			
			if (i == (len_nums - 1)){
				System.out.println("]");
			} else {
				System.out.print(", ");
			}
		}
		
		
		System.out.print("\n\n\n[");
		for (int i = 0; i < (len_nums - rem); i++){
			System.out.print(nums[i]);
			
			if (i == ((len_nums - rem) - 1)){
				System.out.println("]");
			} else {
				System.out.print(", ");
			}
		}
		System.out.println("\n\n\n");
	}
}
