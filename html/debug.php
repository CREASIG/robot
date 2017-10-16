<?php

include_once "connexion.php";

$connexion = new Connexion();
$connexion->initialise();

echo $connexion->lire("GET DEBUG");



