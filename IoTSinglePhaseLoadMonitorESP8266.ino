<?php
// Database connection parameters
$servername = "localhost";
$username = "pgcresearch_gaja";
$password = "Gaja@123";
$database = "pgcresearch_newiot";

// Create a connection to the database
$conn = new mysqli($servername, $username, $password, $database);

// Check the connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Get date and time variables
 //date_default_timezone_set('Asia/Kolkata');
//$dt = date("Y-m-d h:i:s a"); // Use "h" for 12-hour format and "a" for AM/PM

// Check if data was sent via POST
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Retrieve data from the ESP32
    $Voltage1post= $_POST["Voltage1"]; 
    $Current1post= $_POST["Current1"];
    $Power1post= $_POST["Power1"];
    $Frequency1post= $_POST["Frequency1"];
    $PowerFactor1post= $_POST["PowerFactor1"];
    $Energy1post= $_POST["Energy1"];

    $Voltage2post= $_POST["Voltage2"]; 
    $Current2post= $_POST["Current2"];
    $Power2post= $_POST["Power2"];
    $Frequency2post= $_POST["Frequency2"];
    $PowerFactor2post= $_POST["PowerFactor2"];
    $Energy2post= $_POST["Energy2"];

    $Voltage3post= $_POST["Voltage3"]; 
    $Current3post= $_POST["Current3"];
    $Power3post= $_POST["Power3"];
    $Frequency3post= $_POST["Frequency3"];
    $PowerFactor3post= $_POST["PowerFactor3"];
    $Energy3post= $_POST["Energy3"];

    $Voltage4post= $_POST["Voltage4"]; 
    $Current4post= $_POST["Current4"];
    $Power4post= $_POST["Power4"];
    $Frequency4post= $_POST["Frequency4"];
    $PowerFactor4post= $_POST["PowerFactor4"];
    $Energy4post= $_POST["Energy4"];

    $Voltage5post= $_POST["Voltage5"]; 
    $Current5post= $_POST["Current5"];
    $Power5post= $_POST["Power5"];
    $Frequency5post= $_POST["Frequency5"];
    $PowerFactor5post= $_POST["PowerFactor5"];
    $Energy5post= $_POST["Energy5"];

// Insert data into the database
$sql = "INSERT INTO RegaIllamHall2 (Voltage1,Current1,Power1,Frequency1,PowerFactor1,Energy1,Voltage2,Current2,Power2,Frequency2,PowerFactor2,Energy2,Voltage3,Current3,Power3,Frequency3,PowerFactor3,Energy3,Voltage4,Current4,Power4,Frequency4,PowerFactor4,Energy4,Voltage5,Current5,Power5,Frequency5,PowerFactor5,Energy5) VALUES ('$Voltage1post', '$Current1post', '$Power1post', '$Frequency1post', '$PowerFactor1post', '$Energy1post','$Voltage2post', '$Current2post', '$Power2post', '$Frequency2post', '$PowerFactor2post', '$Energy2post','$Voltage3post', '$Current3post', '$Power3post', '$Frequency3post', '$PowerFactor3post', '$Energy3post','$Voltage4post', '$Current4post', '$Power4post', '$Frequency4post', '$PowerFactor4post', '$Energy4post','$Voltage5post', '$Current5post', '$Power5post', '$Frequency5post', '$PowerFactor5post', '$Energy5post')";

    if ($conn->query($sql) === TRUE) {
        echo "Data inserted successfully";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}

// Close the database connection
$conn->close();
?>
