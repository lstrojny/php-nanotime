--TEST--
Parameter handling
--FILE--
<?php
nano\time(1);
nano\second(1);
?>

==DONE==
--EXPECTF--
Warning: nano\time() expects exactly 0 parameters, 1 given in %snano_zpp.php on line 2

Warning: nano\second() expects exactly 0 parameters, 1 given in %snano_zpp.php on line 3

==DONE==
