
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
                <td><?= $position["price"] ?></td>
                <td><?= print($position["shares"] * $position["price"]) ?>
            </tr>

        <?php endforeach ?>
    </table>
</div>

<div>
    <a href="quote.php">Get Quote</a>
    <br/>
    <a href="logout.php">Log Out</a>
</div>
