<?php
  session_start();
  if ($_SESSION['panier'])
  {
    $_SESSION['panier'] = "";
  }
  header('location: aff_panier.php');
?>
