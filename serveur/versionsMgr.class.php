<?php

define('KEY_MD5',0);
define('KEY_VERSIONTXT',1);
define('KEY_BUILD',2);


class versionsMgr
{
	var $versions_array = array();
	var $current_version_build = 0;
	function loadFromDb()
	{
		$retour = mysql_query('SELECT build,versionTxt,is_current,md5 FROM updater_versions');
		while($data = mysql_fetch_array($retour))
		{
			$this->add($data['md5'],$data['versionTxt'],$data['build']);
			if($data['is_current'] == 1)
				$this->current_version_build = $data['build'];
		}
	}

	function addToDb($md5,$versionTxt,$build,$is_current)
	{
		if($is_current == 1)
			mysql_query('UPDATE updater_maj SET is_current=0');

		$md5 = mysql_real_escape_string($md5);
		$txt = mysql_real_escape_string($versionTxt);
		mysql_query('INSERT INTO updater_maj SET build="'.$build.'", is_current="'.$is_current.'", 
			versionTxt="'.$versionTxt.'", md5="'.$md5.'"') or die(mysql_error());

	}

	function add($md5,$versiontxt,$build)
	{
		$this->versions_array[] = array($md5,$versiontxt,$build);
	}

	function getVersionFromKeyId($key2,$value)
	{
		foreach($this->versions_array as $key)
		{
			if($this->versions_array[$key][$key2] == $value)
			{
				return $this->versions_array[$key];
			}
		}
		return false;
	}

	function getVersionFromMd5($md5)
	{
		return $this->getVersionFromKeyId(KEY_MD5,$md5);
	}

	function getVersionFromVersionText($value)
	{
		return $this->getVersionFromKeyId(KEY_VERSIONTXT,$value);
	}

	function getVersionFromBuild($value)
	{
		return $this->getVersionFromKeyId(KEY_BUILD,$value);
	}
}

?>
