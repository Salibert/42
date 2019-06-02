<?php
  if ($_POST['submit'] == "OK" && $_POST['login'] && $_POST['passwd']  && ($_POST['passwd2'] === $_POST['passwd']))
  {
    if ($str = file_get_contents('private/users'))
    {
      $login = htmlspecialchars(trim($_POST['login']));
      $passwd = htmlspecialchars(trim($_POST['passwd']));
      if($tab = unserialize($str))
      {
        foreach ($tab as $value)
        {
            if ($value['login'] == $_POST['login'])
            {
              $_SESSION['alert'] = "Ce login existe deja";
              header('location: create.php');
                return;
            }
        }
      }
    }
    $tab[] = ['login' => $login, 'passwd' => hash('whirlpool', $passwd)];
    file_put_contents('private/users', serialize($tab));
    header('location: index.php');
    $_SESSION['flash'] = "creation du compte: Valider";
  }
?>
<!DOCTYPE html>

<html>
    <head>
        <meta charset="utf-8">
        <title> - Creation du compte</title>
        <link rel="stylesheet" href="css/style.css">
    </head>

<body>
    <div id="id01" class="modal2">
                <form class="modal-content animate" action="create.php" method="post">
                    <div class="container">
                        <label><b>Nom d'utilisateur</b></label>
                        <input type="text" placeholder="Enter Username" name="login" required>
                        <label><b>Mot de passe</b></label>
                        <input type="password" placeholder="Enter Password" name="passwd" required>
                        <label><b>Confirmation du mot de passe</b></label>
                        <input type="password" placeholder="Enter Password" name="passwd2" required>
                        <button type="submit" name="submit" value="OK">Créer le compte</button>
                    </div>

                    <div class="container" style="background-color:#f1f1f1">
                        <a href="index.php" class="button">Annuler et retourner sur le site</a>
                    </div>
                </form>
              </div>

            <script>
                var modal = document.getElementById('id02');
                window.onclick = function(event)
                {
                    if (event.target == modal2)
                    {
                        modal.style.display = "none";
                    }
                }
            </script>
    </form>
</body>

</html>
