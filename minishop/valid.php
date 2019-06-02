<?php
    session_start();
    if ($_SESSION['loggued_on_user'] == "")
    {
      $_SESSION['alert'] = "Connectez vous pour valider la commande";
      header('location: aff_panier.php');
      return;
    }
    if ($_SESSION['panier'] && $_SESSION['command'])
    {
      if ($str = file_get_contents('private/command'))
          $tab = unserialize($str);
      $tab[] = ['login' => $_SESSION['loggued_on_user'],
      'date' => date('Y-d-m'), 'command' => $_SESSION['command']];
      file_put_contents('private/command', serialize($tab));
      header('location: index.php');
      $_SESSION['flash'] = "Merci de vos achats";
      unset($_SESSION['command']);
      unset($_SESSION['panier']);
    }
    else
    {
      $_SESSION['alert'] = "Panier invalid, contacter un administrateur";
        return;
    }
?>
