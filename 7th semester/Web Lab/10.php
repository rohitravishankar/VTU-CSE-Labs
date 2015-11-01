<?php

session_start();

if(isset($_SESSION['views']))
	$_SESSION['views']=$_SESSION['views']+1;
else
	$_SESSION['views']=1;
	echo "This page has been viewed ".$_SESSION['views']." times.";
?>
