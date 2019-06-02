<?php
  if (session_status() === PHP_SESSION_NONE){session_start();}
  if ($_SESSION['auth'] != "")
    $_SESSION['auth'] = "";
    header('location: index.php');
