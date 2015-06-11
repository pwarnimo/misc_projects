#!/usr/bin/perl -w

use strict;
use Curses::UI;

my $cui = new Curses::UI(
	-clear_on_exit => 1,
	-debug => 0
);

my $mmiFile = [
	{-label => "Quit program", -value => \&exitScript}
];

my $mmiEdit = [
	{-label => "Refresh", -value => 0},
	{-label => "Settings", -value => 0}
];

my $mmMain = [
	{-label => "File", -submenu => $mmiFile},
	{-label => "Edit", -submenu => $mmiEdit}
];

$cui->add("menu", "Menubar", -menu => $mmMain);

$cui->set_binding(
	sub {
		exit
	},
	"\cQ"
);

$cui->set_binding(
	sub {
		shift()->root->focus("menu")
	},
	"\cX"
);

sub exitScript() {
	my $return = $cui->dialog(
		-title => "Warning",
		-buttons => ["yes", "no"],
		-messgae => "Do you really want to quit?"
	);

	exit(0) if $return;
}

my $w0 = $cui->add(
	"w0", "Window",
	-border => 1,
	-y => -1,
	-height => 3
);

$w0->add(
	"explain", "Label",
	-text => "CTRL+X: menu  CTRL+Q: quit"
);

my $screen = $cui->add(
	"screen", "Window",
	-padtop => 1,
	-border => 0,
	-ipad => 0
);

$screen->add(
	"explain" => "Label",
	-text => "This is a test."
);

$cui->mainloop;
