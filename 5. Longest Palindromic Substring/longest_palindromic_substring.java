class longest_palindromic_substring{
	public static boolean is_palindrome (String sub){
		int len_sub = sub.length();
		int mir = len_sub / 2;
		boolean out = false;
		
		for (int i = 0; i < mir; i++){
			if (i == 0){
				out = (sub.charAt(i) == sub.charAt(len_sub - 1 - i));
			} else {
				out = out && (sub.charAt(i) == sub.charAt(len_sub - 1 - i));
			}
		}
		
		return (out);
	}
	
	public static String longest_substring (String text){
		int len_text = text.length();
		String longest_text = "";
		
		for (int i = 0; i < len_text; i++){
			for (int j = (len_text - 1 - i); j >= 0; j--){
				String substring = text.substring(i, (i + j + 1));
				
				if (is_palindrome(substring)){
					if (longest_text.length() < substring.length()){
						longest_text = substring;
						break;
					}
				}
			}
		}
		
		return (longest_text);
	}
	
	public static void main (String[] args){
		String word = "babob";
		System.out.println("This is the handy work of Java.\n\n\n");
		System.out.println(longest_substring(word));
		System.out.println("\n\n\n");
	}
}
