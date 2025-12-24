<?php
function power ($significand, $exponent){
	$out = 1;
	
	if ($exponent > 0){
		for ($i = 0; $i < $exponent; $i++){
			$out *= $significand;
		}
	} else if ($exponent < 0){
		$exponent *= -1;
		for ($i = 0; $i < $exponent; $i++){
			$out /= $significand;
		}
	} else if ($exponent == 0){
		$out = 1;
	}
	
	return $out;
}

$significand = 2;
$exponent = 0;

echo (power($significand, $exponent));
echo ("\n\n\n");
?>
