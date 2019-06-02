<?php
  function auth($login, $passwd)
  {
    if ((file_exists('private/users')) && ($str = file_get_contents('private/users')))
    {
      $tab = unserialize($str);
      foreach ($tab as $value)
      {
          if ($value['login'] == $login)
          {
            if ($value['passwd'] == hash('whirlpool', $passwd))
              return (TRUE);
            else
              return (FALSE);
          }
      }
    }
    return (FALSE);
  }
?>
