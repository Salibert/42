<?php
if (session_status() === PHP_SESSION_NONE){session_start();}
require 'class/Autoloader.class.php';
Autoloader::register();

if ($_SESSION['auth'] == "")
  header('location: index.php');

$success = 0;

if(($_POST['submit'] == "upload") AND isset($_FILES['image']) AND
  ($_FILES['image']['name'] != "") AND ($_FILES['image']['error'] == 0) AND
  is_uploaded_file($_FILES['image']['tmp_name']) AND (isset($_POST['radio'])))
{
  $image = $_FILES['image'];

  $sizemax = 2097152;

  if($image['size'] > $sizemax)
    $_SESSION['flash']['bad'] = "file is SO FAT !!! please 2MO maxi";
  else
  {
    $extensions = array('jpeg' , 'jpg');
    $tab = explode('.', $image['name']);
    $type = explode('/', $image['type']);

    if ((count($tab) != 2) AND
    (!in_array($extensions ,strtolower($tab))) AND
    (!in_array($extensions ,strtolower($type))))
      $_SESSION['flash']['bad'] = "bad extensions";
    else
    {
      $data = $_SESSION['auth'];
      $uploads_dir = 'private/uploads/'.$data->id;
      if (!file_exists($uploads_dir))
        mkdir($uploads_dir);
      $token = str_replace('.', $data->id, uniqid("", true));
      $path = 'private/uploads/'.$data->id.'/'.$token.".jpeg";
      move_uploaded_file($image['tmp_name'], $path);
      $finfo = new finfo(FILEINFO_MIME);
      if (!$finfo)
      {
          $_SESSION['flash']['bad'] = "problem";
          header('location: posts.php');
      }
      $mime = mime_content_type($path);
      $fileinfo = array('image/jpeg', 'image/jpg');
      if (!in_array($mime, $fileinfo))
      {
          $_SESSION['flash']['bad'] = "impossible";
          $mask = "private/uploads/".$data->id.'/*.jpeg';
          array_map("unlink", glob($mask));
          rmdir('private/uploads/'.$data->id);
          header('location: posts.php');
      } else {
        $success = 1;
      }
    }
  }
}
elseif(isset($_POST['data']) && isset($_POST['radio']))
{
  $data = $_SESSION['auth'];
  $img = $_POST['data'];
  $decoded = substr($img,23);
  $decoded = str_replace(' ', '+', $decoded);
  $decoded = base64_decode($decoded);
  $token = str_replace('.', $data->id, uniqid("", true));
  $path = "private/uploads/".$data->id."";

  if (!file_exists($path))
		mkdir($path);

  $path = "private/uploads/".$data->id."/".$token.".jpeg";
	file_put_contents($path, $decoded);
  $success = 1;
}
if ((isset($_POST['radio'])) AND ($success == 1))
{
  $filtre = imagecreatefrompng($_POST['radio']);
  $largeur_filtre = imagesx($filtre);
  $hauteur_filtre = imagesy($filtre);
  imagealphablending($filtre, true);
  imagesavealpha($filtre, true);

  $photo = imagecreatefromjpeg($path);
  $largeur_photo = imagesx($photo);
  $hauteur_photo = imagesy($photo);

  $photo_x = ($largeur_photo - $largeur_filtre)/2;
  $photo_y =  ($hauteur_photo - $hauteur_filtre)/2;

  imagecopy($photo, $filtre, $photo_x, $photo_y, 0, 0, $largeur_filtre, $hauteur_filtre);
  imagecolortransparent ($photo, 100);

  if (!file_exists("private/posts/".$data->id))
		mkdir("private/posts/".$data->id);

  imagejpeg($photo, "private/posts/".$data->id.'/'.$token.'.jpeg', 75);

  $db = DataBase::getInstance();
  $sql = "INSERT INTO posts(login, likes, image)
          VALUES(:login, :likes, :image)";
  $fields = [
              'login' => $data->login,
              'likes' => 0,
              'image' => 'private/posts/'.$data->id.'/'.$token.'.jpeg'
            ];
  $db->request($sql, $fields);

  imagedestroy($filtre);
  imagedestroy($photo);
  $mask = "private/uploads/".$data->id.'/*.jpeg';
  array_map("unlink", glob($mask));
  rmdir('private/uploads/'.$data->id);
  $_SESSION['flash']['good'] = "picture catch !!!";
}
else
{
  $_SESSION['flash']['bad'] = "Impossible to make editing";
}
header('location: posts.php');
