<?php

    // configuration
    require("../includes/config.php"); 

    // query user's data
    $rows = query("SELECT * FROM portfolio WHERE id = ?", $_SESSION["id"]);
    
    // lookup all positions in user's portfolio
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
                ];
        }
    }

    // render portfolio
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio"]);
    

?>
