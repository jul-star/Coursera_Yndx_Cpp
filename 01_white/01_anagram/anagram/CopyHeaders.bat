SET LIB_LEVEL=..\
SET LIB_NAME=Anagram
SET LIB_DIR=Anagram_Lib
SET LIB_PATH=%LIB_LEVEL%%LIB_DIR%

rmdir /S/Q %LIB_PATH%

mkdir  %LIB_PATH%\
mkdir  %LIB_PATH%\include\

copy /Y Anagram.h %LIB_PATH%\include
