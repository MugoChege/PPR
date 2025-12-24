def power (significand, exponent)
	out = 1.0
	
	if (exponent > 0.0)
		exp = Integer(exponent)
		for i in 0...exp
			out *= significand
		end
	elsif (exponent < 0.0)
		exp = Integer(exponent * -1.0)
		for i in 0...exp
			out /= significand
		end
	elsif (exponent == 0.0)
		out = 1.0
	end
	
	return out
end

significand = 2.0
exponent = -4.0

print (power(significand, exponent))
puts ("\n\n\n\n")
