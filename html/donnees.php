<?php

include_once "connexion.php";

$connexion = new Connexion();
$connexion->initialise();

$connexion->ecrire("GET ");

echo $_POST['name'];
