#!/usr/bin/expect

spawn ssh root@123.56.145.243

expect {
	"yes/no" { send "yes\r"; exp_continue }
	"password:" { send "LHQlhq1761512493\r" };
}

interact