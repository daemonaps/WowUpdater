<?php
include('init.php');

//Fonctions VUE
function input($txt,$name,$value='')
{
	echo $txt.'<input type="text" name="'.$name.'" value="'.$value.'" /><br /><br />';
}

function fieldset($legend = '')
{
	echo '<fieldset><legend>'.$legend.'</legend>';
}
function checkbox($txt,$name,$value='1')
{
	echo $txt.'<input type="checkbox" name="'.$name.'" value="'.$value.'" /><br /><br />';
}
function endFieldset()
{
	echo '</fieldset';
}

//Traitement des informations
$log = "";
if(isset($_POST['mdp']))
{
	if($_POST['mdp'] == ADMIN_PASS)//Admin
	{
		//Ajout de MAJ
		if($_POST['maj'])
		{
			$url = $_POST['url'];		
			$from = intval($_POST['maj_from']);	
			$to = intval($_POST['maj_to']);	
			
			$listeMaj = new updateMgr;
			$listeMaj->addToDb($url,$from,$to);
			$log .= 'Mise a jour ajoutee.<br />';
		}
		if($_POST['version'])//Ajouter une version
		{
			$log .= 'Version ajoutee.<br />';
		}
		if($_POST['build'])//Ajouter une version
		{
			$log .= 'Version du serveur changee.<br />';
		}
	}
	else
		$erreur = 'Mauvais mot de passe ADMIN envoyé';
}
else
{
	$erreur = '';
}
?>

<title>Administration</title>
<h1>Administration</h1>
<form action="" method="post">
<?php
if($log != '')
	echo '<h3>Action effectuees:</h3><p>'.$log.'</p>';
echo '<div style="color:red;">'.$erreur.'</div>';

input('PassWord Administrateur','mdp',htmlentities($_POST['mdp']));

fieldset('Ajouter une mise a jour');
	checkbox('Ajouter une mise a jour ?','maj');
	input('URL de téléchargement','maj_url');
	input('MaJ depuis version (build)','maj_from');
	input('MaJ vers version (build)','maj_to');
endfieldset();

fieldset('Ajouter une Version');
	checkbox('Ajouter une version ?','version');
	input('MD5 du fichier WOW.EXE','version_md5');
	input('Build (exemple : 8606)','version_build');
	input('Texte de la version (exemple : 2.4.3)','version_txt');
endfieldset();

fieldset('Version actuelle du serveur');
	checkbox('Changer la version ?','build');
	input('Build','build_current');
endfieldset();
?>
<input type='submit' name="=>" value="=>" />
</form>

<?php


?>
