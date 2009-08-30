<?php

define('KEY_URL',0);
define('KEY_FROM',1);
define('KEY_TO',2);

class updateMgr
{
	var $update_liste = array();
	var $currentBuild;

	function setCurrent($currentBuild)
	{
		$this->currentBuild = $currentBuild;
	}

	function add($dlUrl,$fromBuild,$toBuild)
	{
		$this->update_liste[] = array($dlUrl,$from,$to);
	}

	function getNextUpdateFrom($fromBuild,$maxBuild)
	{
		//1 : Lister toutes les MaJ pour cette version
		$workingMaj = array();
		foreach($this->update_liste as $key)
		{
			if($this->update_liste[$key][KEY_FROM] == $fromBuild)
				$workingMaj[] = $this->update_liste[$key];
		}

		//2 : trouver la plus directe
		$bestToBuild = 0; //Build de destination le plus haut
		$bestUpdateUrl = "";
		foreach($workingMaj as $key)
		{
			if($bestToBuild < $workingMaj[KEY_TO] //Cette MaJ est mieux
				AND $workingMaj[KEY_TO] <= $maxBuild)  //ET convient au serveur
			{
				$bestToBuild = $workingMaj[KEY_TO];
				$bestUpdateUrl = $workingMaj[KEY_URL];
			}
		}

		//Enfin :)
		return $bestUpdateUrl;
	}
}
