<?php

    // configuration
    require("../includes/config.php");

    // render quote
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $s = lookup($_POST["symbol"]);
            
        if ($s === false)
        {
            apologize("Not a valid stock symbol!");
        }
        else
        {
            render("quote_display.php", ["title" => "Quote Price", "name" => $s["name"], "price" => $s["price"]]);
        }
    }
    else
    {
        render("quote_form.php", ["title" => "Get Quote!"]);
    }
?>
