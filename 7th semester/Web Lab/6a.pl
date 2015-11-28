#!/usr/bin/perl
# Write a Perl program to accept the User Name and display a greeting message
# randomly chosen from a list of 4 greeting messages.
use CGI':standard';

print "content-type:text/html\n\n";

$input=param("username");

@msgs=("Good morning","Welcome","How are you doing?","Hello!");
$i=int rand scalar @msgs;

print "Hi, $input.<br>Message:",  $msgs [$i];
