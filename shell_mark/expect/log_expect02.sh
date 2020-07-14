#!/usr/bin/expect

set ip [lindex $argv 0]
set user [lindex $argv 1]
set password LHQlhq1761512493
set timeout 5


spawn ssh $user@$ip

expect {
	"yes/no" { send "yes\r"; exp_continue }
	"password:" { send "$password\r" };
}

interact
