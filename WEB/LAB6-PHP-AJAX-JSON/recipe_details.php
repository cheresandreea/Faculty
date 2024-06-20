<?php
include 'config.php';

$recipe = null;
$error = null;

if (isset($_GET['id'])) {
    $recipe_id = $_GET['id'];
    $stmt = $link->prepare("SELECT recipes.recipe_id, recipes.name, recipes.author, recipe_types.type_name, recipes.ingredients, recipes.instructions
                            FROM recipes
                            JOIN recipe_types ON recipes.type = recipe_types.type
                            WHERE recipes.recipe_id = ?");
    $stmt->bind_param("i", $recipe_id);
    $stmt->execute();
    $result = $stmt->get_result();
    if ($result->num_rows > 0) {
        $recipe = $result->fetch_assoc();
    } else {
        $error = "Recipe not found!";
    }

    $stmt->close();
} else {
    $error = "Recipe ID is missing!";
}

$link->close();

header('Content-Type: application/json');
echo json_encode(['recipe' => $recipe, 'error' => $error]);