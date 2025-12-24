<?php
$combinations= [" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];

function wordFromOdo($relevantDigits, $digitsOdo){
	$out = "";
	global $combinations;
	for ($i = 0; $i < strlen($relevantDigits); $i++){
		$out .= $combinations[(int)$relevantDigits[$i]][$digitsOdo[$i]];
	}
	
	return ($out);
}

function wordFill($relevantDigits, $digitsOdo, $depth, $maxDepth, &$sampleSpace){
	global $combinations;
	$letterOptions = $combinations[(int)$relevantDigits[$depth]];
	$lenLetterOptions = strlen($letterOptions);
	
	for ($i = 0; $i < $lenLetterOptions; $i++){
		$digitsOdo[$depth] = $i;
		if ($depth < ($maxDepth - 1)){
			wordFill($relevantDigits, $digitsOdo, ($depth + 1), $maxDepth, $sampleSpace);
		} else {
			//echo (wordFromOdo($relevantDigits, $digitsOdo) . "\n");
			array_push($sampleSpace, wordFromOdo($relevantDigits, $digitsOdo));
		}
	}
}

function getLetterCombinations ($digits){
	global $combinations;
	$out = [];
	
	$lenDigits = strlen($digits);
	$odo = [];
	
	$useableDigits = "";
	
	for ($i = 0; $i < $lenDigits; $i++){
		//echo($combinations[(int)$digits[$i]]. "\n");
		if (strlen($combinations[(int)$digits[$i]]) == 0){
			continue;
		}
		
		$useableDigits .= $digits[$i];
		array_push($odo, 0);
	}
	
	$lenUseableDigits = strlen($useableDigits);
	
	wordFill($useableDigits, $odo, 0, $lenUseableDigits, $out);
	
	return ($out);
}

$digits = "6872";
echo (json_encode(getLetterCombinations($digits)) . "\n\n\n\n");
?>
