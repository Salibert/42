<?php
  session_start();
  if ($_GET['categorie'] != "")
  {
    $categorie = htmlspecialchars(trim($_GET['categorie']));
    $data_products = file_get_contents('private/products');
    $data_products = unserialize($data_products);
    $count = 0;
    foreach ($data_products as $key_products => $value_products)
    {
      if (($tab_categorie = explode(":", $value_products['categorie'])))
      {
        foreach ($tab_categorie as $key_categorie => $value_categorie)
        {
          if ($value_categorie == $categorie)
          {
            $count = $count + 1;
            $tab_products[] = $data_products[$key_products];
          }
        }
      }
    }
    if ($count == 0)
      header('location: index.php');
  }
?>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>DrawMyShop</title>
    <link rel="stylesheet" href="css/style.css">
  </head>
  <body>
    <div id="header">
        <div id="headerTitle">DrawMyShop</div>
        <?php if($_SESSION['loggued_on_user'] == ""){ ?>
        <button onclick="document.getElementById('id01').style.display='block'" class="buttonlogin">Log in / Sign in</button>
        <?php } else { ?>
          <a href="logout.php">
        <button   class="buttonlogout">Log out</button>
        </a>
        <?php } ?>
     </div>
    <div id="id01" class="modal">
        <form class="modal-content animate" action="login.php" method="post">
            <div class="imgcontainer">
                <span onclick="document.getElementById('id01').style.display='none'" class="close" title="Close Modal">&times;</span>
            </div>
            <div class="container">
                <label><b>Nom d'utilisateur</b></label>
                <input type="text" placeholder="Enter Username" name="login" required>
                <label><b>Mot de passe</b></label>
                <input type="password" placeholder="Enter Password" name="passwd" required>
                <button type="submit" name="submit" value="OK">Login</button>
            </div>
            <div class="container" style="background-color:#f1f1f1">
                <button type="button" onclick="document.getElementById('id01').style.display='none'" class="cancelbtn">Cancel</button>
                <span class="psw">Nouvel utilisateur ?   <a href="create.php">Creer un compte ici</a></span>
            </div>
        </form>
    </div>
    <div id="id02" action="logout.php">
    </div>
    <script>
        var modal = document.getElementById('id01');
        var logout = document.getElementById('id02');
        window.onclick = function(event)
        {
            if (event.target == modal)
            {
                modal.style.display = "none";
            }
            if (event.target == logout)
            {
                function NavigateToPage(page)
                {
                    window.location.href = "logout.php";
                }
            }
        }
    </script>
  		<header class="main-header">
  		    <ul class="main-nav" style="width:100%;box-shadow:10px">
            <li><a href="index.php">Home</a></li>
            <li><a href="aff_categorie.php?categorie=Hommes">Hommes</a></li>
            <li><a href="aff_categorie.php?categorie=Femmes">Femmes</a></li>
            <li><a href="aff_categorie.php?categorie=Chaussures">Chaussures</a></li>
            <li><a href="aff_panier.php">Panier</a></li>
          <?php if ($_SESSION['loggued_on_user'] != ""): ?>
            <li class="dropdown">
            <a href="#">Settings
              <ul class="drop-nav">
                <li><a href="modif.php">Modifier son mot de passe</a></li>
                <li><a href="logout.php">Se deconnecter</a></li>
                <li><a href="delete.php">Supprimer son compte</a></li>
              </ul>
            </a>
            </li>
          <?php endif; ?>
          </ul>
  		  </header>
  		<div class="connexion">
  			<?php if (isset($_SESSION['flash'])){echo $_SESSION['flash']; unset($_SESSION['flash']);} ?>
          <?php if ($_SESSION['loggued_on_user'] != ""): ?>
            <a href="settings.php">
          <button   class="buttonlogin">Settings</button>
          </a>
  			<?php endif; ?>
  		</div>
      <?php if($tab_products) foreach ($tab_products as $key => $value) { ?>
        <form action="panier.php" method="post">
          <div class="product" style="color:black;padding:5px">
            <div class="image"><img src="<?php echo $value['image'] ?>" class="day" title="titre" alt="titre"></div>
            <div class="nom"><?php echo $value['nom'] ?></div>
            <div class="prix"><?php echo $value['prix']."$"?></div>
            <input type="hidden" name="data" value="<?php echo $value['nom'];?>">
            <input type="submit" name="submit" value="Ajouter">
          </div>
          </form>
        <?php }
        ?>
  	</body>
  </html>
