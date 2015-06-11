#!/usr/bin/perl -w

use strict;
use Curses;
use Curses::UI;
use Cwd;

my @menu = (
	{
		-label => "File",
		-submenu => [
			{ -label => "Refresh ^R", -value => 0 },
			{ -label => "Exit    ^Q", -value => \&showExitDialog }
		]
	},
	{
		-label => "Administration",
		-submenu => [
			{ -label => "Servers  ^S", -value => 0 },
			{ -label => "Services ^E", -value => 0 },
			{ -label => "Users    ^U", -value => 0 },
			{ -label => "Settings ^T", -value => 0 }
		]
	},
	{
		-label => "Help",
		-submenu => [
			{ -label => "About ^A", -value => 0 }
		]
	}
);

my $cui = new Curses::UI(
	-clear_on_exit => 1,
	-color_support => 1
);

my $menu = $cui->add(
	"menu",
	"Menubar",
	-fg => "white",
	-bg => "blue",
	-menu => \@menu
);

my $screen = $cui->add(
	"screen",
	"Window",
	-padtop => 1,
	-border => 1,
	-ipad => 0
);

sub showExitDialog() {
	my $return = $cui->dialog(
		-title => "Are you sure?",
		-buttons => ["yes", "no"],
		-message => "Do you really want to quit?",
		-tbg => "white",
		-tfg => "blue",
		-bg => "black",
		-fg => "white",
		-bbg => "black",
		-bfg => "white"
	);

	exit(0) if $return;
}

$cui->set_binding(\&showExitDialog, "\cQ", "\cC");

$cui->mainloop;
