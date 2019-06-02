<?php
  session_start();
  if ($_SESSION['loggued_on_user'] != "")
  {
    $login = $_SESSION['loggued_on_user'];
    $passwd = htmlspecialchars(trim($_GET['passwd']));
    if ($str = file_get_contents('private/users'))
    {
      $tab = unserialize($str);
      foreach ($tab as $key => $value)
      {
          if ($value['login'] == $login)
          {
            if ($value['passwd'] == hash('whirlpool', $passwd))
            {
              array_splice($tab, $key, 1);
              file_put_contents('private/users', serialize($tab));
              header('location: logout.php');
              $_SESSION['flash'] = "Le compte $login a bien etait supprimer";
            }
            else
            {
              header('location: settings.php');
            }
          }
        }
      }
    }
?>
