class zigzag_conversion {
	public static String[] zigzag (String text, int rows){
		String[] out = new String[rows];
		
		for (int i = 0; i < rows; i++){
			out[i] = "";
		}
		
		int len_text = text.length();
		boolean straight = true;
		int text_cursor = 0;
		
		while (text_cursor < len_text){
			if (straight) {
				for (int row_cursor = 0; row_cursor < rows; row_cursor++){
					if (text_cursor < len_text){
						out[row_cursor] += text.charAt(text_cursor);
						text_cursor++;
					} else {
						break;
					}
				}
				straight = false;
			} else {
				for (int term = 0; term < (rows - 2); term++){
					for (int row_cursor = 0; row_cursor < rows; row_cursor++){
						if (text_cursor < len_text){
							if (row_cursor == (rows - 2 - term)){
								out[row_cursor] += text.charAt(text_cursor);
								text_cursor++;
							} else {
								out[row_cursor] += ' ';
							}
						} else {
							break;
						}
					}
				}
				straight = true;
			}
		}
		return (out);
	}
	
	public static void main (String[] args){
		String text = "PAYPALISHIRING";
		int rows = 4;
		
		String[] line = zigzag(text, rows);
		
		System.out.println("This is the handy work of Java\n\n\n");
		
		for (int i = 0; i < line.length; i++){
			System.out.println(line[i]);
		}
		
		System.out.println("\n\n\n");
	}
}
