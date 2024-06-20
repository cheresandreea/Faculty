<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

ob_start();

include 'config.php';

$response = array();
if (isset($_POST['id'], $_POST['name'], $_POST['author'], $_POST['type'], $_POST['ingredients'], $_POST['instructions'])) {
    $recipe_id = $_POST['id'];
    $name = $_POST['name'];
    $author = $_POST['author'];
    $type = $_POST['type'];
    $ingredients = $_POST['ingredients'];
    $instructions = $_POST['instructions'];

    $stmt = $link->prepare("UPDATE recipes SET name=?, author=?, type=?, ingredients=?, instructions=? WHERE recipe_id=?");
    $stmt->bind_param("sssssi", $name, $author, $type, $ingredients, $instructions, $recipe_id);

    if ($stmt->execute()) {
        if ($stmt->affected_rows > 0) {
            $response['success'] = true;
        } else {
            $response['success'] = false;
            $response['error'] = "Recipe not found or no changes were made.";
        }
    } else {
        $response['success'] = false;
        $response['error'] = "Error executing query: " . $stmt->error;
    }

    $stmt->close();
} else {
    $response['success'] = false;
    $response['error'] = "Missing fields in the request.";
}

$link->close();

ob_end_clean();

header('Content-Type: application/json');
echo json_encode($response);

