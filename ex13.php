<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "employee";
// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}



// sql to create table
$sql = "CREATE TABLE MyGuests (
id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
firstname VARCHAR(30) NOT NULL,
lastname VARCHAR(30) NOT NULL,
email VARCHAR(50),
reg_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
)";

if ($conn->query($sql) === TRUE) {
  echo "Table MyGuests created successfully\n";
} else {
  echo "Error creating table: " . $conn->error;
}


//Insert records in tabel
$sql1 = "INSERT INTO MyGuests (firstname, lastname, email)
VALUES ('Arun', 'Doe', 'john@example.com')";

if ($conn->query($sql1) === TRUE) {
  echo "New record created successfully\n";
} else {
  echo "Error: " . $sql . "<br>" . $conn->error;
}
//Update records in table
$sql2 = "UPDATE MyGuests SET lastname='Raj' WHERE id=2";

if ($conn->query($sql2) === TRUE) {
  echo "Record updated successfully\n";
} else {
  echo "Error updating record: " . $conn->error;
}


// sql to delete a record
$sql3 = "DELETE FROM MyGuests WHERE id=3";

if ($conn->query($sql3) === TRUE) {
  echo "Record deleted successfully";
} else {
  echo "Error deleting record: " . $conn->error;
}


$sql4 = "SELECT id, firstname, lastname FROM MyGuests";
$result = $conn->query($sql4);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "id: " . $row["id"]. " - Name: " . $row["firstname"]. " " . $row["lastname"]. "<br>";
  }
} else {
  echo "0 results\n";
}

$conn->close();
?>