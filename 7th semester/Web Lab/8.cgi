#!/usr/bin/perl

# Question 8. Write a Perl program to insert name and age information entered by
# the user into a table created using MySQL and
# to display the current contents of this table.

use CGI':standard';
print "content-type:text/html\n\n";
use DBI;

$dbh = DBI->connect("DBI:mysql:student_info","root","root123");
$name=param("name");
$age=param("age");
$sql="insert into user values ('$name','$age')";
$sth=$dbh->prepare("$sql");
$sth->execute;
$sql = "select * from user";
$sth = $dbh->prepare($sql);
$sth->execute;

print "<table border size=1>
<tr>
<th>Name</th>
<th>Age</th>
</tr>";

while(($name,$age)=$sth->fetchrow())
{
print "<tr>
<td>$name</td>
<td>$age</td>
</tr>";
}
$sth->finish();
$dbh->disconnect();
print"</table> </html>";
