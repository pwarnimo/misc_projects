<?php
function getDB() {
	$dbhost = "127.0.0.1";
	$dbuser = "srvmonusr";
	$dbpass = "q1w2e3!";
	$dbname = "srvmon";

	$con = new PDO("mysql:host=" . $dbhost . ";dbname=" . $dbname, $dbuser, $dbpass);
	$con->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	return $con;
}
