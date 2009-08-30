<?php

define('KEY_MD5',0);
define('KEY_VERSIONTXT',1);
define('KEY_BUILD',2);


class versionsMgr
{
	var $versions_array = array();

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
