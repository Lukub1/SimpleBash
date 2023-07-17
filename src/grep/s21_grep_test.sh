
# /////////// DONE ///////////
>logTest.txt
for i in  e i v c l n h o ie ve ce le ne he oe iv ic il ni ih io vc vl vn vh vo cl cn ch co ln lh lo nh no ho ivnhe
do
    echo "<---TESTING WITH FLAG '$i'--->" >> logTest.txt
    ./s21_grep -$i grep s21_grep.c > s21_grep.txt
    grep -$i grep s21_grep.c > grep.txt
    diff  -s s21_grep.txt grep.txt >> logTest.txt
done
# 

# 
echo "<---TESTING WITHOUT FLAG--->" >> logTest.txt
    ./s21_grep [A-Z] s21_grep.c > s21_grep.txt
    grep [A-Z] s21_grep.c > grep.txt
    diff -s s21_grep.txt grep.txt >> logTest.txt
# 

for i in f sf cf nf hf 
do
    echo "<---TESTING WITH FLAG '$i'--->" >> logTest.txt
    ./s21_grep -$i gr.txt text.txt > s21_grep.txt
    grep -$i gr.txt text.txt > grep.txt
    diff -s s21_grep.txt grep.txt >> logTest.txt
done


# 
echo "<---TESTING WITH FLAG 's'--->" >> logTest.txt
    ./s21_grep -s regex test.txt > s21_grep.txt
    grep -s regex test.txt > grep.txt
    diff -s s21_grep.txt grep.txt >> logTest.txt
# 

# ​
echo "<---TESTING WITH 2 FILES--->" >> logTest.txt
    ./s21_grep include gr.txt s21_grep.c > s21_grep.txt
    grep include gr.txt s21_grep.c > grep.txt
    diff -s s21_grep.txt grep.txt >> logTest.txt
# 

# 
echo "<---TESTING WITH 3 FILES--->" >> logTest.txt
    ./s21_grep include gr.txt s21_grep.c  text.txt> s21_grep.txt
    grep include gr.txt s21_grep.c  text.txt > grep.txt
    diff -s s21_grep.txt grep.txt >> logTest.txt
# 

# ​
echo "<---TESTING WITH -h FLAG && TWO FILES--->"  >> logTest.txt
    ./s21_grep -h include gr.txt s21_grep.c > s21_grep.txt
    grep -h include gr.txt s21_grep.c > grep.txt
    diff -s s21_grep.txt grep.txt >> logTest.txt
# 
rm -rf s21_grep.txt grep.txt

