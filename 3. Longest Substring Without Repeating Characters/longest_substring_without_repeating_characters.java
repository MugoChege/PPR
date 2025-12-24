class longest_substring_without_repeating_characters{
	public static boolean strfind (String text, char l){
		boolean out = false;
		int len_text = text.length();
		
		for (int a = 0; a < len_text; a++){
			if (text.charAt(a) == l){
				out = true;
				break;
			}
		}
		return out;
	}
	
	public static String longest_substring (String text){
		int len_text = text.length();
		String longest_text = "";
		
		for (int a = 0; a < len_text; a++){
			for (int b = a; b < (len_text - a); b++){
				if ((a + b) >= len_text){
					break;
				}
				String substring = text.substring(a, a + b);
				char letter = text.charAt(a + b);
				//System.out.println(String.valueOf(a + b) + "\t\t\t" + substring + "\t\t\t" + letter);
				
				//if ((substring.contains(letter + "")){
				if (strfind (substring, letter)){
					if (longest_text.length() < substring.length()){
						longest_text = substring;
					}
					break;
				}
			}
		}
		
		return (longest_text);
	}
	
	public static void main (String [] args){
		String f = "pwwkew";
		String ret;
		ret = longest_substring(f);
		
		System.out.println (ret);
		
		//return 0;
	}
}
