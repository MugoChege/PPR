import java.util.Arrays;

class find_first_and_last_position_of_element_in_sorted_array
{
	public static int [] first_and_last (int element, int[] list){
		boolean find_first = true;
		int len_list = list.length;
		int [] out = {-1, -1};
		
		Arrays.sort(list);
		
		for (int i = 0; i < len_list; i++){
			if (list[i] == element){
				if (find_first){
					out[0] = i;
					out[1] = i;
					find_first = false;
				} else {
					out[1] = i;
				}
			}
		}
		return (out);
	}
	
	public static void main (String [] args){
		int [] nums = {5,7,7,8,8,10,2};
		int target = 8;
		
		int [] positions = first_and_last (target, nums);
		
		System.out.print("This is the handy work of Java\n\n\n[");
		System.out.print(positions[0]);
		System.out.print(", ");
		System.out.print(positions[1]);
		System.out.println("]\n\n");
	}
}
