<?php

if (session_status() === PHP_SESSION_NONE){session_start();}
require 'class/Autoloader.class.php';
Autoloader::register();

if ($_SESSION['auth'] == "")
{
  $_SESSION['flash']['bad'] = "Permission Denied";
  header('location: index.php');
}
elseif(($_POST['submit'] == "delete") AND (isset($_POST['data'])))
{
  $auth = $_SESSION['auth'];
  $tab = explode('&path=', $_POST['data']);
  $path = $tab[1];
  $login = substr($tab[0], 6);

  if($login == $auth->login)
  {
    $db = DataBase::getInstance();
    $sql = "SELECT `id` FROM `posts` WHERE `login` = :login AND `image` = :image";
    $fields = ['login' => $login, 'image' => $path];
    $id_posts = $db->request($sql, $fields);
    $sql = "DELETE FROM `posts` WHERE `login` = :login AND `image` = :image";
    $fields = ['login' => $login, 'image' => $path];
    $db->request($sql, $fields);
    if ($empty = $db->request("SELECT * FROM `comments`"))
    {
      $sql = "DELETE FROM `comments` WHERE `id_posts` = :id_posts";
      $db->request($sql, ['id_posts' => $id_posts->id]);
    }
    if (file_exists($path))
      unlink($path);
    $_SESSION['flash']['good'] = "The post was well deleted";
    header('location: posts.php');
  }
  else
  {
    $_SESSION['flash']['bad'] = "Dermission Denied";
    header('location: index.php');
  }
}
else
{
  $_SESSION['flash']['bad'] = "Permission Denied";
  header('location: index.php');
}
