<?php
function isPalindrome($sub){
	$lenSub = strlen($sub);
	$mirror = ($lenSub / 2) - (($lenSub / 2) % 1);
	$out = false;
	
	for ($a = 0; $a < $mirror; $a++){
		if ($a == 0){
			$out = ($sub[$a] == $sub[$lenSub - 1 - $a]);
		} else {
			$out = $out && ($sub[$a] == $sub[$lenSub - 1 - $a]);
		}
	}
	
	return ($out);
}

function longestSubString ($text){
	$lenText = strlen($text);
	$longestText = "";
	
	for ($a = 0; $a < $lenText; $a++){
		for ($b = 1; $b < $lenText; $b++){
			$subString = substr($text, $a, ($b + 1));
			
			if (isPalindrome($subString)){
				if (strlen($longestText) < strlen($subString)){
					$longestText = $subString;
				}
			}
		}
	}
	
	return ($longestText);
}

$word = "babad";

echo (longestSubString($word));
echo ("\n\n\n\n");
?>
