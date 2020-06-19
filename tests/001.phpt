--TEST--
Check if purify is loaded
--SKIPIF--
<?php
if (!extension_loaded('purify')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "purify" is available';
?>
--EXPECT--
The extension "purify" is available
