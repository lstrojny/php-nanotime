php-nanotime [![Build Status](https://secure.travis-ci.org/lstrojny/php-nanotime.png)](http://travis-ci.org/lstrojny/php-nanotime)
============

PHP bindings for libnanotime for nanosecond precision timestamps


Usage
-----

```php
$currentNanoSecond = nano\second(); // int(1381843170058990080)
$currentTimestampWithNanoSecondPrecision = nano\time() // float(1381843170.059027910232543945312)
```
