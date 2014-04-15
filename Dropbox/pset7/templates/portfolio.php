
<!-- Internal styling-->

    <style>

    .portfolio { width: 600px; margin: auto; border: 3px solid black; }
    tr.heading { font-weight: bold; text-align: center; }
    td { padding-left: 25px; padding-right: 25px; }
    .navbar a { padding-left: 20px; padding-right: 20px; }

    </style> 

<!-- navbar -->

    <div class="navbar">
        <a href="quote.php">Get Quote</a>
        <a href="buy.php">Buy Shares</a>
        <a href="sell.php">Sell Shares</a>
        <a href="history.php">History</a>
        <a href="logout.php">Log Out</a>
    </div>

<!-- Display Portfolio -->    

    <div class="portfolio">
        <table >
            <tr class="heading">
                <td>Symbol</td>
                <td>Name</td>
                <td>Shares</td>
                <td>Price</td>
                <td>Total</td>
            </tr>      
                 
            <?php foreach ($positions as $position): ?>
                
                <tr>
                    <td><?= $position["symbol"] ?></td>
                    <td><?= $position["name"] ?></td>
                    <td><?= $position["shares"] ?></td>
                    <td><?= number_format($position["price"], 4) ?></td>
                    <td><?= number_format($position["shares"] * $position["price"], 4) ?>
                </tr>

            <?php endforeach ?>
                <tr>
                    <td>CASH</td>
                    <td></td>
                    <td></td>
                    <td></td>
                    <td><?php 
                        $user_data = query("SELECT * FROM users WHERE id =?", $_SESSION["id"]);
                        print_r($user_data[0]["cash"]);
                        ?></td>
                </tr>
        </table>
    </div>

