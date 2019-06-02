<?php
	/*
	* Class form
	* charge les class automatiquement
	*/
	class Autoloader{
		/*
		* crée Autoloader
		*/
		static function register(){
			spl_autoload_register(array(__CLASS__, 'autoload'));
		}
		/*
		* charge la class mise en parametre
		*/
		static function autoload($class_name){
			require 'class/'.$class_name.'.class.php';
		}
	}
?>
