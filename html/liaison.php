
<?php

$message = "GET avance";
echo "Message To server :".$message."<br>";
// create socket
$socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("Could not create socket<br>");
// connect to server
$result = socket_connect($socket, $host, $port) or die("Could not connect to server<br>");  
// send string to server
socket_write($socket, $message, strlen($message)) or die("Could not send data to server<br>");
// get server response
$result = socket_read ($socket, 1024) or die("Could not read server response<br>");
echo "Reply From Server  :".$result;
// close socket
socket_close($socket);


?>


