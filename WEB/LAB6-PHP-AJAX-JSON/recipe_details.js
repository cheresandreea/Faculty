$(document).ready(function() {
    function getRecipeId() {
        const params = new URLSearchParams(window.location.search);
        return params.get('id');
    }

    function fetchRecipeDetails() {
        const recipeId = getRecipeId();
        console.log('Recipe ID:', recipeId);
        if (recipeId) {
            $.ajax({
                url: 'recipe_details.php',
                method: 'GET',
                data: { id: recipeId },
                dataType: 'json',
                success: function(response) {
                    console.log('Response Data:', response);
                    if (response.error) {
                        $('#recipeDetails').html('<p>' + response.error + '</p>');
                    } else {
                        displayRecipe(response.recipe);
                    }
                },
                error: function(xhr, status, error) {
                    console.error('AJAX Error:', xhr.responseText);
                }
            });
        } else {
            $('#recipeDetails').html('<p>Recipe ID is missing</p>');
        }
    }

    function displayRecipe(recipe) {
        if (!recipe) {
            $('#recipeDetails').html('<p>No recipe details available</p>');
            return;
        }
        var recipeDiv = $('<div class="recipe"></div>');
        recipeDiv.append('<h2>' + recipe.name + '</h2>');
        recipeDiv.append('<p>Author: ' + recipe.author + '</p>');
        recipeDiv.append('<p>Type: ' + recipe.type_name + '</p>');
        recipeDiv.append('<p>Ingredients: ' + recipe.ingredients + '</p>');
        recipeDiv.append('<p>Instructions: ' + recipe.instructions + '</p>');

        var deleteButton = $('<button>Delete Recipe</button>');
        deleteButton.click(function() {
            console.log('Deleting from click recipe with ID:', recipe.recipe_id);
            deleteRecipe(recipe.recipe_id);
        });

        var editButton = $('<button>Edit Recipe</button>');
        editButton.click(function() {
            window.location.href = 'edit_recipe.html?id=' + recipe.recipe_id;
        });

        recipeDiv.append(deleteButton);
        recipeDiv.append(editButton);

        $('#recipeDetails').append(recipeDiv);
    }

    function deleteRecipe(recipeId) {
        if (confirm('Are you sure you want to delete this recipe?')) {
            console.log('Deleting recipe with ID:', recipeId);
            $.ajax({
                url: 'delete_recipe.php',
                method: 'POST',
                data: { id: recipeId },
                success: function(data) {
                    console.log('Raw Response:', data);
                    try {
                        if (data.success) {
                            alert('Recipe deleted successfully!');
                            window.location.href = 'main_page.html';
                        } else {
                            alert('Error deleting recipe: ' + response.error);
                        }
                    } catch (e) {
                        console.error('JSON Parsing Error:', e);
                        alert('Unexpected server response. Please try again.');
                    }
                },
                error: function(xhr, status, error) {
                    console.error('AJAX Error:', xhr.responseText);
                }
            });
        }
    }
    fetchRecipeDetails();
});
