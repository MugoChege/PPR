class two_sum {
	public static int [] get_target (int[] nums, int target){
		int len_nums = nums.length;
		int [] out = new int[2];
		for (int i = 0; i < len_nums; i++){
			boolean exit_loop = false;
			
			for (int j = 0; j < len_nums; j++){
				if (i == j){
					continue;
				} else {
					if ((nums[i] + nums[j]) == target){
						out[0] = nums[i];
						out[1] = nums[j];
						exit_loop = true;
						break;
					}
				}
			}
			if (exit_loop){
				break;
			}
		}
		return (out);
	}

	public static void main (String[] args){
		int number_list[] = {1,2,3,4,5,6,7,8,9};
		int target = 16;
		int[] indices = new int [2];
		
		indices = get_target(number_list, target);
		
		System.out.println("[" + indices[0] + "," + indices[1] + "]\n");
	}

}


