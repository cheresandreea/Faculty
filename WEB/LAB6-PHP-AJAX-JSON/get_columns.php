<?php
include 'config.php';

$sql = "SHOW COLUMNS FROM recipes ";
$result = $link->query($sql);

if ($result->num_rows > 0) {
    $columns = array();

    while ($row = $result->fetch_assoc()) {
        if ($row['Field'] != 'recipe_id') {
            $columns[] = $row['Field'];
        }
    }

    echo json_encode($columns);
} else {
    echo json_encode(array('error' => 'No columns found'));
}

$link->close();