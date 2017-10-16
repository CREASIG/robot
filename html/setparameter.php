<?php

include_once "connexion.php";

$connexion = new Connexion();


foreach($_POST as $key=>$value) {
    $connexion->ecrire("SET $key $value");
    
}


