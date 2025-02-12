# 結果
## 課題1
* 圧縮
```
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time xz -d gakumonno_susume.txt.xz 

real	0m0.044s
user	0m0.025s
sys	0m0.017s
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time gzip -d gakumonno_susume.txt.xz 
gzip: gakumonno_susume.txt.xz.gz: No such file or directory

real	0m0.006s
user	0m0.006s
sys	0m0.001s
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time gzip -d gakumonno_susume.txt.gz 

real	0m0.017s
user	0m0.012s
sys	0m0.006s
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time bzip2 -d gakumonno_susume.txt.bz2 

real	0m0.064s
user	0m0.055s
sys	0m0.008s
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time unzip gakumonno_susume.txt.zip 
Archive:  gakumonno_susume.txt.zip
  inflating: gakumonno_susume.txt    

real	0m0.026s
user	0m0.013s
sys	0m0.009s
```

* サイズ -
```
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ ls -lh
合計 472K
-rw-r--r-- 1 j22126 j22126 184K  7月 18 10:30 gakumonno_susume.txt
-rw-r--r-- 1 j22126 j22126  63K  7月 18 10:30 gakumonno_susume.txt.bz2
-rw-r--r-- 1 j22126 j22126  79K  7月 18 10:30 gakumonno_susume.txt.gz
-rw-r--r-- 1 j22126 j22126  64K  7月 18 10:30 gakumonno_susume.txt.xz
-rw-r--r-- 1 j22126 j22126  79K  7月 18 10:31 gakumonno_susume.txt.zip
```

* 解凍
```
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time xz -d gakumonno_susume.txt.xz

real	0m0.044s
user	0m0.025s
sys	0m0.017s
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time gzip -d gakumonno_susume.txt.gz

real	0m0.017s
user	0m0.012s
sys	0m0.006s
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time bzip2 -d gakumonno_susume.txt.bz2

real	0m0.064s
user	0m0.055s
sys	0m0.008s
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time unzip gakumonno_susume.txt.zip
Archive:  gakumonno_susume.txt.zip
  inflating: gakumonno_susume.txt

real	0m0.026s
user	0m0.013s
sys	0m0.009s
```

## 課題2
* 圧縮前サイズ 
```
j22126@raspberrypi:~/3J_jikken/IDE/tmp/aozorabunko_text_files $ ls -lh
合計 236K
-rw-r--r-- 1 j22126 j22126 3.8K 10月 22  2005 a_aki.txt
-rw-r--r-- 1 j22126 j22126  27K  2月  1  2016 aito_bini_tsuite.txt
-rw-r--r-- 1 j22126 j22126  17K 10月 23  2005 anitachi.txt
-rw-r--r-- 1 j22126 j22126 1.9K 11月 15  2006 aomori.txt
-rw-r--r-- 1 j22126 j22126 2.3K  6月 16  2004 aru_chukoku.txt
-rw-r--r-- 1 j22126 j22126  19K 10月 23  2005 aruto_haideruberuhi.txt
-rw-r--r-- 1 j22126 j22126 7.1K  2月 19  2004 asa.txt
-rw-r--r-- 1 j22126 j22126 4.7K  3月  4  2004 asamasiki_mono.txt
-rw-r--r-- 1 j22126 j22126  885  4月  7  2009 atarashii_katachino.txt
-rw-r--r-- 1 j22126 j22126 4.6K  2月  1  2016 i_can_speak.txt
-rw-r--r-- 1 j22126 j22126  22K  6月  8  2004 ibuse_masuji_koki.txt
-rw-r--r-- 1 j22126 j22126 3.1K  7月 12  2016 ichimon_itto.txt
-rw-r--r-- 1 j22126 j22126 5.8K  7月 12  2016 ichinichino_roku.txt
-rw-r--r-- 1 j22126 j22126  579  4月  7  2009 inakamono.txt
-rw-r--r-- 1 j22126 j22126  29K  2月 23  2016 inka.txt
-rw-r--r-- 1 j22126 j22126 2.7K  7月 12  2016 ippo_zenshin_niho_taikyaku.txt
-rw-r--r-- 1 j22126 j22126 7.0K 10月 24  2005 itto.txt
-rw-r--r-- 1 j22126 j22126  42K  5月 22  2011 viyon.txt
```
* 圧縮
```
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time xz aozorabunko_text_files.tar -k

real	0m0.290s
user	0m0.221s
sys	0m0.068s
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time gzip aozorabunko_text_files.tar -k

real	0m0.110s
user	0m0.103s
sys	0m0.006s
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time bzip2 aozorabunko_text_files.tar -k

real	0m0.100s
user	0m0.087s
sys	0m0.010s
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time zip aozorabunko_text_files.tar.zip aozorabunko_text_files.tar
  adding: aozorabunko_text_files.tar (deflated 59%)

real	0m0.089s
user	0m0.083s
sys	0m0.004s
```
* 圧縮後サイズ
```
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ ls -lh
合計 560K
drwxr-xr-x 2 j22126 j22126 4.0K  4月 18  2023 aozorabunko_text_files
-rw-r--r-- 1 j22126 j22126 220K  7月 18 11:21 aozorabunko_text_files.tar
-rw-r--r-- 1 j22126 j22126  73K  7月 18 11:21 aozorabunko_text_files.tar.bz2
-rw-r--r-- 1 j22126 j22126  90K  7月 18 11:21 aozorabunko_text_files.tar.gz
-rw-r--r-- 1 j22126 j22126  75K  7月 18 11:21 aozorabunko_text_files.tar.xz
-rw-r--r-- 1 j22126 j22126  90K  7月 18 11:23 aozorabunko_text_files.tar.zip
```
* 圧縮後展開
```
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time xz -dk aozorabunko_text_files.tar.xz

real	0m0.052s
user	0m0.031s
sys	0m0.018s
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time gzip -dk aozorabunko_text_files.tar.gz

real	0m0.024s
user	0m0.016s
sys	0m0.006s
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time bzip2 -dk aozorabunko_text_files.tar.bz2

real	0m0.030s
user	0m0.029s
sys	0m0.000s
j22126@raspberrypi:~/3J_jikken/IDE/tmp $ time unzip aozorabunko_text_files.tar.zip 
Archive:  aozorabunko_text_files.tar.zip
  inflating: aozorabunko_text_files.tar  

real	0m0.010s
user	0m0.007s
sys	0m0.003s
```


## 課題3
* 展開
```
j22126@raspberrypi:~/3J_jikken/IDE $ time xz -d 2023-02-21-raspios-bullseye-armhf-lite.img.xz

real	0m55.167s
user	0m48.348s
sys	0m6.403s
```
* サイズ
```
j22126@raspberrypi:~/3J_jikken/IDE/imagetmp $ ls -lh
合計 1.6G
drwxr-xr-x 2 j22126 j22126 4.0K  7月 18 10:56 .
drwxr-xr-x 7 j22126 j22126 4.0K  7月 18 11:26 ..
-rw-r--r-- 1 j22126 j22126 1.9G  7月 18 10:21 2023-02-21-raspios-bullseye-armhf-lite.img
-rw-r--r-- 1 j22126 j22126 380M  7月 18 10:21 2023-02-21-raspios-bullseye-armhf-lite.img.xz
```

* 圧縮
```
j22126@raspberrypi:~/3J_jikken/IDE/imagetmp $ time xz 2023-02-21-raspios-bullseye-armhf-lite.img -k

real	25m9.820s
user	25m0.390s
sys	0m7.661s
```

## 課題5
```
j22126@raspberrypi:~/3J_jikken/IDE/shell_scripts/tmp$ bash classify_picture.sh | head -n 10
test_text_files_1/20230312155053.txt
mkdir -p "2023/2023-0312"
cp "20230312155053.txt" "2023/2023-0312"
test_text_files_1/20230312152507.txt
mkdir -p "2023/2023-0312"
cp "20230312152507.txt" "2023/2023-0312"
test_text_files_1/20230312152748.txt
mkdir -p "2023/2023-0312"
cp "20230312152748.txt" "2023/2023-0312"
test_text_files_1/20230312155115.txt



j22126@raspberrypi:~/3J_jikken/IDE/shell_scripts/tmp$ bash classify_picture.sh | head -n 10
test_text_files_2/20230301121325.txt
mkdir -p "2023/2023-0301"
cp "20230301121325.txt" "2023/2023-0301"
test_text_files_2/20230302072805.txt
mkdir -p "2023/2023-0302"
cp "20230302072805.txt" "2023/2023-0302"
test_text_files_2/20230301214038.txt
mkdir -p "2023/2023-0301"
cp "20230301214038.txt" "2023/2023-0301"
test_text_files_2/20230303211601.txt



j22126@raspberrypi:~/3J_jikken/IDE/shell_scripts/tmp$ cat classify_result | head -n 20
2023
├── 2023-0101
│   ├── 20230101002114.txt
│   ├── 20230101011948.txt
│   ├── 20230101014908.txt
│   ├── 20230101031916.txt
│   ├── 20230101032524.txt
│   ├── 20230101042546.txt
│   ├── 20230101044106.txt
│   ├── 20230101055433.txt
│   ├── 20230101060708.txt
│   ├── 20230101065535.txt
│   ├── 20230101065824.txt
│   ├── 20230101065928.txt
│   ├── 20230101084538.txt
│   ├── 20230101090243.txt
│   ├── 20230101102841.txt
│   ├── 20230101110205.txt
│   ├── 20230101112143.txt
│   ├── 20230101114301.txt
```

# 課題4
``` 
$ bash homesize.sh 
6.9G	/home/j22126


$ bash rootls.sh 
root directory
合計 68
lrwxrwxrwx   1 root root     7  5月  3  2023 bin -> usr/bin
drwxr-xr-x   5 root root  4096  1月  1  1970 boot
drwxr-xr-x  18 root root  4200  9月 20 11:56 dev
drwxr-xr-x 136 root root 12288  9月 24 16:01 etc
drwxr-xr-x   3 root root  4096 10月  6  2023 home
lrwxrwxrwx   1 root root     7  5月  3  2023 lib -> usr/lib
drwx------   2 root root 16384  5月  3  2023 lost+found
drwxr-xr-x   2 root root  4096  5月  3  2023 media
drwxr-xr-x   2 root root  4096  5月  3  2023 mnt
drwxr-xr-x   5 root root  4096 10月 11  2023 opt
dr-xr-xr-x 256 root root     0  1月  1  1970 proc
drwx------   4 root root  4096  9月 24 16:05 root
drwxr-xr-x  30 root root   860  9月 20 11:57 run
lrwxrwxrwx   1 root root     8  5月  3  2023 sbin -> usr/sbin
drwxr-xr-x   2 root root  4096  5月  3  2023 srv
dr-xr-xr-x  12 root root     0  1月  1  1970 sys
drwxrwxrwt  19 root root  4096  9月 24 16:51 tmp
drwxr-xr-x  11 root root  4096  5月  3  2023 usr
drwxr-xr-x  11 root root  4096  5月  3  2023 var


$ bash var.sh 
/home/


$ bash quote.sh
I came from $country
I came from Japan


$ bash touch_date.sh
$ ls -lh
合計 48K
drwxr-xr-x 2 j22126 j22126 4.0K  9月 24 17:33 .
drwxr-xr-x 4 j22126 j22126 4.0K  9月 21 17:05 ..
-rw-r--r-- 1 j22126 j22126    0  9月 24 17:33 2024-09-24
-rw-r--r-- 1 j22126 j22126   62  7月 25 10:05 for-touch.sh
-rw-r--r-- 1 j22126 j22126   57  7月 25 10:04 for.sh
-rw-r--r-- 1 j22126 j22126   32  7月 25 09:47 homesize.sh
-rw-r--r-- 1 j22126 j22126   70  7月 25 10:00 if-bin.sh
-rw-r--r-- 1 j22126 j22126   98  7月 25 10:03 if-int.sh
-rw-r--r-- 1 j22126 j22126   83  7月 25 09:55 quote.sh
-rwxrw-r-x 1 j22126 j22126   45  7月 25 09:47 rootls.sh
-rw-r--r-- 1 j22126 j22126   60  7月 25 09:57 touch_date.sh
-rw-r--r-- 1 j22126 j22126   40  7月 25 09:49 var.sh
-rw-r--r-- 1 j22126 j22126   70  7月 25 10:08 while.sh


$ bash if-bin.sh 
NG


$ bash if-int.sh 1 5


$ bash for.sh
aaa
bbb
ccc


$ bash for-touch.sh
ls
合計 48K
drwxr-xr-x 2 j22126 j22126 4.0K  9月 24 17:35 .
drwxr-xr-x 4 j22126 j22126 4.0K  9月 21 17:05 ..
-rw-r--r-- 1 j22126 j22126    0  9月 24 17:35 0001.txt
-rw-r--r-- 1 j22126 j22126    0  9月 24 17:35 0002.txt
-rw-r--r-- 1 j22126 j22126    0  9月 24 17:35 0003.txt
-rw-r--r-- 1 j22126 j22126    0  9月 24 17:35 0004.txt
-rw-r--r-- 1 j22126 j22126    0  9月 24 17:35 0005.txt
-rw-r--r-- 1 j22126 j22126    0  9月 24 17:33 2024-09-24
-rw-r--r-- 1 j22126 j22126   62  7月 25 10:05 for-touch.sh
-rw-r--r-- 1 j22126 j22126   57  7月 25 10:04 for.sh
-rw-r--r-- 1 j22126 j22126   32  7月 25 09:47 homesize.sh
-rw-r--r-- 1 j22126 j22126   70  7月 25 10:00 if-bin.sh
-rw-r--r-- 1 j22126 j22126   98  9月 24 17:34 if-int.sh
-rw-r--r-- 1 j22126 j22126   83  7月 25 09:55 quote.sh
-rwxrw-r-x 1 j22126 j22126   45  7月 25 09:47 rootls.sh
-rw-r--r-- 1 j22126 j22126   60  7月 25 09:57 touch_date.sh
-rw-r--r-- 1 j22126 j22126   40  7月 25 09:49 var.sh
-rw-r--r-- 1 j22126 j22126   70  7月 25 10:08 while.sh


$ bash while.sh
1
3
5
7
9
```
