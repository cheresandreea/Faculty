<?php

$user = 'root';
$password = 'root';
$db = 'food';
$host = 'localhost';
$port = 3306;

$link = new mysqli($host, $user, $password, $db, $port);

if ($link->connect_error) {
    die("Connection failed: " . $link->connect_error);
}
