GREEN='\033[0;32m'
DARK_BLUE='\e[1;34m'
RED='\x1B[31m'
BLUE='\e[96m'
NC='\033[0m'
i=0
success=0
error=0

# $1 = text, $2 = test number
test()
{
	printf "$1" >> result.log
	./a.out $2 > original_output
	echo $? >> original_output
	./a.out $2 user > user_output
	echo $? >> user_output
	if diff "original_output" "user_output" >> /dev/null
	then
		if [ $error -eq 1 ]
		then
			printf "\n"
		fi
    	printf "${GREEN}OK ${NC}"
    	printf "${GREEN}OK ${NC}\n" >> result.log
		((success++))
		error=0
	else
    	printf "\n${RED}$1"
		printf "${RED}FAILED${NC}"
		printf "${RED}FAILED${NC}\n" >> result.log
		error=1
	fi
	((i++))
}

rm result.log
make all
make bonus
gcc -Wall -Wextra -Werror -Wformat=0 test-printf/test-main.c libftprintf.a
printf "\n${BLUE}[D - Tests with flag 0]${NC}\n"
test "$i - (\"%%01i\", 0) : ${NC}" $i 
test "$i - (\"%%02i\", 0) : ${NC}" $i 
test "$i - (\"%%010i\", 0) : ${NC}" $i 
test "$i - (\"%%01i\", -1) : ${NC}" $i 
test "$i - (\"%%02i\", -1) : ${NC}" $i 
test "$i - (\"%%03i\", -1) : ${NC}" $i 
test "$i - (\"%%09i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011i\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%01d\", 0) : ${NC}" $i 
test "$i - (\"%%02d\", 0) : ${NC}" $i 
test "$i - (\"%%010d\", 0) : ${NC}" $i 
test "$i - (\"%%01d\", -1) : ${NC}" $i 
test "$i - (\"%%02d\", -1) : ${NC}" $i 
test "$i - (\"%%03d\", -1) : ${NC}" $i 
test "$i - (\"%%09d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%010d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%011d\", INT_MAX) : ${NC}" $i 
test "$i - (\"%%01u\", 0) : ${NC}" $i 
test "$i - (\"%%02u\", 0) : ${NC}" $i 
test "$i - (\"%%010u\", 0) : ${NC}" $i 
test "$i - (\"%%01u\", -1) : ${NC}" $i 
test "$i - (\"%%02u\", -1) : ${NC}" $i 
test "$i - (\"%%03u\", -1) : ${NC}" $i 
test "$i - (\"%%09u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011u\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%01x\", 0) : ${NC}" $i 
test "$i - (\"%%02x\", 0) : ${NC}" $i 
test "$i - (\"%%010x\", 0) : ${NC}" $i 
test "$i - (\"%%01x\", -1) : ${NC}" $i 
test "$i - (\"%%02x\", -1) : ${NC}" $i 
test "$i - (\"%%03x\", -1) : ${NC}" $i 
test "$i - (\"%%09x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011x\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%01X\", 0) : ${NC}" $i 
test "$i - (\"%%02X\", 0) : ${NC}" $i 
test "$i - (\"%%010X\", 0) : ${NC}" $i 
test "$i - (\"%%01X\", -1) : ${NC}" $i 
test "$i - (\"%%02X\", -1) : ${NC}" $i 
test "$i - (\"%%03X\", -1) : ${NC}" $i 
test "$i - (\"%%09X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%010X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%011X\", UINT_MAX) : ${NC}" $i 
test "$i - (\"%%0-10d\", 42) : ${NC}" $i 
test "$i - (\"%%-010d\", 42) : ${NC}" $i 
printf "\n\n${DARK_BLUE}Result [$success/$i]${NC}"
