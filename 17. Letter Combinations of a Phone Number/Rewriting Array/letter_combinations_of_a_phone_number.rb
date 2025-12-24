$combinations = {
	0=> " ",
	1=> "",
	2=> "abc",
	3=> "def",
	4=> "ghi",
	5=> "jkl",
	6=> "mno",
	7=> "pqrs",
	8=> "tuv",
	9=> "wxyz"
	}
	
def letter_combinations (digits)
	out = []
	digits = String(digits)
	
	for dig in 0...digits.length
	#digits.each do |d|
		d = dig
		key_letters = $combinations[Integer(digits[d])]
		
		if ((out == []) and (out.length == 0))
			for i in 0...key_letters.length
			#key_letters.each do |letter|
				letter = key_letters[i]
			
				out << letter
			end
		else
			holder = []
			for i in 0...key_letters.length
			#key_letters.each do |letter|
				letter = key_letters[i]
				#for out_words in out
				out.each do |out_words|
					holder << (out_words + letter)
				end
			end
			
			out = holder
		end
	end
	
	out.sort()
	
	return out
end

digits = "234"

puts (letter_combinations(digits));
