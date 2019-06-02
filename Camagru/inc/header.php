<!DOCTYPE html>
<?php if (session_status() === PHP_SESSION_NONE){session_start();} ?>
<html>
  <head>
    <meta charset="utf-8">
    <title>Camagru</title>
		<link rel="stylesheet" href="css/master.css">
  </head>
  <body>
  <div width="100%" height="100%">
  <div class="header">
    <ul>
    <li><a href="index.php"><h1>Camagru</h1></a></li>
  <?php if ($_SESSION['auth'] != ""): ?>
    <li><a href="posts.php"></a></li>
    <div style="float:right;margin-left:70%;display:inline-block;">
      <li style=""><a href="posts.php">POST</a></li>
      <li><a href="delog.php">DELOG</a></li>
    </div>
  <?php elseif($_SERVER['REQUEST_URI'] == '/Camagru/creat_account.php'):?>
    <h1 align="center">Welcome future user</h1>
  <?php else: ?>
  <div style="float=right;margin-left:60%;display:inline-block">
    <li>
    <div style="align-content:center">
    <form action="log.php" method="post">
      <label><b>Login</b></label>
      <input type="text" placeholder="Login" name="login" required>
      <label><b>password</b></label>
      <input type="password" placeholder="min 5" name="password" required>
      <input type="submit" name="submit" value="Sign in"><br>
      <a href="send_email_forget_password.php">Forget Password</a>
      <a href="creat_account.php">Sign Up</a>
    </div>
    </form>
    </li>
  </div>
<?php endif; ?>
</ul>
</div>
