<?php
include 'config.php';
$response = array();

if (isset($_POST['author'], $_POST['name'], $_POST['type'], $_POST['ingredients'], $_POST['instructions'])) {
    $author = $_POST['author'];
    $name = $_POST['name'];
    $type = $_POST['type'];
    $ingredients = $_POST['ingredients'];
    $instructions = $_POST['instructions'];

    $stmt = $link->prepare("INSERT INTO recipes (author, name, type, ingredients, instructions) VALUES (?, ?, ?, ?, ?)");
    $stmt->bind_param("sssss", $author, $name, $type, $ingredients, $instructions);

    if ($stmt->execute()) {
        $response["success"] = true;
    } else {
        $response["success"] = false;
        $response["error"] = $stmt->error;
    }

    $stmt->close();
} else {
    $response["success"] = false;
    $response["error"] = "Missing fields in the request.";
}

$link->close();

header('Content-Type: application/json');
echo json_encode($response);
