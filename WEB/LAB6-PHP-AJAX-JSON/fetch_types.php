<?php
include 'config.php';

$sql = "SELECT DISTINCT type_name, type FROM recipe_types";
$result = $link->query($sql);

if ($result->num_rows > 0) {
    while($row = $result->fetch_assoc()) {
        $typeId = $row["type"];
        $typeName = $row["type_name"];
        echo "<option value='$typeId'>$typeName</option>";
    }
} else {
    echo '<option value="">No types available</option>';
}

$link->close();
