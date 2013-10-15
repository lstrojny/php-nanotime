--TEST--
nano\time()
--INI--
precision=20
--FILE--
<?php
var_dump(nano\time());
printf("%1.20F", nano\time());
?>

==DONE==
--EXPECTREGEX--
float(.*)
1\d{9}\.\d{20}
==DONE==
