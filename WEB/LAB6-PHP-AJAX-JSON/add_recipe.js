function addRecipe(event) {
    event.preventDefault();

    var author = $('#author').val();
    var name = $('#name').val();
    var type = $('#type').val();
    var ingredients = $('#ingredients').val();
    var instructions = $('#instructions').val();

    var addedRecipe = {
        author: author,
        name: name,
        type: type,
        ingredients: ingredients,
        instructions: instructions
    };

    $.ajax({
        url: 'add_recipe.php',
        method: 'POST',
        data: addedRecipe,
        success: function(response) {
            if (response.success) {
                alert('Recipe added successfully');
                window.location.href = 'main_page.html';
            } else {
                alert('Error adding recipe: ' + response.error);
            }
        },
        error: function(xhr, status, error) {
            console.error('AJAX Error:', xhr.responseText);
        }
    });
}

$(document).ready(function() {
    $('#recipeForm').submit(addRecipe);
});
