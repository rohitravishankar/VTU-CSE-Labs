<?php
$con = mysql_connect("localhost","root","root123");
if (!$con)
{
die('Could not connect: ' . mysql_error());
}
mysql_select_db("Emp", $con);
$sql="SELECT * FROM Emp.Contacts WHERE name='$_POST[name]'";
$result=mysql_query($sql,$con);
echo "<center><h1>Here is the Data You Requested!...</h1></center>";
echo "<center><table border='1'>
<tr>
<th>Name</th>
<th>Address1</th>
<th>Address2</th>
<th>Email</th>
</tr>";
while($row = mysql_fetch_array($result))
{
echo "<tr><td>" . $row['name'] . "</td>";
echo "<td>" . $row['add1'] . "</td>";
echo "<td>" . $row['add2'] . "</td>";
echo "<td>" . $row['email'] . "</td></tr>";
}
echo "</table></center>";
mysql_close($con);
?>
