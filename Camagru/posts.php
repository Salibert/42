<?php
if (session_status() === PHP_SESSION_NONE){session_start();}

if ($_SESSION['auth'] != "")
{
  require 'class/Autoloader.class.php';
  Autoloader::register();
  Data::get_message();
  $db = DataBase::getInstance();
  $auth = $_SESSION['auth'];
  $filtre = glob('private/image_merge/*.png');
  $data = $db->request("SELECT `id` FROM `posts` WHERE `login` = :login", ['login' => $auth->login], true);
  $postparpage = 4;
  $pagetotal = ceil(Count($data) / $postparpage);
  $nbr_page = (isset($_GET['page']) AND !empty($_GET['page']) AND $_GET['page'] > 0 AND $_GET['page'] <= $pagetotal) ? intval($_GET['page']) : 1;
  $start = ($nbr_page - 1) * $postparpage;
  include 'inc/header.php';
  ?>
  <div class="gallery">
    <form action="upload.php" method="post" enctype="multipart/form-data">
    <div class="padding:10px">
      <img src="private/image_merge/SpongeBob.png" id="photo" alt="photo" height="100px" width="100px">
      <input type="file" name="image">
      <input type="submit" name="submit" value="upload" id="upload" disabled="true">
    </div>

    <?php $id = 0; ?>
    <div style="float:rigth;display:inline-block">
    <?php foreach ($filtre as $value): ?>
      <img src="<?= $value?>" width="100%">
        <input type="radio" name="radio" value="<?=$value?>" id="<?=$id?>" onclick="image_merge(<?=$id?>)">
      <?php $id++; ?>
    <?php endforeach; ?>
  </div>
    </form>
  </div>
  <div class="cam">
  <video id="video"></video><br>
  <button id="startbutton" disabled="true">Prendre une photo</button><br>
  <canvas id="canvas"></canvas><br>
</div>

  <div style="display:inline-block;background-color:white;float:right">
    <?php
    for($index=1; $index<=$pagetotal; $index++){
      if ($index == $nbr_page)
        echo $index.' ';
      else
        echo '<a href="posts.php?page='.$index.'">'.$index.'</a> ';
    }
  $data = $db->request('SELECT `image` FROM `posts` WHERE `login` = :login ORDER BY `id` DESC LIMIT '.$start.','.$postparpage, ['login' => $auth->login], true);
  foreach  ($data as $image): ?>
  <br>
  <div class="gallery_image"><img src="<?=$image->image?>" alt="posts" width="100%">
    <?php $del =  "login=".$auth->login."&path=".$image->image;?>
  <form action="delete_posts.php" method="post">
    <input type="hidden" name="data" value="<?='login='.$auth->login.'&path='.$image->image?>">
    <input  type="submit" name="submit" value="delete"><br>
  </form>
  </div>
  <?php endforeach; ?>
 </div>

  <script type="text/javascript">
    function image_merge(id)
    {
      document.getElementById("startbutton").disabled = false;
      document.getElementById("upload").disabled = false;
  		document.getElementById(id).setAttribute("checked", "");
  		var radio = document.querySelector('input[name=radio]:checked').value;
  		document.getElementById('photo').setAttribute('src', radio);
    }
  </script>
  <script src="js/webcam.js"></script>
  <?php include 'inc/footer.php';
}
else
{
  header('location: index.php');
  $_SESSION['flash']['sign up please'];
}
