<?php
if (session_status() === PHP_SESSION_NONE){session_start();}
require 'class/Autoloader.class.php';
Autoloader::register();
$db = DataBase::getInstance();
if($_SESSION['auth'] != "")
  $auth = $_SESSION['auth'];
if(isset($_GET['posts']))
  $id_posts = intval($_GET['posts']) > 0 ? intval($_GET['posts']) : 1;
$data_post = $db->request("SELECT `image` FROM `posts` WHERE `id` = :id", ['id' => $id_posts]);
if (empty($data_post))
{
  header('location: index.php');
  exit;
}

include ('inc/header.php');
Data::get_message();
?>
    <?php
    if (!empty($_GET['posts']) AND ($_SESSION['auth'] != ""))
    {
      if(($_POST['submit'] == 'Post') AND !empty($_POST['comment']) AND !empty($_GET['posts']) AND ($_SESSION['auth'] != ""))
      {
        $comment = htmlspecialchars(trim($_POST['comment']));
        $sql = "INSERT INTO `comments` (`login`,`comment`,`id_posts`) VALUES (:login, :comment, :id_posts)";
        $fields = [
                    'login' => $auth->login,
                    'comment' =>$comment,
                    'id_posts' => $id_posts
                  ];
        $db->request($sql, $fields);

        $sql = "SELECT `login` FROM posts WHERE `id` = :id";
        $login = $db->request($sql, ['id' => $id_posts]);
        $sql = "SELECT `email` FROM users_data WHERE `login` = :login";
        $email = $db->request($sql, ['login' => $login->login]);
        $subject = 'Comments - Camagru';
        $header  = "MIME-Version: 1.0\r\n";
        $header .= 'From:"Camagru"<support@twelveforstudy.com>'."\n";
        $header .= 'Content-Type:text/html; charset="UTF-8"'."\n";
        $header .= 'Content-Transfer-Encoding: 8bit';
        $message = '<p align="center"">Welcome '.$login->login.'
        <a href="http://localhost:8080/camagru/comments.php?posts='.$id_posts.'&limit=10">wacth the comment</a></p>';
        mail($email->email, $subject, $message, $header);
        $_POST['comment'] = NULL;
      }
    }
    else
      $_SESSION['flash']['bad'] = "sign in you for post your comments";
    if(!empty($_GET['posts']))
    {
      ?>
      <div style="width: 80%; margin: auto; text-align: center;">
    <img style="width:75%;"src="<?=$data_post->image?>">
    <br>

      <form class="" action="comments.php?posts=<?= $_GET['posts'] ?>" method="post">
        <h2>Post your comments</h2>
        <textarea name="comment" rows="8" cols="80" placeholder="comment..."></textarea>
        <input type="submit" name="submit" value="Post">
      </form>
    <?php
    if ($empty = $db->request("SELECT * FROM `comments`"))
    {
      if (isset($_GET['limit']))
        $comparpage = intval($_GET['limit']);
      else
        $comparpage = 5;

      $sql = "SELECT * FROM `comments` WHERE `id_posts`= :id_posts ORDER BY `id` DESC LIMIT 0 ,".$comparpage;
      $comments = $db->request($sql,[ 'id_posts' => $id_posts], true);
      $i = 0;
      foreach ($comments as $value) : ?>
        <div class="">
          <h3>[<?=$value->login?>]:</h3>
          <p><?=$value->comment?></p>
        </div>
      <?php $i++;
    endforeach;
      if ($i >= $comparpage )
        $comparpage = $comparpage + 5;
      else
        $comparpage = $i;
      echo '<a style="float:right"href="comments.php?posts='.$id_posts.'&limit='.$comparpage.'">more comments</a>';?>
    </div>
    <?php }
  }
  include ('inc/footer.php');
