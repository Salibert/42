<?php
function ajouterArticle($nom)
{
  if (!$_SESSION['panier'])
    $_SESSION['panier'][] = ['nom' => $nom, 'quantite' => 1];
  else if ($_SESSION['panier'])
  {
    $match = 0;
    foreach ($_SESSION['panier'] as $key => $value)
    {
      if ($value['nom'] == $nom)
      {
        $match = 1;
        $_SESSION['panier'][$key]['quantite'] += 1;
      }
    }
    if ($match == 0)
      $_SESSION['panier'][] = ['nom' => $nom, 'quantite' => 1];
  }
   else
   {
     header('location: index.php');
     echo "Un problème est survenu veuillez contacter l'administrateur du site.";
   }
}
?>
