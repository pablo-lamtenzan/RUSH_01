#!/usr/bin/env perl
use warnings;
use strict;

my $height = shift or die "Usage: $0 HEIGHT\n";

print int($height), "\n.\n";

for((1..$height)) {
    for ((1..$height)) {
        print int(rand(10));
    }
    print "\n";
}