<?php
mysql_connect('127.0.0.1','user','');
mysql_select_db('db');

include('updateMgr.class.php');
include('versionsMgr.class.php');

define('ADMIN_PASS','mdp');
?>
