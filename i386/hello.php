#!/usr/bin/php
<?php
# test
echo "============\n";
echo "i am php" . PHP_EOL;

$pid = posix_getpid();
$ppid = posix_getppid();

echo "pid:$pid, ppid:$ppid" . PHP_EOL;


