<?php
session_start();
  if ($_SESSION['loggued_on_user'] != 'Admin')
  {
    header('location: ../index.php');
    $_SESSION['flash'] = "Casse toi fdp";
  }
  if($_GET['nom'])
  {
    if ($str = file_get_contents('../private/products'))
    {
      $nom = $_GET['nom'];
      $tab = unserialize($str);
      foreach ($tab as $key => $value)
      {
          if ($value['nom'] == $nom)
          {
              array_splice($tab, $key, 1);
              file_put_contents('../private/products', serialize($tab));
              header('location: admin.php');
              echo "OK\n";
          }
        }
      }
  }
?>
