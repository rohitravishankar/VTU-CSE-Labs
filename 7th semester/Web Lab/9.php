<?php
	$expiry=60*24*60*60+time();
	setcookie("lastvisit",date('G:i-m/d/y'),$expiry);
	if(isset($_COOKIE["lastvisit"]))
	{
		$a=$_COOKIE["lastvisit"];
		print "last visit $a";
	}
	else
	{
		print "cookies are too old";
	}
?>

