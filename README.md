#AES256 with openssl in C Language

1. 빌드방법: ~/openssl 디렉터리에서 make 명령어 실행
2. 오류메시지
  1) "missing separator (did you mean TAB instead of 8 spaces?)" 발생시에는 Makefile, makefile 에서 공백->TAB키 문자로 변경
![image](https://user-images.githubusercontent.com/57746289/195518552-a722f824-b950-4b19-8adc-62a9bf81389e.png)

  2) "error while loading shared libraries: libaes.so: cannot open shared object file: No such file or directory" 발생시에는 다음 명령어 진행
     => export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/openssl/lib
