<?php

    // configuration
    require("../includes/config.php");
    
    $cash = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    
    // purchase (more) shares of stock
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock_data = lookup($_POST["symbol"]);

        // check stock exists
        if ($stock_data == false)
        {
            apologize("Stock does not exist");
        }
        else
        {            
            // check for non-fractional amount of shares
            if (preg_match("/^\d+$/", $_POST["shares"]) !== false)
            {
                // store symbol and price
                $stock_symbol = $stock_data["symbol"];
                $transaction_cost = $stock_data["price"] + $_POST["shares"];
                
                // check for sufficient funds
                if ($transaction_cost <= query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]))
                {
                    // subtract cost from funds
                    query("UPDATE users SET cash = cash - $transaction_cost WHERE id = ?", $_SESSION["id"]);
                    
                    // buy shares and add to portfolio
                    query("INSERT INTO portfolio (id, symbol, shares) VALUES(?, '$stock_symbol', ?)
                    ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $_POST["shares"]);
                }
                else 
                {
                    apologize("You don't have enough money!");
                }
            }
            else
            {
                apologize("Fractions of shares not accepted. Please enter whole numbers.");
            }
        }
        
        render("buy_display.php", ["title" => "Stocks Purchased!"]);
    
    }
    else
    {
    render("buy_form.php", ["title" => "Buy Stocks!"]);
    }
?>
