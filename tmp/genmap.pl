#!/usr/bin/env perl
use warnings;
use strict;

my $height = shift or die "Usage: $0 HEIGHT\n";
my $generatorName = shift;
$generatorName //= "random";

sub random {
    my ($x, $y) = (@_);
    return int(rand(10));
}

sub interpolate {
    my ($a0, $a1, $w) = (@_);

    return ($a1 - $a0) * $w + $a0;
	#return ($a1 - $a0) * (($w * ($w * 6.0 - 15.0) + 10.0) * $w * $w * $w) + $a0;
}

sub randomGradient {
    my ($ix, $iy) = (@_);

    my $r = 2920.0 * sin($ix * 21942.0 + $iy * 171324.0)
        * cos($ix * 23157.0 + $iy * 217832.0 + 9758.0);

    return (cos($r), sin($r));
}

sub dotGridGradient {
    # Get gradient from integer coordinates
    my ($ix, $iy, $x, $y) = (@_);
    my ($grx, $gry) = randomGradient($ix, $iy);

    my $dx = $x - $ix;
    my $dy = $y - $iy;

    return $dx * $grx + $dy * $gry;
}

my $perlinSeed = rand(4096);
my $perlinZoom = 100;

sub perlin {
    my ($x, $y) = (@_);

	$x = ($x + $perlinSeed) / $perlinZoom;
	$y = ($y + $perlinSeed) / $perlinZoom;

    my $x0 = int($x);
    my $x1 = $x0 + 1;
    my $y0 = int($y);
    my $y1 = $y0 + 1;

    # Determine interpolation weights
    my $sx = $x - $x1;
    my $sy = $y - $y1;

    my ($n0, $n1, $ix0, $ix1, $value);

    $n0 = dotGridGradient($x0, $y0, $x, $y);
    $n1 = dotGridGradient($x1, $y0, $x, $y);
    $ix0 = interpolate($n0, $n1, $sx);

    $n0 = dotGridGradient($x0, $y1, $x, $y);
    $n1 = dotGridGradient($x1, $y1, $x, $y);
    $ix1 = interpolate($n0, $n1, $sx);

    return interpolate($ix0, $ix1, $sy);
}


my %generators = (
    "random" => \&random,
    "perlin" => \&perlin,
);

my $generator;

if ($generators{$generatorName}) {
    $generator = $generators{$generatorName};
} else {
    die "No such generator: '$generatorName'!\n";
}

print int($height), "\n.\n";
for my $x ((1..$height)) {
    for my $y ((1..$height)) {
        print abs(int($generator->($x, $y)))
    }
    print "\n";
}
