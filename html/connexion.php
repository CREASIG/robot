<?php

class Connexion {

    private $host = "127.0.0.1";
    private $port = 8080;
    private $socket;

    public function initialise() {
        // create socket
        $this->socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("Could not create socket<br>");
// connect to server
        $result = socket_connect($this->socket, $this->host, $this->port) or die("Could not connect to robot server<br>");
// send string to server
//        socket_write($this->socket, $message, strlen($message)) or die("Could not send data to server<br>");
// get server response
//        $result = socket_read($this->socket, 1024) or die("Could not read server response<br>");
//        echo "Reply From Server  :" . $result;
// close socket
    }

    public function fermer() {
        socket_close($socket);
    }

    public function lire($message) {
        $this->initialise();
        socket_write($this->socket, $message, strlen($message)) or die("Impossible de demander des informations au robot");
// get server response
        $message = "";
        do {
            $message1 = socket_read($this->socket, 1024) ;
            $message.=$message1;
        } while ($message1 != "");
        $this->fermer();
        return $message;
    }

    public function ecrire($message) {
        $this->initialise();
        socket_write($this->socket, $message, strlen($message)) or die("Impossible d'envoyer des paramètres au robot");
        $this->fermer();
    }

}
