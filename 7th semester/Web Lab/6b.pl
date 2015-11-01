#!/usr/bin/perl
# Write a Perl program to keep track of the number of visitors visiting the web page
# and to display this count of visitors, with proper headings.

use CGI':standard';

print "content-type:text/html \n\n";
# Requires a file 'data.txt' to pre-exist with the content '0'

open FILE, "data.txt";
$count = <FILE>;

#print "Value of Visited: $count <br />";
close(FILE);
$count++;
#print "After! Value of Count: $count\n";

open Handler, ">data.txt";
print Handler $count ;
close Handler;

#print "No of visits: $count2";
print " <b>This page has been viewed $count times <br /></b>";

