#!/usr/bin/perl -w
#
# Script      : srvmon-admin.pl
# Author(s)   : Pol Warnimont
# Create date : 2015-06-11
# Version     : 0.1
#
# Description : A simple administration tool for SRVMON
#
# Changelog
# ---------
#  2015-06-11 : Created script.
#
# License information
# -------------------
#  Copyright (C) 2015  Pol Warnimont
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Affero General Public License as
#  published by the Free Software Foundation, either version 3 of the
#  License, or (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Affero General Public License for more details.
#
#  You should have received a copy of the GNU Affero General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.

use strict;
use warnings;
use Curses;
use Curses::UI;
use Cwd;
use DBI;

my ($dbuser, $dbpass, $dbname) = ("sqlusr", "q1w2e3!", "srvmon");
my $dbh = DBI->connect("DBI:mysql:database=" . $dbname, $dbuser, $dbpass);

# Create curses main window
my $cui = new Curses::UI(
	-clear_on_exit => 1,
	-color_support => 1,
	-debug => 0
);

# Context menu definition
my @menu = (
	{
		-label => "File",
		-submenu => [
			{ -label => "Quit ^Q", -value => \&dialogExit }
		]
	},
	{
		-label => "View",
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
			{ -label => "Help  ^H", -value => 0 },
			{ -label => "About ^A", -value => 0 }
		]
	}
);

# Add menu to curses window
my $menu = $cui->add(
	"menu",
	"Menubar",
	-fg => "white",
	-bg => "blue",
	-menu => \@menu
);

# Create main content viewport
my $screen = $cui->add(
	"screen",
	"Window",
	-padtop => 1,
	-border => 0,
	-ipad => 0
);

# Create status bar
$screen->add(
	"lblHelp",
	"Label",
	-y => -1,
	-width => -1,
	-reverse => 1,
	-paddingspaces => 1,
	-fg => "blue",
	-bg => "white",
	-text => " F10 = Menu   F11 = Help   F12 = Quit"
);

# Exit dialog
sub dialogExit() {
	my $return = $cui->dialog(
		-title => "Attention!",
		-buttons => ["yes", "no"],
		-message => "Do you really want to close this script?",
		-tbg => "white",
		-tfg => "blue",
		-bg => "black",
		-fg => "white",
		-bbg => "black",
		-bfg => "white"
	);

	exit(0) if $return;
}

# WINDOW DEFS BEGIN

my %w = ();
my %args = (
	-border => 1,
	-titlereverse => 0,
	-padtop => 1,
	-padbottom => 1,
	-ipad => 1
);

# W1 : MAIN MENU

$w{1} = $cui->add(
	1,
	"Window",
	-title => "Main Menu",
	%args
);

$w{1}->add(
	undef,
	"Label",
	-y => 0,
	-text => "Welcome to the SRVMON administration menu.\n\nUse UP/DOWN to move."
);

$w{1}->add(
	undef,
	"Buttonbox",
	-y => 5,
	-vertical => 1,
	-buttons => [
		{
			-label => " 1. Monitored Servers  "
		},
		{
			-label => " 2. Available Services "
		},
		{
			-label => " 3. User Management    "
		},
		{
			-label => " 4. SRVMON Settings    "
		},
		{
			-label => " 5. Exit Script        ",
			-onpress => \&dialogExit
		}
	]
);

# W2 : SERVERS OVERVIEW

$w{2} = $cui->add(
	2,
	"Window",
	-title => "Servers Overview",
	%args
);

$w{2}->add();

# WINDOW DEFS END

$w{1}->focus;

$cui->set_binding(\&dialogExit, KEY_F(12), "\cQ", "\cC");
$cui->set_binding(sub {
	shift()->getobj("menu")->focus;
}, KEY_F(10), "\cX");

$cui->mainloop;
