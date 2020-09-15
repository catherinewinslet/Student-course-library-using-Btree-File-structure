## A study on B tree file stucture

The project is a menu-driven application for student courses database where the user is able to perform operations like adding a course, searching for a courses or deleting a course, etc.

### Brief about File Structures
A **file** is a named collection of related information that is recorded on secondary storage such as magnetic disks, magnetic tapes and optical disks. **File Structure** is a way of organizing files in such a way that inserting and retrieving of record is done efficiently.

#### Accessing records from file
There are different mechanisms for accessing records from files. **Indexed-sequential access** is a mechanism where an *index* is created for each file which contains pointers to various blocks. The *index* is searched sequentially and its pointer is used to access the file directly.

#### Storing records into file
Among the different techniques of storing the records into the files, **variable-length records with delimiters** are most efficiently when used along with index-based accessing. The record-delimiter used to seperate records is hash symbol(#) and the seperator for fields in each record is pipeline symbol(|).

#### Tree File Structures
A tree structure is the most common directory structure. The tree has a **root** directory, and every file in the system have a unique path.
This generalization allows the user to create there own subdirectories and to organize on their files accordingly.
![Tree structure](https://media.geeksforgeeks.org/wp-content/uploads/222-3-1.png)

##### BINARY SEARCH TREE
In computer science, a binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree whose internal nodes each store a key greater than all the keys in the node's left subtree and less than those in its right subtree.

Problems in BST arises when the node inserting into the tree are always greater/lesser than the root node and child nodes. In this case, we get a skewed tree which is not ideal for accessing and inserting.

##### SELF- BALANCING BINARY SEARCH TREES
We can solve this problem using self-balancing trees. In computer science, a self-balancing binary search tree is any node-based binary search tree that automatically keeps its height small in the face of arbitrary item insertions and deletions.

**B-Tree** is a self-balancing search tree. The main idea is to reduce the number of disk accesses. Most of the tree operations like searching, inserting, deleting require O(h) disk accesses where h is the height of the tree. B-tree is a wide rather than a tall tree. The height of B-Trees is kept low by putting maximum possible keys in a B-Tree node. Since the height of the B-tree is low so efficiency of the operations are significantly higher compared to other balanced BST like AVL Tree, Red-Black Tree, ..etc.

### Header files used in the program
```include<graphics.h>``` - provides access to a simple graphics library that makes it possible to draw lines, polygons, images, and strings on a graphical window.</br>
```include <fstream.h>``` - input/output stream class to operate on files.</br>
```include <conio.h>``` - declares several useful library functions for performing "console input and output" from a program.</br>
```include<iostream.h>``` - defines the standard input/output stream objects</br>
```include <string.h>``` - set of functions implementing operations on strings in its standard library.</br>
```include <stdlib.h>``` - defines four variable types, several macros, and various functions for performing general functions.</br>
```include<dos.h>``` - contains functions for handling interrupts, producing sound, date and time functions etc.</br>
```include<ctype.h>``` - several functions that are useful for testing and mapping characters. </br>

### Flow of Control
![flow of control](https://github.com/catherinewinslet/Student-course-library-using-Btree-File-structure/blob/master/images/Group%2015.png)

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
* Wikipedia [donate](https://donate.wikimedia.org/w/index.php?title=Special:LandingPage&country=IN&uselang=en&utm_medium=sidebar&utm_source=donate&utm_campaign=C13_en.wikipedia.org)
