<?php
header('Content-Type: application/json');

$servername = "localhost";
$username = "pgcresearch_gaja";
$password = "Gaja@123";
$database = "pgcresearch_newiot";

$hall = $_GET['hall'];
$load = $_GET['load'];

// Connect to the database
$conn = new mysqli($servername, $username, $password, $database);

if ($conn->connect_error) {
    die(json_encode(['error' => 'Connection failed: ' . $conn->connect_error]));
}

// Determine table based on hall
//$table = ($hall == 'RegaIllamHall1') ? 'RegaIllamHall1' : 'RegaIllamHall2';
if($hall == 'RegaIllamHall1')
$table = 'RegaIllamHall1';
if($hall == 'RegaIllamHall2')
$table = 'RegaIllamHall2';
if($hall == 'RegaIllam')
$table = 'RegaIllam';

// Column names
$columns = [
    'Voltage' => 'Voltage' . $load,
    'Current' => 'Current' . $load,
    'Power' => 'Power' . $load,
    'Frequency' => 'Frequency' . $load,
    'PowerFactor' => 'PowerFactor' . $load,
    'Energy' => 'Energy' . $load
];

// Updated SQL queries
$sqlchart = "
    SELECT Date_Time, {$columns['Voltage']}, {$columns['Current']}, {$columns['Power']}, {$columns['Frequency']}, {$columns['PowerFactor']}, {$columns['Energy']}
    FROM (
        SELECT Date_Time, {$columns['Voltage']}, {$columns['Current']}, {$columns['Power']}, {$columns['Frequency']}, {$columns['PowerFactor']}, {$columns['Energy']}
        FROM $table
        ORDER BY S_No DESC
        LIMIT 100
    ) Var1
    ORDER BY Date_Time ASC
";

$sqltable = "
    SELECT Date_Time, {$columns['Voltage']}, {$columns['Current']}, {$columns['Power']}, {$columns['Frequency']}, {$columns['PowerFactor']}, {$columns['Energy']}
    FROM $table
    ORDER BY S_No DESC
    LIMIT 10
";

$result1 = $conn->query($sqlchart);
$result2 = $conn->query($sqltable);

if (!$result1 || !$result2) {
    die(json_encode(['error' => 'SQL error: ' . $conn->error]));
}

$datachart = [
    'timestamps' => [],
    'voltages' => [],
    'currents' => [],
    'powers' => [],
    'frequencies' => [],
    'powerFactors' => [],
    'energies' => []
];

$datatable = [
    'timestamps' => [],
    'voltages' => [],
    'currents' => [],
    'powers' => [],
    'frequencies' => [],
    'powerFactors' => [],
    'energies' => []
];

while ($row = $result1->fetch_assoc()) {
    $datachart['timestamps'][] = $row['Date_Time'];
    $datachart['voltages'][] = $row[$columns['Voltage']];
    $datachart['currents'][] = $row[$columns['Current']];
    $datachart['powers'][] = $row[$columns['Power']];
    $datachart['frequencies'][] = $row[$columns['Frequency']];
    $datachart['powerFactors'][] = $row[$columns['PowerFactor']];
    $datachart['energies'][] = $row[$columns['Energy']];
}

while ($row = $result2->fetch_assoc()) {
    $datatable['timestamps'][] = $row['Date_Time'];
    $datatable['voltages'][] = $row[$columns['Voltage']];
    $datatable['currents'][] = $row[$columns['Current']];
    $datatable['powers'][] = $row[$columns['Power']];
    $datatable['frequencies'][] = $row[$columns['Frequency']];
    $datatable['powerFactors'][] = $row[$columns['PowerFactor']];
    $datatable['energies'][] = $row[$columns['Energy']];
}

$conn->close();

// Return both datasets
echo json_encode([
    'chart' => $datachart,
    'table' => $datatable
]);
?>
