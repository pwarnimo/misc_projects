<?php
use Phalcon\Loader;
use Phalcon\Mvc\View;
use Phalcon\Mvc\Application;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Url as UrlProvider;
use Phalcon\Db\Adapter\Pdo\Mysql as DbAdapter;

try {
	$loader = new Loader();
	
	$loader->registerDirs(array(
		"../app/controllers/",
		"../app/models/"
	))->register();

	$di = new FactoryDefault();

	$di->set("db", function() {
		return new DbAdapter(array(
			"host" => "127.0.0.1",
			"username" => "sqlusr",
			"password" => "q1w2e3!",
			"dbname" => "mvcphalcon"
		));
	});

	$di->set("view", function() {
		$view = new View();
		$view->setViewsDir("../app/views/");

		return $view;
	});

	$di->set("url", function() {
		$url = new UrlProvider();
		$url->setBaseUri("/phalcon/tut1/");

		return $url;
	});

	$application = new Application($di);

	echo $application->handle()->getContent();
}
catch (\Exception $e) {
	echo "Exception: ", $e->getMessage();
}
