<?php
$combinations = array(
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
	);
	
function letterCombinations ($digits){
	$out = [];
	$digits = strval($digits);
	
	for ($d = 0; $d < strlen($digits); $d++){
		global $combinations;
		$keyLetters = $combinations[(int)$digits[$d]];
		
		if (count($out) == 0){
			for ($l = 0; $l < strlen($keyLetters); $l++){
				array_push($out, $keyLetters[$l]);
			}
		} else {
			$holder = [];
			for ($l = 0; $l < strlen($keyLetters); $l++){
				$letter = $keyLetters[$l];
				foreach ($out as $outWords){
					array_push($holder, ($outWords . $letter));
				}
			}
			
			$out = $holder;
		}
	}
	
	Sort($out);
	
	return ($out);
}

$digits = "23";
$c = letterCombinations($digits);

foreach ($c as $a){
	echo ($a . "\n");
}
?>
