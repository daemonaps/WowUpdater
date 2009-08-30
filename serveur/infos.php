<?php
include('init.php');
/*
md5 situé dans l'user agent (nom du navigateur normalement ...)
*/
$md5Client = $_SERVER['HTTP_USER_AGENT'];

//Chargement ...
$listeVersions = new versionsMgr;
$listeVersions->loadFromDb();

$listeMaj = new updateMgr;
$listeMaj->loadFromDb();

//Obtenir le build du client
$buildClient = 0;
$version = $listeVersions->getVersionFromMd($md5Client);
if(!$version) //Erreur
	die('Erreur, version non prise en charge');
$buildClient = $version[KEY_BUILD];

//Build du serveur
$serveurBuild = 8086;

//Meilleur possible mise a jour
$urlUpdate = listeMaj->getNextUpdateFrom($buildClient,$serveurBuild);
if($urlUpdate == '')
	die('Impossible de trouver une mise à jour pour votre version du jeu');


echo '<a href="'.$urlUpdate.'">'.$urlUpdate.'</a>';
?>
