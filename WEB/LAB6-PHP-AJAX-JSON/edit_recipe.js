function fetchTypes() {
    $.ajax({
        url: 'fetch_types.php',
        method: 'GET',
        dataType: 'html',
        success: function(data) {
            $('#type').html(data);
        },
        error: function(xhr, status, error) {
            console.error('Error fetching types:', error);
        }
    });
}

function editRecipe(event) {
    event.preventDefault();

    var urlParams = new URLSearchParams(window.location.search);
    var recipeId = urlParams.get('id');

    var name = $('#name').val();
    var author = $('#author').val();
    var type = $('#type').val();
    var ingredients = $('#ingredients').val();
    var instructions = $('#instructions').val();

    var updatedRecipe = {
        id: recipeId,
        name: name,
        author: author,
        type: type,
        ingredients: ingredients,
        instructions: instructions
    };

    $.ajax({
        url: 'edit_recipe.php',
        method: 'POST',
        data: updatedRecipe,
        success: function(response) {
            console.log('Raw Response:', response);
            if (response.success) {
                alert('Recipe updated successfully!');
                window.location.href = 'main_page.html';
            } else {
                alert('Error updating recipe: ' + response.error);
            }
        },
        error: function(xhr, status, error) {
            console.error('AJAX Error:', xhr.responseText);
        }
    });
}

$(document).ready(function() {
    fetchTypes();
    $('#editRecipeForm').submit(editRecipe);
});
