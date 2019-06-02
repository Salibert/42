<?php
class DataBase{
	private $_PDOInstance;
	private static $_instance = null;

	/*-------------------------------------------*/
	private function __construct(){
		try {
			$options =
			[
				PDO::MYSQL_ATTR_INIT_COMMAND => "SET NAMES utf8",
				PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
				PDO::ATTR_EMULATE_PREPARES => false
			];
			$this->_PDOInstance = new PDO('mysql:host='.$DB_DSN.";dbname=Camagru",$DB_USER, $DB_PASSWORD, $options);
		} catch(PDOException $e){
			echo "Connection failed: ". $e->getMessage();
		}
	}
	/*-------------------------------------------*/
	/**
	* retourne une instance database
	* @return une instance pour la base de données
	*/
	public static function getInstance(){
		if (is_null(self::$_instance))
			self::$_instance = new DataBase();
		return self::$_instance;
	}
	/*-------------------------------------------*/
	/*
	* Permet de faire une requete SQl
	*/
	public function request($sql, $fields = false, $multiple = false){
		try {
			$statement = $this->_PDOInstance->prepare($sql);
			if($fields)
			{
				foreach($fields as $key => $value)
				{
					if(is_int($value))
						$dataType = PDO::PARAM_INT;
					else if(is_bool($value))
						$dataType = PDO::PARAM_BOOL;
					else if(is_null($value))
						$dataType = PDO::PARAM_NULL;
					else
						$dataType = PDO::PARAM_STR;
					$statement->bindValue(':'.$key, $value, $dataType);
				}
			}
			$statement->execute();
			if ($multiple)
				$result = $statement->fetchAll(PDO::FETCH_OBJ);
			else
				$result = $statement->fetch(PDO::FETCH_OBJ);
			$statement->closeCursor();
			return $result;
		} catch (Exception $e){
			echo $e->getMessage();
		}

	}
	/*-------------------------------------------*/
	public function check_users($login){
		$sql = "SELECT * FROM users_data WHERE login = :login";
		$fields = ['login' => $login];
		$check_users = $this->request($sql, $fields, false);
		return $check_users;
	}

	public function check_email($email){
		$sql = "SELECT * FROM users_data WHERE email = :email";
		$fields = ['email' => $email];
		$check_email = $this->request($sql, $fields, true);
		return $check_email;
	}

	public function check_email_mdp($email){
		$sql = "SELECT * FROM recup_mdp WHERE email = :email";
		$fields = ['email' => $email];
		$check_email = $this->request($sql, $fields, true);
		return $check_email;
	}

	public function send_email($id, $email, $token, $page)
	{
		$subject = 'Account activation - Camagru';
		$header  = "MIME-Version: 1.0\r\n";
		$header .= 'From:"Camagru"<support@twelveforstudy.com>'."\n";
		$header .= 'Content-Type:text/html; charset="UTF-8"'."\n";
		$header .= 'Content-Transfer-Encoding: 8bit';
		$message = '<p align="center"">Welcome '.$login.'
		<a href="http://localhost:8080/camagru/'.$page.'.php?id='.$id.'&t='.$token.'">Validate my account</a></p>';
		mail($email, $subject, $message, $header);
	}
}
