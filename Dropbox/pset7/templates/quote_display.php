
<!-- Display the price of the stock after lookup -->

<div>

    <h3><?php print("Price of: " . $name . " is $" . number_format($price, $decimals = 4) . "."); ?></h3>
    
    <br/>
    <h3>Look up another quote</h3>
    <br/>
    
    <form action="quote.php" method="post">
        <fieldset>
            <div class="form-group">
                <input autofocus class="form-control" name="symbol" placeholder="Symbol" type="text"/>
            </div>
        </fieldset>
    </form>
    
    <p>Return to <a href="/">main</a>.

</div>

