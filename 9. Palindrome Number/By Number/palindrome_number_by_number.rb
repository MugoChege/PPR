$negative_as_i_squared = true

def reverse_number(number, base = 10)
	nh = number
	out = 0
	i = 1
	
	while (nh > 0)
		out *= i
		mod = nh % base
		out += mod
		nh -= mod
		nh /= base
		i = 10
	end
	
	return (out)
end

def palindrome_checker(number)
	out = nil
	negative = number < 0
	
	number = (number < 0) ? (number * -1) : (number * 1)
	
	reversed_number = reverse_number(number)
	
	
	
	if ($negative_as_i_squared)
		out = (number == reversed_number)
	else
		if (negative)
			out = ((number * -1) == reversed_number)
		else
			out = (number == reversed_number)
		end
	end
	
	return out
end

puts(palindrome_checker(23232))
