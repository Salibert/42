<?php
  session_start();
  if ($_SESSION['panier'])
  {
    $data_products = file_get_contents('private/products');
    $data_products = unserialize($data_products);
    $total = 0;
    foreach ($_SESSION['panier'] as $key => $value)
    {
      $tab_panier = $_SESSION['panier'][$key];
      foreach ($data_products as $key_panier => $value_panier)
      {

        if ($value_panier['nom'] == $tab_panier['nom'])
        {
          if ($_SESSION['loggued_on_user'] == "")
            $login = "users";
          else
            $login = $_SESSION['loggued_on_user'];
          $nom = $tab_panier['nom'];
          $image = $value_panier['image'];
          $description = $value_panier['description'];
          $prix = $value_panier['prix'];
          $total += $prix * $tab_panier['quantite'];
          $final[] =  ['nom' => $nom,
          'image' => $image,
          'description' => $description,
          'prix' => $prix * $tab_panier['quantite'],
          'quantite' => $tab_panier['quantite'],
          'total' => $total];
        }
      }
      $_SESSION['command'] = $final;
    }
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
                <a href="settings.php">
              <button   class="buttonlogin">Settings</button>
                </a>
              <?php endif; ?>
            </ul>
    		  </header>
          <?php if (isset($_SESSION['alert'])): ?>
            <div class="alert">
              <span class="closebtn" onclick="this.parentElement.style.display='none';">&times;</span>
              <strong>Attention!</strong> <?php echo $_SESSION['alert']; ?>
            </div>
          <?php unset($_SESSION['alert']); endif; ?>
          <?php if (isset($_SESSION['flash'])): ?>
          <div class="alert-success">
            <span class="closebtn" onclick="this.parentElement.style.display='none';">&times;</span>
          <?php echo $_SESSION['flash']; ?>
          </div>
        <?php unset($_SESSION['flash']); endif; ?>
      <table class="table_admin" style="margin-top:5vw">
        <tr class="th_admin">
          <th class="th_admin">Image</th>
          <th class="th_admin">Nom</th>
          <th class="th_admin">Description</th>
          <th class="th_admin">Prix</th>
          <th class="th_admin">Quantité</th>
          <th class="th_admin">Gestion</th>
          <th class="th_admin"><a href="kill_panier.php"><img style="width:2vw"src="https://grand-monitor.com/design/img/war.png" alt=""></a></th>
          <?php if ($final){ ?>
        </tr>
        <tr class="tr_admin" >
          <?php foreach ($final as $key => $value){ ?>
            <tr class="tr_admin">
              <td class="td_admin"><img  style="margin:auto;width:5vw"src="<?php echo $value['image']; ?>" alt=""></td>
              <td class="td_admin"><?php echo $value['nom']; ?></td>
              <td class="td_admin"><?php echo $value['description']; ?></td>
              <td class="td_admin"><?php echo $value['prix']."$"; ?></td>
              <td class="td_admin"><?php echo $value['quantite']; ?></td>
              <td class="td_admin">
                <a class="a_admin" href="kill_products.php?nom=<?php echo $value['nom']; ?>">supprimer</a>
              </td>
            </tr>
          <?php }?>
          <tr class="tr_admin">
            <td class="td_admin"></td>
            <td class="td_admin"></td>
            <td class="td_admin"></td>
            <td class="td_admin"></td>
            <td class="td_admin"><?php echo $total."$"; ?></td>
            <td class="td_admin">
              <a class="a_admin" href="valid.php">Valider Commande</a>
            </td>
          </tr>
          <?php } ?>
        </tr>
      </table>
      </body>
    </html>
