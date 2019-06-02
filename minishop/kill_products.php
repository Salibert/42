<?php
session_start();

  if (!isset($_GET['nom']))
    header('location: aff_panier.php');
  $nom = htmlspecialchars(trim($_GET['nom']));
  foreach ($_SESSION['panier'] as $key => $value)
  {
    if ($value['nom'] == $nom)
    {

      if ($value['quantite'] > 1)
      {
        $value['quantite'] -= 1;
        $_SESSION['panier'][$key] = $value;
      }
      else
      {
        array_splice($_SESSION['panier'], $key, 1);
      }
    }
  }
  header('location: aff_panier.php');
?>
