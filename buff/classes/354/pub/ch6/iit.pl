#!/usr/bin/perl

sub f() {
    print;
    print "\n";
}

my @a=(1,"hi",2);

map(f,@a);
