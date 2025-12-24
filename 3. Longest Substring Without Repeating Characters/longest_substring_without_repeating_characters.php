<?php

function longestSubstring ($text){
	$lenText = strlen($text);
	$longestText = "";
	
	for ($a = 0; $a < $lenText; $a++){
		for ($b = $a; $b < ($lenText - $a); $b++){
			$subString = substr($text, $a, $b);
			$letter = substr($text, $a + $b, 1);
			//echo ( $subString . "\t\t\t" . $letter. "\n");
			
			if (strpos($subString, $letter) !== false){ //
				if (strlen($longestText) < strlen($subString)){
					$longestText = $subString;
				}
				break;
			}
			
		}
	}
	
	return $longestText;
}

$w = longestSubstring("pwwkew");
print ($w);
print ("\n\n\n");
?>
