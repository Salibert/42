<?php
  if (session_status() === PHP_SESSION_NONE){session_start();}
  require 'class/Autoloader.class.php';
  Autoloader::register();
  if($_SESSION['auth'] != "")
    $auth = $_SESSION['auth'];
  $db = DataBase::getInstance();
  include ('inc/header.php');
  Data::get_message();
  $data = $db->request("SELECT `id` FROM `posts`", false, true);
  $postparpage = 4;
  $limit = 5;
  $pagetotal = ceil(Count($data) / $postparpage);
  $nbr_page = (isset($_GET['page']) AND !empty($_GET['page']) AND $_GET['page'] > 0 AND $_GET['page'] <= $pagetotal) ? intval($_GET['page']) : 1;
  $start = ($nbr_page - 1) * $postparpage;
?>

<?php $data = $db->request('SELECT `image`, `likes`, `id` FROM `posts` ORDER BY `id` DESC LIMIT '.$start.','.$postparpage, false, true); ?>
<div align="center" style="margin-top:10%">
<?php foreach  ($data as $posts): ?>
  <div style="display:inline-block">
  <div style="margin-left:40px"><img src="<?=$posts->image?>" alt="posts" width="300">
<form class="gallery" action="likes.php" method="post">
  <input type="hidden" name="data" value="<?='login='.$auth->login.'&id='.$posts->id?>">
  <input  type="submit" name="submit" value="<?='likes('.$posts->likes.')'?>">
  <a align="center" href="<?='comments.php?posts='.$posts->id?>">View comments</a>
  </div>
</form>
</div>
<?php endforeach; ?>
<div class="">

<?php
for($index=1; $index<=$pagetotal; $index++){
  if ($index == $nbr_page)
    echo $index.' ';
  else
    echo '<a href="index.php?page='.$index.'">'.$index.'</a>'.' ';
}
 ?>
</div>
</div>
<?php include ('inc/footer.php'); ?>
