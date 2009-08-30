CREATE TABLE `launcheraps`.`updater_maj` (
`url` VARCHAR( 255 ) NOT NULL ,
`from` INT( 8 ) NOT NULL COMMENT 'build depuis ...',
`to` INT( 8 ) NOT NULL COMMENT 'build destination',
UNIQUE (
`url`
)
) ENGINE = MYISAM COMMENT = 'Liste de toutes les MAJ de wow';

CREATE TABLE IF NOT EXISTS `updater_versions` (
  `build` int(8) NOT NULL,
  `versionTxt` varchar(20) collate latin1_general_ci NOT NULL COMMENT 'ex : 3.1.3',
  `md5` varchar(255) collate latin1_general_ci NOT NULL COMMENT 'md5 du fichier wow.exe',
  `is_current` int(11) NOT NULL default '0' COMMENT '1 si version actuelle du serveur, sinon 0',
  UNIQUE KEY `build` (`build`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;

