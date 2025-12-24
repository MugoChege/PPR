import java.util.Arrays;

class remove_duplicates_from_sorted_array{
	public static int duplicates_shifting_remove(int [] list){
		int counter = 0;
		int len_list = list.length;
		
		Arrays.sort(list);
		
		for (int i = (len_list - 1); i >= 0; i--){
			int element = list[i];
			boolean unique = true;
			
			for (int j = 0; j < i; j++){
				if (element == list[j]){
					unique = false;
					break;
				}
			}
			
			if (unique == false){
				counter ++;
				int holder = list[i];
				
				for (int j = i; j < (len_list - 1); j++){
					list[j] = list[j + 1];
				}
				
				list[len_list - 1] = holder;
			}
		}
		
		return (counter);
	}
	
	public static void main (String [] args){
		int [] nums = {0,0,1,1,1,2,2,3,3,4};
		int len_nums = nums.length;
		int rem = duplicates_shifting_remove(nums);
		
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
