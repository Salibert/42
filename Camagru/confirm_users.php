<?php
    if (session_status() === PHP_SESSION_NONE){session_start();}
    require 'class/Autoloader.class.php';
  	Autoloader::register();

    if(isset($_GET['id']) && isset($_GET['t'])){
        $id = htmlspecialchars(trim($_GET['id']));
        $db = DataBase::getInstance();
        $sql = "SELECT * FROM `users_data` WHERE `id` = :id";
        if($data = $db->request($sql, ['id' => $id])){
            if($data->token == $_GET['t']){
                $sql = "UPDATE `users_data` SET `status` = :status, `token`= NULL WHERE `id`= :id";
                $fields= ['status' => 1, 'id' => $data->id];
                $db->request($sql, $fields);
                $_SESSION['flash']['good'] = "account activated";
            } else $_SESSION['flash']['bad'] = "token invalid";
        } else $_SESSION['flash']['bad'] = "id not found";
    } else $_SESSION['flash']['bad'] = "id or token invalid";
    header('location: index.php');
