<?php
	if (session_status() === PHP_SESSION_NONE){session_start();}
	require 'class/Autoloader.class.php';
	Autoloader::register();

	if ($_SESSION['auth'] != "")
			header('location: index.php');
	elseif (($_POST['submit'] == "OK") &&
	isset($_POST['password']) && isset($_POST['login']) &&
	($_POST['password_check'] == $_POST['password']) &&
	isset($_POST['email']))
	{
		$login = htmlspecialchars(trim($_POST['login']));
		$password = sha1($_POST['password']);
		$email = htmlspecialchars(trim($_POST['email']));
		$error = new Data();
		if ($error->email($email))
		{
			$db = DataBase::getInstance();
			if(!($db->check_users($login)) && !($db->check_email($email)))
			{
				$token = md5(uniqid($login, true));
				$sql = "INSERT INTO users_data (login, password, email, token)
								VALUES (:login, :password, :email, :token)";
				$fields = [
										'login' => $login,
										'password' => $password,
										'email' => $email,
										'token' => $token
									];
				$db->request($sql, $fields);
				$sql = "SELECT id FROM users_data WHERE login = :login";
				$id = $db->request($sql, ['login' => $login]);
				$db->send_email($id->id, $email, $token, "confirm_users");
				$_SESSION['flash']['good'] = "Creat account, check your emails";
				header('location: index.php');
			}
			else
				$_SESSION['flash']['bad'] = "users or email exists";
		}
	} else {$_SESSION['flash']['bad'] = "fields invalid";}
?>
<?php include 'inc/header.php'; ?>
		<?php Data::get_message();?>
		<div align="center" style="margin: auto;width: 50%;border: 3px solid green;padding:10px;border-radius:10px">
			<form action="creat_account.php" method="post" style="margin:auto">
				<label><b>Nom d'utilisateur</b></label><br>
				<input type="text" placeholder="Login" name="login" required><br>
				<label><b>mot de passe</b></label><br>
				<input type="password" placeholder="minimun 5" name="password" required><br>
				<label><b>Confirmez votre mot de passe</b></label><br>
				<input type="password" placeholder="password" name="password_check" required><br>
				<label><b>email</b></label><br>
				<input type="email" placeholder="exemple@exemple.exemple" name="email" required><br>
				<button type="submit" name="submit" value="OK">Validation</button>
			</form>
		</div>
	<?php include 'inc/footer.php'; ?>
