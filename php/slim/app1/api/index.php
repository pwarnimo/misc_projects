<?php
require "vendor/autoload.php";

$c = new \Slim\Container();

$c["notFoundHandler"] = function ($c) {
	return function ($request, $response) use ($c) {
		return $c["response"]
			->withStatus(404)
			->withHeader("Content-Type", "text/json")
			->write(json_encode(
				array(
					"error" => "NOT-FOUND"
				)
			));
	};
};

$app = new \Slim\App($c);

//$app->get("/servers/getid/:query", "getServerIDByName");
$app->get("/servers", "getServers");

$app->run();

function getServers() {
	$sql = "SELECT * FROM tblServer";

	try {
		$db = getConnection();
		$stmt = $db->query($sql);
		$servers = $stmt->fetchAll(PDO::FETCH_OBJ);
		$db = null;
		return json_encode(
			array(
				"data" => $servers
			)
		);
	}
	catch(PDOException $e) {
		return json_encode(
			array(
				"error" => array(
					"type" => "dbfail",
					"mesg" => $e->getMessage()
				)
			)
		);
	}
}

function getServerIDByName($query) {
	$sql = "SELECT idServer FROM tblServer WHERE dtHostname = :query";

	print_r($query);

	/*try {
		$db = getConnection();
		$stmt = $db->prepare($sql);
		$stmt->bindParam("name", $name);
		$stmt->execute();
		$serverid = $stmt->fetchObject();
		$db = null;

		return json_encode($serverid);
	}
	catch(PDOException $e) {
		return json_encode(
			array(
				"error" => array(
					"type" => "dbfail",
					"mesg" => $e->getMessage()
				)
			)
		);
	}*/
}

function getConnection() {
	$dbhost = "127.0.0.1";
	$dbuser = "srvmonusr";
	$dbpass = "q1w2e3!";
	$dbname = "srvmon";

	$dbh = new PDO("mysql:host=" . $dbhost . ";dbname=" . $dbname, $dbuser, $dbpass);
	$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	return $dbh;
}
