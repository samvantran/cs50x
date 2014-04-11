<?php

    // configuration
    require("../includes/config.php");
    
    // sell shares
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // calculate revenue
        $shares = query("SELECT shares FROM portfolio WHERE id = ? AND symbol =?", $_SESSION["id"], $_POST["symbol"]);
        $share_price = lookup($_POST["symbol"]);
        $revenue = $shares[0]["shares"] * $share_price["price"];
        
        $delete_share = query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        if ($delete_share !== false)
        {
            query("UPDATE users SET cash = cash + $revenue WHERE id = ?", $_SESSION["id"]);
            
            render("sell_display.php", ["title" => "Sold!"]);
        }
        else
        {
            print("You do not own any shares of this stock!");
        }
    }
    else
    {
    // display sell_form
    render("sell_form.php", ["title" => "Sell Positions"]);
    }
?>
