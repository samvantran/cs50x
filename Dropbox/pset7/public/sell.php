<?php

    // configuration
    require("../includes/config.php");
    
    // sell shares
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check stock exists
        $stock_data = lookup($_POST["symbol"]);
        if ($stock_data !== false)
        {
            // check user owns stock
            $shares = query("SELECT * FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
            if (!empty($shares))
            {
                // delete stock from portfolio
                $delete_share = query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);

                // calculate revenue for selling shares and update portfolio
                $revenue = $shares[0]["shares"] * $stock_data["price"];
                query("UPDATE users SET cash = cash + $revenue WHERE id = ?", $_SESSION["id"]);
                
                // log transaction in history
                query("INSERT INTO history(id, transaction, datetime, symbol, shares, price) 
                        VALUES(?, 'SELL', NOW(), ?, ?, ?)", $_SESSION["id"], strtoupper($_POST["symbol"]), $shares[0]["shares"], $revenue);

                // display form
                render("sell_display.php", ["title" => "Sold!"]);
            }
            else
            {
                apologize("You do not own any shares of this stock!");
            }
            
        }
        else
        {
            apologize("Stock does not exist!");
        }
    }
    else
    {
    // display sell_form
    render("sell_form.php", ["title" => "Sell Positions"]);
    }
?>
