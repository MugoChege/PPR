class find_the_index_of_the_first_occurence_in_a_string{
	public static boolean CASE_SENSITIVE = false;
	
	public static boolean compare_string (String text1, String text2){
		boolean out = false;
		int len_text1 = text1.length();
		int len_text2 = text2.length();
		
		if ((len_text1 == 0) && (len_text2 == 0)){
			out = true;
			return (out);
		}
		
		if (len_text1 != len_text2){
			return (out);
		}
		
		String text1_c = text1;
		String text2_c = text2;
		
		if (CASE_SENSITIVE){
			text1_c = text1.toUpperCase();
			text2_c = text2.toUpperCase();
		}
		
		for (int i = 0; i < len_text1; i++){
			if (i == 0){
				out = (text1_c.charAt(i) == text2_c.charAt(i));
			} else {
				out = out && (text1_c.charAt(i) == text2_c.charAt(i));
			}
		}
		
		return (out);
	}
	
	public static int first_occurence (String needle, String haystack){
		int len_needle = needle.length();
		int len_haystack = haystack.length();
		int nje = -1;
		
		if (len_needle > len_haystack){
			nje = -1;
		} else if (len_needle == len_haystack){
			nje = (compare_string(needle, haystack)) ? 0 : -1;
		} else {
			int len_searchable = len_haystack - len_needle + 1;
			
			for (int i = 0; i < len_searchable; i++){
				String substring = haystack.substring(i, i + len_needle);
				
				if (compare_string(needle, substring)){
					nje = i;
					break;
				}
			}
		}
		
		return (nje);
	}
	
	public static void main (String[] args){
		String haystack = "leetcode";
		String needle = "ode";
		
		System.out.println("This is the handy work of Java.\n\n\n");
		System.out.println(first_occurence(needle, haystack));
		System.out.println("\n\n\n");
	}
}
