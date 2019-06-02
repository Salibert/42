<?php
session_start();
?>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <div id="header">
        <div id="headerTitle">DrawMyShop</div>
        </div>
        <link rel="stylesheet" href="css/style.css">
    </head>
<body>
    <div id="id01" class="modal2">
        <form class="setting_style" action="modif.php" method="get">
            <div class="container" >
              <input type="text" placeholder="Entrer Mot de Passe" name="oldpw" value="" required>
              <input type="text" placeholder="Confrimer Mot de Passe" name="newpw" value="" required>
                <a href="modif.php"><button class="">Modifier mot de passe</button></a>
            </div>
        </form>
        <form class="setting_style"  action="delete.php" style="margin:5vw">
            <div class="container" method="get">
              <input type="text" placeholder="Entrer Mot de Passe" name="passwd" value="" required>
                <a href="delete.php"><button  class="">Supprimer compte</button></a>
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
