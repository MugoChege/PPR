def reverse_number(number, base = 10)
	negative = (number < 0)
	
	number = (number < 0) ? (number * -1) : (number * 1)
	
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
	
	if (negative)
		out *= -1
	end
	
	return (out)
end

puts(reverse_number(-34567))
