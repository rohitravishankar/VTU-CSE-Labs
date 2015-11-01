#!/usr/bin/perl
# Question 5b. Write a Perl program to accept UNIX command from a HTML form and to display the output of the command executed.


use CGI':standard';

print "content-type:text/html\n\n";

$c=param('cmd'); 

system($c); 

exit(0);
