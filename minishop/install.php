<?php
  if (!file_exists('private'))
  {
    mkdir('private');
    $tab_users[] = ["login" => "Admin", "passwd" => hash('whirlpool', "Admin")];
    file_put_contents('private/users', serialize($tab_users));
    $fd = fopen("private/command", "a");
    fclose($fd);
    file_put_contents("private/.htaccess", "Options -Indexes\ndeny from all\n");
  	$fd = fopen("private/products", "a");
  	{
      $tab[] = ["nom" => "Pull bleu",
        				"description" => "Pull en coton",
        				"categorie" => "Hommes:Vetements",
        				"prix" => "34",
        				"image" => "http://media.laredoute.com/products2/250by250/d/4/2/501860528_1005_CO_1_1200.jpg"];
        		$tab[] = ["nom" => "Pull rouge",
        				"description" => "Pull en coton",
        				"categorie" => "Femmes:Vetements",
        				"prix" => "34",
        				"image" => "http://i2.cdscdn.com/pdt2/8/6/9/1/300x300/mp00710869/rw/pull-rouge-homme-fruit-of-the-loom-rouge.jpg"];
        		$tab[] = ["nom" => "Trench",
        				"description" => "Manteau de detective",
                "categorie" => "Hommes:Vetements",
        				"prix" => "120",
        				"image" => "http://miss30andsomething.i.m.f.unblog.fr/files/2010/03/trench1.jpg"];
        		$tab[] = ["nom" => "Tee shirt noir",
        				"description" => "Tee shirt ninja",
        				"categorie" => "Hommes:Vetements",
        				"prix" => "5",
        				"image" => "https://www.leslipfrancais.fr/3031-thickbox_default/t-shirt-homme-noir-bradley.jpg"];
        		$tab[] = ["nom" => "Tee shirt blanc",
        				"description" => "Tee shirt blanc",
        				"categorie" => "Hommes:Vetements",
        				"prix" => "5",
        				"image" => "http://media.laredoute.com/products2/250by250/e/a/9/500750262_1015_CO_1_1200.jpg"];
        		$tab[] = ["nom" => "Nike airforce one",
        				"description" => "Des baskets qui font voler",
                "categorie" => "Hommes:Chaussures",
        				"prix" => "130",
        				"image" => "http://mpe-d2-p.mlstatic.com/nike-air-force-one-solo-pedidos-611211-MPE20484958879_112015-F.jpg"];
        		$tab[] = ["nom" => "Pull rose",
        				"description" => "Pull en coton de couleur rose",
                "categorie" => "Hommes:Vetements",
        				"prix" => "34",
        				"image" => "http://media.dorothyperkins.com/wcsstore/DorothyPerkinsFR/images/catalog/75100409_large.jpg"];
        		$tab[] = ["nom" => "Pull jaune",
        				"description" => "Pull en coton de couleur jaune",
                "categorie" => "Femmes:Vetements",
        				"prix" => "34",
        				"image" => "https://s-media-cache-ak0.pinimg.com/736x/05/12/a4/0512a404012b686288b5fc7df46980c7.jpg"];
        		$tab[] = ["nom" => "Parka kaki",
        				"description" => "Parka de couleur kaki", "categorie" => "13",
        				"prix" => "120",
        				"image" => "https://images-eu.ssl-images-amazon.com/images/I/418-3RAXsHL._AC_UL260_SR200,260_.jpg"];
        		$tab[] = ["nom" => "Tee shirt vert",
        				"description" => "Tee shirt de couleur blanc",
                "categorie" => "Femmes:Vetements",
        				"prix" => "13",
        				"image" => "http://i2.cdscdn.com/pdt2/6/6/5/1/700x700/mp02681665/rw/t-shirt-vert-irlandais-mixte-homme-femme-sc221-100.jpg"];
        		$tab[] = ["nom" => "Legging yoga",
        				"description" => "Leggin de couleur yoga",
                "categorie" => "Hommes:Vetements",
        				"prix" => "15",
        				"image" => "http://media.laredoute.com/products2/641by641/6/7/7/506874414_1000_CO_1_1200.jpg"];
        		$tab[] = ["nom" => "Escarpin",
        				"description" => "Escarpin Louis bouton",
                "categorie" => "Femmes:Chaussures",
        				"prix" => "5000",
        				"image" => "https://www.lamodeuse.com/80675-large_default/escarpins-noirs-ajoures-forme-goutte-d-eau.jpg"];
  		file_put_contents("private/products", serialize($tab));
  	}
  	fclose($fd);
  }
?>
