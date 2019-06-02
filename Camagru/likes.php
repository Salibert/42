<?php
if (session_status() === PHP_SESSION_NONE){session_start();}
require 'class/Autoloader.class.php';
Autoloader::register();

if ($_SESSION['auth'] == "")
{
  $_SESSION['flash']['bad'] = "please sign up you";
  header('location: index.php');
}
elseif((strstr($_POST['submit'], "likes(")) AND (isset($_POST['data'])))
{
  $auth = $_SESSION['auth'];
  $tab = explode('&id=', $_POST['data']);
  $login = substr($tab[0], 6);
  $id_post = $tab[1];

  if($login == $auth->login)
  {
    $db = DataBase::getInstance();
    $sql = "SELECT `liked` FROM `users_data` WHERE `login` = :login";
    $user = $db->request($sql, ['login' => $login]);
    $sql = "SELECT `likes` FROM `posts` WHERE  `id` = :id";
    $post = $db->request($sql, ['id' => $id_post]);
    if($user->liked == "")
    {
      $user->liked = $id_post.'/';
      $post->likes = 1;
    }
    elseif (in_array($id_post, explode('/', $user->liked)))
    {
      $user->liked = str_replace($id_post.'/', '', $user->liked);
      $post->likes = $post->likes - 1;
    }
    else
    {
        $user->liked = $user->liked.$id_post.'/';
        $post->likes = $post->likes + 1;
    }
    $sql = "UPDATE `users_data` SET `liked` = :liked WHERE `login`= :login";
    $fields= ['liked' => $user->liked, 'login' => $login];
    $db->request($sql, $fields);
    $sql = "UPDATE `posts` SET `likes` = :likes WHERE `id`= :id";
    $fields= ['likes' => $post->likes, 'id' => $id_post];
    $db->request($sql, $fields);
    header('location: index.php');
  }
  else
  {
    $_SESSION['flash']['bad'] = "Permission Denied";
    header('location: index.php');
  }
}
else
{
  $_SESSION['flash']['bad'] = "Permission Denied";
  header('location: index.php');
}
