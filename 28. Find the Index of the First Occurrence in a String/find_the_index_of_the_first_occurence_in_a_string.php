<?php
$CASE_SENSITIVE = false;

function compareStrings ($text1, $text2){
	$out = false;
	
	global $CASE_SENSITIVE;
	if ($CASE_SENSITIVE){
		$text1 = strtoupper($text1);
		$text2 = strtoupper($text2);
	}
	
	if ($text1 === "" && $text2 === ""){
		$out = true;
		return ($out);
	}
	
	if (strlen($text1) != strlen($text2)){
		return ($out);
	}
	
	for ($i = 0; $i < strlen($text1); $i++){
		if ($i == 0){
			if ($text1[$i] == $text2[$i]){
				$out = true;
			} else {
				$out = false;
			}
		} else {
			$out = $out && ($text1[$i] == $text2[$i]);
		}
	}
	
	return ($out);
}

function firstOccurence ($needle, $haystack){
	$lenNeedle = strlen($needle);
	$lenHaystack = strlen($haystack);
	$out = -1;
	
	if ($lenNeedle > $lenHaystack){
		$out = -1;
	} else if ($lenNeedle == $lenHaystack){
		$found = compareStrings($needle, $haystack);
		$out = $found ? 0 : -1;
	} else {
		$lenSearchable = $lenHaystack - $lenNeedle + 1;
		for ($i = 0; $i < $lenSearchable; $i++){
			if (compareStrings($needle, substr($haystack, $i, ($i + $lenNeedle)))){ //this is the part of the string
				$out = $i;
				break;
			}
		}
	}
	
	return ($out);
}

echo((firstOccurence("ode", "leetcode")) . "\n\n\n");
?>
