<?php
  session_start();
  if ($_SESSION['loggued_on_user'] != 'Admin')
  {
    header('location: ../index.php');
    $_SESSION['alert'] = "Casse toi";
  }
  $tab = file_get_contents("../private/users");
  $tab = unserialize($tab);
  $tab_products = file_get_contents("../private/products");
  $tab_products = unserialize($tab_products);
  $tab_command = file_get_contents("../private/command");
  $tab_command = unserialize($tab_command);
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>DrawMyShop</title>
    <link rel="stylesheet" href="../css/style.css">
  </head>
  <body>
  		<header class="main-header">
  		    <ul class="main-nav" style="width:100%;box-shadow:10px">
            <li><a href="../index.php">Home</a></li>
            <li><a href="../aff_categorie.php?categorie=Hommes">Hommes</a></li>
            <li><a href="../aff_categorie.php?categorie=Femmes">Femmes</a></li>
            <li><a href="../aff_categorie.php?categorie=Chaussures">Chaussures</a></li>
            <li><a href="../aff_panier.php">Panier</a></li>
            <?php if ($_SESSION['loggued_on_user'] == ""): ?>
                <a href="#">Se connecter</a>
              <form class="" action="login.php" method="post" style="margin:10px">
                <label for="login">Identifiant</label>
                  <input type="text" name="login" value=""><br/>
                  <label for="passwd">Mot de Passe</label>
                  <input type="text" name="passwd" value=""><br/>
                  <input type="submit" name="submit" value="OK">
                  <a href="create.php"><p style=font-size:0.7em;>Creer son Compte</p></a>
                </form>
          <?php endif; ?>
          <?php if ($_SESSION['loggued_on_user'] != ""): ?>
            <li class="dropdown">
            <a href="#">Settings
              <ul class="drop-nav" style="padding:10px">
                <li><a href="../logout.php">Se deconnecter</a></li>
                <li><a href="../delete.php">Supprimer son compte</a></li>
              </ul>
            </a>
            </li>
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
      <table class="table_admin">
        <tr class="th_admin">
          <th class="th_admin">Utilisateurs</th>
          <th class="th_admin">Mot de passe</th>
          <th class="th_admin">gestion</th>
        </tr>
        <tr class="tr_admin">
          <?php foreach ($tab as $key => $value){ ?>
            <tr class="tr_admin"><td class="td_admin"><?php echo $value['login']; ?></td>
              <td class="td_admin"><?php echo $value['passwd']; ?></td>
              <td class="td_admin">
                <a class="a_admin" href="kill_users.php?login=<?php echo $value['login']; ?>">supprimer</a>
              </td>
            </tr>
          <?php } ?>
        </tr>
      </table>
    <form style="margin-top:1vw" action="add_users.php" method="post">
      <input class="input_admin" type="text" name="login" value="" placeholder="login">
      <input class="input_admin" type="text" name="passwd" value="" placeholder="passwd">
      <input class="input_admin" style="  background-color: #4CAF50;" type="submit" name="submit" value="OK">
    </form>
    <table class="table_admin" style="margin-top:5vw">
      <tr class="th_admin">
        <th class="th_admin">image</th>
        <th class="th_admin">nom</th>
        <th class="th_admin">description</th>
        <th class="th_admin">categorie</th>
        <th class="th_admin">prix</th>
        <th class="th_admin">gestion</th>
      </tr>
      <tr class="tr_admin" >
        <?php if ($tab_products){foreach ($tab_products as $key => $value){ ?>
          <tr class="tr_admin">
            <td class="td_admin"><img style="margin:auto;width:5vw" src="<?php echo $value['image']; ?>" alt=""></td>
            <td class="td_admin"><?php echo $value['nom']; ?></td>
            <td class="td_admin"><?php echo $value['description']; ?></td>
            <td class="td_admin"><?php echo $value['categorie']; ?></td>
            <td class="td_admin"><?php echo $value['prix']."$"; ?></td>
            <td class="td_admin">
              <a class="a_admin" href="kill_products.php?nom=<?php echo $value['nom']; ?>">supprimer</a>
            </td>
          </tr>
        <?php }} ?>
      </tr>
    </table>
    <form style="margin-top:1vw;text-align:center;" action="modif_products.php" method="post">
      <input class="input_add" type="text" name="image" value="" placeholder="path_image">
      <input class="input_add" type="text" name="nom" value="" placeholder="nom">
      <input class="input_add" type="text" name="description" value="" placeholder="description">
      <input class="input_add" type="text" name="categorie" value="" placeholder="categorie">
      <input class="input_add" type="text" name="prix" value="" placeholder="prix">
      <input class="input_add" style="  background-color: #4CAF50;" type="submit" name="submit" value="OK">
    </form>
    <table class="table_admin" style="margin-top:5vw">
      <tr class="th_admin">
        <th class="th_admin">login</th>
        <th class="th_admin">date</th>
        <th class="th_admin">nom</th>
        <th class="th_admin">total</th>
        <th class="th_admin">gestion</th>
      </tr>
      <tr class="tr_admin" >
        <?php if($tab_command){foreach ($tab_command as $key => $value){ ?>
          <tr class="tr_admin">
            <td class="td_admin"><?php echo $value['login']; ?></td>
            <td class="td_admin"><?php echo $value['date']; ?></td>
            <td class="td_admin">
            <?php if($value['command']){foreach ($value['command'] as $key => $value_nom){?>
              <?php echo $value_nom['nom']."   "; ?>
            <?php }} ?>
            </td>
            <td class="td_admin"><?php echo $value_nom['total']."$"; ?></td>
            <td class="td_admin">
              <a class="a_admin" href="remboursement.php?login=<?php echo $value['login']."&"; ?>date=<?php echo $value['date']?>">Remboursement</a>
            </td>
          </tr>
        <?php }} ?>
      </tr>
    </table>
    </body>
  </html>
