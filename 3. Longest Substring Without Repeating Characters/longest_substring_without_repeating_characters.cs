using System;

namespace longest_substring_without
{
	class longest_substring_without
	{
		static String longest_substring (String text)
		{
			int len_text = text.Length;
			String longest_text = "";
			
			for (int a = 0; a < len_text; a++)
			{
				for (int b = 0; b < (len_text - a); b++)
				{
					if ((a + b) >= len_text)
					{
						break;
					} else {
						String substring = text.Substring(a, b);
						char letter = text[a + b];
						//Console.WriteLine(substring + "\t\t\t" + letter);
						
						if (substring.Contains(letter))
						{
							if (longest_text.Length < substring.Length)
							{
								longest_text = substring;
							}
							break;
						}
					}
				}
			}
			return (longest_text);
		}
		
		static void Main (String [] args)
		{
			String f = "pwwkew";
			String ret;
			ret = longest_substring(f);
			
			Console.WriteLine(ret);
		}
	}
}
