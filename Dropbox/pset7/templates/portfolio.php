
<!-- display portfolio -->


<!-- Internal styling-->

    <style>

    .portfolio {
        width: 500px;
        margin: auto;
        border: 3px solid black;
        text-align: center;
    }
    
    tr.heading {
        font-weight: bold;
        text-align: center;
    }

    </style> 
    
<!-- Display Portfolio -->    
    
<div>
    <h1>Look at your Portfolio!</h1>
</div>

<div class="portfolio">
    <table >
        <tr class="heading">
            <td>Symbol</td>
            <td>Shares</td>
            <td>Price</td>
        </tr>      
             
        <?php foreach ($positions as $position): ?>
            
            <tr>
                <td><?= $position["symbol"] ?></td>
                <td><?= $position["shares"] ?></td>
                <td><?= $position["price"] ?></td>
            </tr>

        <?php endforeach ?>
    </table>
</div>

<div>
    <a href="quote.php">Get Quote</a>
    <br/>
    <a href="logout.php">Log Out</a>
</div>
