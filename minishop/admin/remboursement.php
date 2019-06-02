<?php
  session_start();
  if ($_SESSION['loggued_on_user'] != 'Admin')
  {
    header('location: ../index.php');
    $_SESSION['alert'] = "Casse toi";
  }
  if ($_GET['login'] && $_GET['date'])
  {
    $login = htmlspecialchars(trim($_GET['login']));
    $date = htmlspecialchars(trim($_GET['date']));
    if ($str = file_get_contents('../private/command'))
    {
      $tab = unserialize($str);
      foreach ($tab as $key => $value)
      {
          if ($value['login'] == $login)
          {
            if ($value['date'] == $date)
            {
              array_splice($tab, $key, 1);
              file_put_contents('../private/command', serialize($tab));
              $_SESSION['flash'] = "Sucess";              
              header('location: admin.php');
            }
          }
        }
      }
  }
?>
