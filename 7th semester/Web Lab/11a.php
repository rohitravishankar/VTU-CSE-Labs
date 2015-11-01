<?php
$con = mysql_connect("localhost","root","root123");
if (!$con)
{
die('Could not connect: ' . mysql_error());
}
mysql_select_db("Emp", $con);
$sql="INSERT INTO Emp.Contacts VALUES('$_POST[name]','$_POST[add1]','$_POST[add2]','$_POST[email]')";
if (!mysql_query($sql,$con))
{
die('Error: ' . mysql_error());
}
echo "1 Record Added";
mysql_close($con);

?>
