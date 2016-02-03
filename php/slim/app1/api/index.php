<?php
require "db.php";
require "vendor/autoload.php";

$app = new \Slim\Slim();

$app->get("/servers/:name/getid", function ($name) {
	$sql = "SELECT idServer FROM tblServer WHERE dtHostname = :name";

	try {
		$db = getDB();
		$stmt = $db->prepare($sql);
		$stmt->bindParam("name", $name);

		if ($stmt->execute()) {
			$serverid = $stmt->fetchObject();

			if ($serverid != false) {
				echo json_encode(
					array(
						"status" => "OK",
						"data" => $serverid
					)
				);
			}
			else {
				echo json_encode(
					array(
						"status" => "NOT-FOUND"
					)
				);
			}
		}
		else {
			echo json_encode(
				array(
					"status" => "QUERYFAIL"
				)
			);
		}

		$db = null;
	}
	catch(PDOException $e) {
		echo json_encode(
			array(
				"status" => "DBFAIL",
				"mesg" => $e->getMessage()
			)
		);
	}
});

$app->put("/servers/scan", function () {
	$sql = "UPDATE tblServer SET dtEnabled = 0 WHERE dtLastCheckTS < (NOW() - INTERVAL 5 MINUTE)";

	try {
		$db = getDB();
		if ($db->query($sql)) {
			echo json_encode(
				array(
					"status" => "OK"
				)
			);
		}
		else {
			echo json_encode(
				array(
					"status" => "QUERYFAIL"
				)
			);
		}
	}
	catch(PDOException $e) {
		echo json_encode(
			array(
				"status" => "DBFAIL",
				"mesg" => $e->getMessage()
			)
		);
	}
});

$app->put("/servers/:id/enable", function ($id) {
	$sql = "UPDATE tblServer SET dtEnabled = 1 WHERE idServer = :id";

	try {
		$db = getDB();
		$stmt = $db->prepare($sql);
		$stmt->bindParam("id", $id);

		if ($stmt->execute()) {
			echo json_encode(
				array(
					"status" => "OK"
				)
			);
		}
		else {
			echo json_encode(
				array(
					"status" => "QUERYFAIL"
				)
			);
		}

		$db = null;
	}
	catch(PDOException $e) {
		echo json_encode(
			array(
				"status" => "DBFAIL",
				"mesg" => $e->getMessage()
			)
		);
	}
});

$app->get("/servers", function () {
	$sql = "SELECT * FROM tblServer";

	try {
		$db = getDB();
		$stmt = $db->query($sql);
		$servers = $stmt->fetchAll(PDO::FETCH_OBJ);
		$db = null;

		echo json_encode(
			array(
				"status" => "OK",
				"servers" => $servers
			)
		);
	}
	catch(PDOException $e) {
		echo json_encode(
			array(
				"status" => "DBFAIL",
				"mesg" => $e->getMessage()
			)
		);
	}
});

$app->run();
