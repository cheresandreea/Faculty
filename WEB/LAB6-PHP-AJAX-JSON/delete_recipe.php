<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

ob_start();

include 'config.php';

$response = array();

if (isset($_POST['id'])) {
    $recipe_id = $_POST['id'];

    $stmt = $link->prepare("DELETE FROM recipes WHERE recipe_id = ?");
    $stmt->bind_param("i", $recipe_id);

    if ($stmt->execute()) {
        if ($stmt->affected_rows > 0) {
            $response['success'] = true;
        } else {
            $response['success'] = false;
            $response['error'] = "Recipe not found!";
        }
    } else {
        $response['success'] = false;
        $response['error'] = "Error executing query: " . $stmt->error;
    }

    $stmt->close();
} else {
    $response['success'] = false;
    $response['error'] = "Recipe ID is missing!";
}
$link->close();

ob_end_clean();

header('Content-Type: application/json');
echo json_encode($response);
