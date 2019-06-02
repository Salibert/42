<?php
  session_start();
  if ($_SESSION['loggued_on_user'] == "")
    header('location: index.php');
  if ($_GET['oldpw'] && $_GET['newpw'] && ($_GET['oldpw'] != $_GET['newpw']))
  {
    if ((file_exists('private/users')) && ($str = file_get_contents('private/users')))
    {
      $match = 0;
      $login =  $_SESSION['loggued_on_user'];
      $passwd =  $_GET['oldpw'];
      $passwd_n = $_GET['newpw'];
      $tab = unserialize($str);
      foreach ($tab as $key => $value)
      {
          if ($value['login'] == $login)
          {
            $match = 1;
            if ($value['passwd'] == hash('whirlpool', $passwd))
            {
              $value['passwd'] = hash('whirlpool', $passwd_n);
              $tab[$key] = $value;
              file_put_contents('private/users', serialize($tab));
              header('location: index.php');
              $_SESSION['flash'] = "Sucess";
              return;
            }
            else
            {
              $_SESSION['alert'] = "Fail";
              return;
            }
          }
      }
      if (!$match)
      {
        $_SESSION['alert'] = "Fail";
        return;
      }
    }
  }
  else
    header('location: settings.php');
?>
