<?php
  session_start();
  if ($_SESSION['loggued_on_user'] != 'Admin')
  {
    header('location: ../index.php');
    $_SESSION['flash'] = "Casse toi";
  }
  if($_GET['login'])
  {
    if ($str = file_get_contents('../private/users'))
    {
      $login = $_GET['login'];
      $tab = unserialize($str);
      foreach ($tab as $key => $value)
      {
          if ($value['login'] == $login && ($login != "Admin"))
          {
              array_splice($tab, $key, 1);
              file_put_contents('../private/users', serialize($tab));
              $_SESSION['flash'] = "Sucess";
          }
        }
      }
      header('location: admin.php');
  }
?>
