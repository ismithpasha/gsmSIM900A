<?php
$server     ="localhost";
$username   ="root";
$password   ="";
$db         ="iotdb";

$conn = mysqli_connect($server, $username, $password, $db);
mysqli_query($conn,"SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'");

if(!$conn)
{
    die("connection failed: " . mysqli_connect_error());
}
?>