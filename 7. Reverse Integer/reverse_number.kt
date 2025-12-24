fun reverse_number(numb: Int, base: Int = 10): Int{
	var negative: Boolean = (numb < 0);
	
	var number: Int = if (numb < 1) (numb * -1) else (numb * 1);
	
	var nh: Int = number;
	var out: Int = 0;
	var i: Int = 1;
	var mod: Int; 
	
	while (nh > 0){
		out *= i;
		mod = nh % base;
		out += mod;
		nh -= mod;
		nh /= base;
		i = 10;
	}
	
	if (negative){
		out *= -1;
	}
	
	return (out);
}

fun main (){
	println(reverse_number(1357));
}
