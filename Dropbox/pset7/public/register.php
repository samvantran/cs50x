<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["username"))
        {
            apologize("You must enter a username!");
        }
        else if (empty($_POST["password"]) || empty($_POST["confirmation"]))
        {
            apologize("You must enter a password!");
        }
        else if($_POST["password"] !== $_POST["confirmation"])
        {
            apologize("Passwords do not match!");
        }
        
        // $result = query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"]));
    }
    else
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

?>
