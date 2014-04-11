
<!-- Internal styling-->

    <style>

    .portfolio { width: 600px; margin: auto; border: 3px solid black; }
    tr.heading { font-weight: bold; text-align: center; }
    td { padding-left: 25px; padding-right: 25px; }

    </style> 
    
<!-- Display Portfolio -->    
    
<div>
    <h1>Look at your Portfolio!</h1>
</div>

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

<br/>
<div>
    <a href="quote.php">Get Quote</a>
    <br/>
    <a href="sell.php">Sell Shares</a>
    <br/>
    <a href="logout.php">Log Out</a>
</div>
