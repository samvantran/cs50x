<div>

<?php
    $stock_data = lookup($_POST["symbol"]);
?>

<h1>You bought <?= $_POST["shares"] ?> shares of <?= $stock_data["name"] ?>!</h1>

Return to <a href="/">main</a>.
</div>
