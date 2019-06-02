<?php
  session_start();
  include('auth.php');
  if ($_POST['submit'] == "OK" && $_POST['login'] && $_POST['passwd'])
  {
    $_SESSION['loggued_on_user'] = $_POST['login'];
    if (auth($_POST['login'], $_POST['passwd']) && $_POST['login'] == "Admin")
      header('location: admin/admin.php');
    else if (auth($_POST['login'], $_POST['passwd']))
      header('location: index.php');
    else
    {
      header('location: index.php');
      $_SESSION['loggued_on_user'] = "";
      $_SESSION['flash'] = "Identifiant Mauvais";
    }
  }
?>
