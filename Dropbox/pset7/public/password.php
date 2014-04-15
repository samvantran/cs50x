<?php

    // configuration
    require("../includes/config.php");
    
    if($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check for correct current password
        $row = query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
        
        if (crypt($_POST["curr_password"], $row[0]["hash"]) == $row[0]["hash"])
        {
            // change password
            query("UPDATE users SET hash = ? WHERE id = ?", crypt($_POST["updated_password"], $row[0]["hash"]), $_SESSION["id"]);
            
            // display success page
            render("password_changed.php", ["title" => "Password Changed!"]);
        }
        else
        {
            apologize("That is not the correct password!");
        }
    }
    else
    {   
    render("password_form.php", ["title" => "Password Changed!"]);
    }
?>
