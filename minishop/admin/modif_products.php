<?php
session_start();
  if ($_SESSION['loggued_on_user'] != 'Admin')
  {
    header('location: ../index.php');
    $_SESSION['flash'] = "Casse toi fdp";
  }
  if ($_POST['nom'] && $_POST['prix'] && $_POST['image'] && $_POST['description']
  && $_POST['categorie'])
  {
    $nom = htmlspecialchars(trim($_POST['nom']));
    $image = htmlspecialchars(trim($_POST['image']));
    $description = htmlspecialchars(trim($_POST['description']));
    $categorie = htmlspecialchars(trim($_POST['categorie']));
    $prix = htmlspecialchars(trim($_POST['prix']));
    $str = file_get_contents('../private/products');
    $tab = unserialize($str);
    foreach ($tab as $key => $value)
    {
      if ($value['nom'] == $nom)
      {
        $value['description'] = $description;
        $value['prix'] = $prix;
        $value['categorie'] = $categorie;
        $value['image'] = $image;
        $tab[$key] = $value;
        file_put_contents('../private/products', serialize($tab));
        header('location: admin.php');
        return;
      }
    }
      $tab[] = ['nom' => $nom,
      'image' => $image,
      'description' => $description,
      'prix' => $prix,
      'categorie' => $categorie];
      file_put_contents('../private/products', serialize($tab));
  }
  header('location: admin.php');
?>
