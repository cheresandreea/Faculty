$(document).ready(function() {
    function fetchColumns() {
        $.ajax({
            url: 'get_columns.php',
            method: 'GET',
            dataType: 'json',
            success: function(response) {
                response.forEach(function(column) {
                    $('#column').append('<option value="' + column + '">' + column + '</option>');
                });
            },
            error: function(xhr, status, error) {
                console.error(xhr.responseText);
            }
        });
    }
    fetchColumns();

    function loadTypes() {
        $.ajax({
            url: 'fetch_types.php',
            method: 'GET',
            dataType: 'html',
            success: function(response) {
                $('#filterValue').replaceWith('<select id="filterValue">' + response + '</select>');
            },
            error: function(xhr, status, error) {
                console.error(xhr.responseText);
            }
        });
    }
    function loadRecipes(column, value) {
        const data = {
            column: column,
            filterValue: value
        };
        if (column !== '') {
            data[column] = value;
            if (column === 'type') {
                data.filterValue = $('#filterValue').val();
            } else {
                data.filterValue = value;
            }
        } else {
            data.filterValue = value;
        }

        $.ajax({
            url: 'get_recipes.php',
            method: 'GET',
            data: data,
            dataType: 'json',
            success: function(response) {
                $('#recipes').empty();
                $.each(response, function(index, recipe) {
                    var recipeDiv = $('<div class="recipe"></div>');
                    recipeDiv.append('<h2>' + recipe.name + '</h2>');
                    recipeDiv.append('<p>Author: ' + recipe.author + '</p>');
                    recipeDiv.append('<p>Type: ' + recipe.type_name + '</p>');
                    recipeDiv.append('<p>Ingredients: ' + recipe.ingredients + '</p>');
                    recipeDiv.append('<p>Instructions: ' + recipe.instructions + '</p>');
                    recipeDiv.click(function() {
                        window.location.href = 'recipe_details.html?id=' + recipe.recipe_id;
                    });
                    $('#recipes').append(recipeDiv);
                });
            },
            error: function(xhr, status, error) {
                console.error(xhr.responseText);
            }
        });
    }

    $('#filterButton').click(function() {
        const column = $('#column').val();
        const filterValue = $('#filterValue').val();
        if (column !== '') {
            loadRecipes(column, filterValue);
        } else {
            loadRecipes('', filterValue);
        }
    });
    $('#column').change(function() {
        const selectedColumn = $(this).val();
        if (selectedColumn === 'type') {
            loadTypes();
        } else {
            // Change dropdown back to input field
            $('#filterValue').replaceWith('<input type="text" id="filterValue">');
        }
    });

    console.log($('#column').val());
    console.log("before");
    loadRecipes('', '');
});
