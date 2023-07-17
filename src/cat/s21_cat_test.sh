> logTest.txt
echo "TEST cat" >> logTest.txt
./s21_cat bytes.txt > s21_cat_test.txt
cat bytes.txt > cat_test.txt
diff -s s21_cat_test.txt cat_test.txt >> logTest.txt

for option in b be bn bs bt e en es et n ns nt s st t v 
do 
echo "TEST :$option" >> logTest.txt
./s21_cat -$option bytes.txt > s21_cat_test.txt
cat -$option bytes.txt > cat_test.txt
diff -s s21_cat_test.txt cat_test.txt >> logTest.txt
done

# echo "TEST :-E" >> logTest.txt
# ./s21_cat -E bytes.txt > s21_cat_test.txt

# echo "TEST :-T" >> logTest.txt
# ./s21_cat -T bytes.txt > s21_cat_test.txt

echo "TEST :--number-nonblank" >> logTest.txt
./s21_cat --number-nonblank bytes.txt > s21_cat_test.txt
cat -b bytes.txt > cat_test.txt
diff -s s21_cat_test.txt cat_test.txt >> logTest.txt

echo "TEST :--number" >> logTest.txt
./s21_cat --number bytes.txt > s21_cat_test.txt
cat -n bytes.txt > cat_test.txt
diff -s s21_cat_test.txt cat_test.txt >> logTest.txt

echo "TEST :--squeeze-blank" >> logTest.txt
./s21_cat --squeeze-blank bytes.txt > s21_cat_test.txt
cat -s bytes.txt > cat_test.txt
diff -s s21_cat_test.txt cat_test.txt >> logTest.txt

rm -rf cat_test.txt s21_cat_test.txt
