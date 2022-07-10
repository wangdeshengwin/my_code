#########################################################################
# File Name:    run_make.sh
# Author:       wangdesheng
# Mail:         wangdesheng2008@163.com
# Created Time: 2022年04月07日 星期四 22时10分34秒
#########################################################################
#!/bin/bash
rm -rvf *.out
astyle --style=allman --mode=c *.cpp 
rm -rvf *.cpp.orig
