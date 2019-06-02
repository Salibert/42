<?php
session_start();
if ($_SESSION['loggued_on_user'] != 'Admin')
{
  header('location: ../index.php');
  $_SESSION['flash'] = "Casse toi d'ici";
}
if ($_POST['submit'] == "OK" && $_POST['login'] && $_POST['passwd'])
{
  $exit = 0;
  $login = htmlspecialchars(trim($_POST['login']));
  $passwd = htmlspecialchars(trim($_POST['passwd']));
  if ($str = file_get_contents('../private/users'))
  {
    $tab = unserialize($str);
    foreach ($tab as $key => $value)
    {
      if ($value['login'] == $login)
      {
        $exit = 1;
        $tab[$key]['passwd'] = hash('whirlpool', $passwd);
        file_put_contents('../private/users', serialize($tab));
        header('location: admin.php');
        $_SESSION['flash'] = "Sucess";
      }
    }
  }
  if ($exit == 0)
  {
    $tab[] = ['login' => $login, 'passwd' => hash('whirlpool', $passwd)];
    file_put_contents('../private/users', serialize($tab));
    header('location: admin.php');
  }
}
header('location: admin.php');
?>
