<?php
    require 'class/Autoloader.class.php';
    Autoloader::register();
    if ($_POST['submit'] == 'OK' && isset($_POST['email'])){
        $error = new Data();
        $email = htmlspecialchars(trim($_POST['email']));
        if($error->email($email)){
            $db = DataBase::getInstance();
            if($db->check_email($email)){
              $token = md5(uniqid($email, true));
              if(!$db->check_email_mdp($email)){
                $sql = "INSERT INTO recup_mdp(email, token)
                VALUES (:email, :token)";
                $db->request($sql, ['email' => $email, 'token' =>$token]);
              }else{
                $sql = "UPDATE `recup_mdp` SET `token` = :token WHERE `email` = :email";
                $db->request($sql, ['email' => $email, 'token' =>$token]);
              }
                $sql = "SELECT id FROM recup_mdp WHERE email = :email";
                $id = $db->request($sql, ['email' => $email]);
                $db->send_email($id->id, $email, $token, "forget_password");
                $_SESSION['flash']['good'] = "Check your emails";
				        header('location: index.php');
            }else $_SESSION['flash']['bad'] = "Email no found in the DataBase";
        }else $_SESSION['flash']['bad'] = "Email invalid";
    }else $_SESSION['flash']['bad'] = "invalid fields or invalid URL";
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
    <div align="center">
        <form action="send_email_forget_password.php" method="post">
        <label><h1>email</h1></label><br>
        <input align="center" width="40%" type="email" placeholder="exemple@exemple.exemple" name="email" required><br>
        <button type="submit" name="submit" value="OK">Validation</button>
        </form>
    </div>
  </body>
</html>
