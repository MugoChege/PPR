using System;

namespace zigzag_conversion_ns
{
	class zigzag_conversion_c
	{
		public static String[] zigzag (String text, int rows){
			String[] nje = new String[rows];
			
			int len_text = text.Length;
			bool straight = true;
			int text_cursor = 0;
			
			while (text_cursor < len_text){
				if (straight){
					for (int row_cursor = 0; row_cursor < rows; row_cursor++){
						if (text_cursor < len_text){
							nje[row_cursor] += text[text_cursor];
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
									nje[row_cursor] += text[text_cursor];
									text_cursor++;
								} else {
									nje[row_cursor] += ' ';
								}
							} else {
								break;
							}
						}
					}
					straight = true;
				}
			}
			return (nje);
		}
		
		public static void Main (String[] args) {
			String text = "PAYPALISHIRING";
			int rows = 5;
			
			String[] line = zigzag(text, rows);
			
			Console.WriteLine("This is the handy work of C#\n\n");
			
			for (int i = 0; i < line.Length; i++){
				Console.WriteLine(line[i]);
			}
			
			Console.WriteLine ("\n\n\n");
		}
	}
}
