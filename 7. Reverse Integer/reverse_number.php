<?php
function reverse_number($number, $base = 10){
	$negative = ($number < 0);
	
	$number = ($number < 0) ? ($number * -1) : ($number * 1);
	
	$nh = $number;
	$out = 0;
	$i = 1;
	
	while ($nh > 0){
		$out *= $i;
		$mod = $nh % $base;
		$out += $mod;
		$nh -= $mod;
		$nh /= $base;
		$i = 10;
	}
	
	if ($negative){
		$out *= -1;
	}
	
	return ($out);
}

echo(reverse_number(-234));
echo("\n\n\n");
?>
