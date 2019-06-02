<?php
  if (session_status() === PHP_SESSION_NONE){session_start();}
  require 'class/Autoloader.class.php';
  Autoloader::register();

  if(isset($_GET['id']) && isset($_GET['t'])){
      $id = htmlspecialchars(trim($_GET['id']));
      $db = DataBase::getInstance();
      $sql = "SELECT * FROM `recup_mdp` WHERE `id` = :id";
      if($data = $db->request($sql, ['id' => $id])){
          if($data->token == $_GET['t']){
            if(($_POST['password'] == $_POST['password_check']) && $_POST['submit'] == 'OK'){
              $password = sha1($_POST['password']);
              $sql = "SELECT * FROM `users_data` WHERE `email` = :email";
              $data = $db->request($sql, ['email' => $data->email]);
              $sql = "UPDATE `users_data` SET `password` = :password WHERE `id`= :id";
              $fields = ['id' => $data->id, 'password' => $password];
              $db->request($sql, $fields);
              $sql = "DELETE FROM `recup_mdp` WHERE `email` = :email";
              $db->request($sql, ['email' => $data->email]);
              $_SESSION['flash']['good'] = "password change";
              header('location: index.php');
            }
          } else $_SESSION['flash']['bad'] = "token invalid";
      } else $_SESSION['flash']['bad'] = "id not found";
  } else $_SESSION['flash']['bad'] = "id or token invalid";
?>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Camagru</title>
    <link rel="stylesheet" href="css/master.css">
  </head>
  <body>
    <div class="header">
      <ul>
      <li><a href="index.php"><h1>Camagru</h1></a></li>
    </ul>
    </div>
	<?php Data::get_message();?>
	<div align="center">
		<form action="forget_password.php?id= <?= $id.'&t='.$_GET['t'] ?>" method="post" style="margin:auto">
			<label><h1>mot de passe</h1></label><br>
			<input type="password" placeholder="minimun 5" name="password" required><br>
			<label><h1>Confirmez votre mot de passe</h1></label><br>
			<input type="password" placeholder="password" name="password_check" required><br>
			<button type="submit" name="submit" value="OK">Validation</button>
		</form>
	</div>
<?php include 'inc/footer.php'; ?>
