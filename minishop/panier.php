<?php
include_once("ft_panier.php");
session_start();
if ($_POST['submit'] == "Ajouter" && $_POST['data'])
  ajouterArticle($_POST['data']);
  header('location: index.php');
?>
