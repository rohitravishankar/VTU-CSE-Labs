#! /usr/bin/perl

use CGI ":standard";
print header;
print start_html("6b");
open(FILE,"<count.txt");
$c = <FILE>;
close(FILE);
$c++;
open(FILE,">count.txt");
print FILE $c;
print "No. of visits : $c";
close(FILE);
print end_html;
