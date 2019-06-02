<?php
    include_once("../config/database.php");
    try {
        $conn = new PDO("mysql:host=".$DB_DSN, $DB_USER, $DB_PASSWORD);
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        echo "Connected successfully";
    }
    catch(PDOException $e)
    {
        echo "Connection failed: " . $e->getMessage();
    }
    $conn->exec("CREATE DATABASE IF NOT EXISTS Camagru");
    $conn = null;
    if(!file_exists('../private/uploads'))
      mkdir('../private/uploads');
    if(!file_exists('../private/posts'))
      mkdir('../private/posts');
    require '../class/DataBase.class.php';
    $new_db = DataBase::getInstance();
    $new_db->request("CREATE TABLE IF NOT EXISTS users_data(
        id INT(11) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        login VARCHAR(255) NOT NULL,
        password VARCHAR(255),
        email VARCHAR(255),
        reg_date TIMESTAMP,
        status BOOLEAN DEFAULT false,
        token VARCHAR(255),
        liked TEXT)");
    $new_db->request("CREATE TABLE IF NOT EXISTS recup_mdp(
        id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
        email VARCHAR(255) NOT NULL,
        token VARCHAR(255),
        confirm BOOLEAN DEFAULT false)");
    $new_db->request("CREATE TABLE IF NOT EXISTS posts(
        id INT(11) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        login VARCHAR(255) NOT NULL,
        image VARCHAR(255) NOT NULL,
        likes INT(11) UNSIGNED)");
    $new_db->request("CREATE TABLE IF NOT EXISTS comments(
        id INT(11) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
        login VARCHAR(255) NOT NULL,
        comment TEXT,
        id_posts INT(11) UNSIGNED)");
