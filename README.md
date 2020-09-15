## A study on B tree file stucture

### Brief about the Project

### A little information about File Structures
A **file** is a named collection of related information that is recorded on secondary storage such as magnetic disks, magnetic tapes and optical disks. **File Structure** is a way of organizing files in such a way that inserting and retrieving of record is done efficiently.

#### Accessing records from file
There are different mechanisms for accessing records from files. **Indexed-sequential access** is a mechanism where an *index* is created for each file which contains pointers to various blocks. The *index* is searched sequentially and its pointer is used to access the file directly.

#### Storing records into file
Among the different techniques of storing the records into the files, **variable-length records with delimiters** are most efficiently when used along with index-based accessing. The record-delimiter used to seperate records is hash symbol(#) and the seperator for fields in each record is pipeline symbol(|).

### Different File Structures
#### other FS
#### Tree-based FS
#### one line leading to btree

### B tree
#### defn
#### advantages
#### better trees than Btree

### Sequence set

### Header files used in the program
#### include<graphics.h>
#### include <fstream.h>
#### include <conio.h>
#### include<iostream.h>
#### include <string.h>
#### include <stdlib.h>
#### include<dos.h>
#### include<stdio.h>
#### include<ctype.h>

### Modules of the program
diagram of all modules
what each module do

### Flow of Control
diagram

### Screenshots of output
![menu](https://github.com/catherinewinslet/Student-course-library-using-Btree-File-structure/blob/master/images/1menu.PNG)
![add1](https://github.com/catherinewinslet/Student-course-library-using-Btree-File-structure/blob/master/images/Picture1.png)
![add2](https://github.com/catherinewinslet/Student-course-library-using-Btree-File-structure/blob/master/images/Picture2.png)
![display](https://github.com/catherinewinslet/Student-course-library-using-Btree-File-structure/blob/master/images/Picture3.png)
![search](https://github.com/catherinewinslet/Student-course-library-using-Btree-File-structure/blob/master/images/Picture4.png)
![delete](https://github.com/catherinewinslet/Student-course-library-using-Btree-File-structure/blob/master/images/Picture5.png)
![edit1](https://github.com/catherinewinslet/Student-course-library-using-Btree-File-structure/blob/master/images/Picture6.png)
![edit2](https://github.com/catherinewinslet/Student-course-library-using-Btree-File-structure/blob/master/images/Picture7.png)

### File Content
![FileContent](https://github.com/catherinewinslet/Student-course-library-using-Btree-File-structure/blob/master/images/fileContent.PNG)
![Index](https://github.com/catherinewinslet/Student-course-library-using-Btree-File-structure/blob/master/images/Index.PNG)

#### References
* [Operating System - File System - TutorialsPoint](https://www.tutorialspoint.com/operating_system/os_file_system.htm)
* [Understanding Record Size and Record Delimiters](http://www.3480-3590-data-conversion.com/article-record-size.html#:~:text=A%20%22record%20delimiter%22%20is%20a,be%20able%20to%20separate%20records.)
* [B-Tree Tutorial - An Introduction to B-Trees](https://youtu.be/C_q5ccN84C8)
* [B-Tree: Another Implementation By Java](https://www.codeproject.com/Articles/1158559/B-Tree-Another-Implementation-By-Java)
