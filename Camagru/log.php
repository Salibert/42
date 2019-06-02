<?php
    if (session_status() === PHP_SESSION_NONE){session_start();}
    require 'class/Autoloader.class.php';
    Autoloader::register();

    if (($_POST['submit'] == "Sign in") &&
        isset($_POST['password']) &&
        isset($_POST['login']))
    {
        $db = DataBase::getInstance();
        $login = htmlspecialchars(trim($_POST['login']));
        $password = sha1($_POST['password']);
        $sql = "SELECT * FROM `users_data` WHERE `login` = :login";
        $fields = ['login' => $login];
        $data = $db->request($sql, $fields);
        if ($data->password == $password)
        {
          if ($data->status == 1)
          {
            $_SESSION['auth'] = $data;
            header('location: posts.php');
            return;
          }
          else
              $_SESSION['flash']['bad'] = "ckeck your email";
        }
        else
            $_SESSION['flash']['bad'] = "password wrong";
    }
    else $_SESSION['flash']['bad'] = "fields invalid";
    header('location: index.php');
