<?php

include_once "connexion.php";

$connexion = new Connexion();


foreach ($_POST as $key => $value) {
    if ($value !== 0)
        $connexion->ecrire("SET $key $value");
}
