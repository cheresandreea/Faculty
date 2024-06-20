<?php
include 'config.php';

// Get column and filter value from request parameters
$filterValue = isset($_GET['filterValue']) ? $_GET['filterValue'] : '';
$column = isset($_GET['column']) ? $_GET['column'] : '';

error_log($_GET['filterValue']);
error_log($_GET['column']);

if (isset($_GET['column'])) {
    error_log($_GET['column']);
}

if ($column && $filterValue) {
    $searchTerm = '%' . $filterValue . '%';
    $stmt = $link->prepare("SELECT recipes.recipe_id, recipes.name, recipes.author, recipe_types.type_name, recipes.ingredients, recipes.instructions
                            FROM recipes
                            JOIN recipe_types ON recipes.type = recipe_types.type
                            WHERE recipes.$column LIKE ?");
    $stmt->bind_param("s", $searchTerm);
} else {
    $stmt = $link->prepare("SELECT recipes.recipe_id, recipes.name, recipes.author, recipe_types.type_name, recipes.ingredients, recipes.instructions
                            FROM recipes
                            JOIN recipe_types ON recipes.type = recipe_types.type");
    error_log("Message to log");
}

$stmt->execute();
$result = $stmt->get_result();
$recipes = $result->fetch_all(MYSQLI_ASSOC);

echo json_encode($recipes);

$stmt->close();
$link->close();
?>
