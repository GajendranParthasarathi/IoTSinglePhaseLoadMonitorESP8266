<?php
// Database connection parameters
$servername = "localhost";
$username = "pgcresearch_gaja";
$password = "Gaja@123";
$database = "pgcresearch_newiot";

// Create connection
$conn = new mysqli($servername, $username, $password, $database);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

// Function to sanitize data
function sanitize($conn, $data) {
  return mysqli_real_escape_string($conn, htmlspecialchars($data));
}

// Fetch POST data
$Voltage1 = sanitize($conn, $_POST['Voltage2']);
$Current1 = sanitize($conn, $_POST['Current2']);
$Power1 = sanitize($conn, $_POST['Power2']);
$Frequency1 = sanitize($conn, $_POST['Frequency2']);
$PowerFactor1 = sanitize($conn, $_POST['PowerFactor2']);
$Energy1 = sanitize($conn, $_POST['Energy2']);

$Voltage2 = sanitize($conn, $_POST['Voltage3']);
$Current2 = sanitize($conn, $_POST['Current3']);
$Power2 = sanitize($conn, $_POST['Power3']);
$Frequency2 = sanitize($conn, $_POST['Frequency3']);
$PowerFactor2 = sanitize($conn, $_POST['PowerFactor3']);
$Energy2 = sanitize($conn, $_POST['Energy3']);

$Voltage3 = sanitize($conn, $_POST['Voltage1']);
$Current3 = sanitize($conn, $_POST['Current1']);
$Power3 = sanitize($conn, $_POST['Power1']);
$Frequency3 = sanitize($conn, $_POST['Frequency1']);
$PowerFactor3 = sanitize($conn, $_POST['PowerFactor1']);
$Energy3 = sanitize($conn, $_POST['Energy1']);

$Voltage4 = sanitize($conn, $_POST['Voltage4']);
$Current4 = sanitize($conn, $_POST['Current4']);
$Power4 = sanitize($conn, $_POST['Power4']);
$Frequency4 = sanitize($conn, $_POST['Frequency4']);
$PowerFactor4 = sanitize($conn, $_POST['PowerFactor4']);
$Energy4 = sanitize($conn, $_POST['Energy4']);

$Voltage5 = sanitize($conn, $_POST['Voltage5']);
$Current5 = sanitize($conn, $_POST['Current5']);
$Power5 = sanitize($conn, $_POST['Power5']);
$Frequency5 = sanitize($conn, $_POST['Frequency5']);
$PowerFactor5 = sanitize($conn, $_POST['PowerFactor5']);
$Energy5 = sanitize($conn, $_POST['Energy5']);

// SQL query to insert data into table
$sql = "INSERT INTO RegaIllamHall1 (Voltage1, Current1, Power1, Frequency1, PowerFactor1, Energy1,
                                   Voltage2, Current2, Power2, Frequency2, PowerFactor2, Energy2,
                                   Voltage3, Current3, Power3, Frequency3, PowerFactor3, Energy3,
                                   Voltage4, Current4, Power4, Frequency4, PowerFactor4, Energy4,
                                   Voltage5, Current5, Power5, Frequency5, PowerFactor5, Energy5)
        VALUES ('$Voltage1', '$Current1', '$Power1', '$Frequency1', '$PowerFactor1', '$Energy1',
                '$Voltage2', '$Current2', '$Power2', '$Frequency2', '$PowerFactor2', '$Energy2',
                '$Voltage3', '$Current3', '$Power3', '$Frequency3', '$PowerFactor3', '$Energy3',
                '$Voltage4', '$Current4', '$Power4', '$Frequency4', '$PowerFactor4', '$Energy4',
                '$Voltage5', '$Current5', '$Power5', '$Frequency5', '$PowerFactor5', '$Energy5')";

// Execute query
if ($conn->query($sql) === TRUE) {
  echo "New record inserted successfully";
} else {
  echo "Error: " . $sql . "<br>" . $conn->error;
}

// Close connection
$conn->close();
?>
