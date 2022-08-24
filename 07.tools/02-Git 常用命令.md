# Git 常用命令

[TOC]

## 1、创建并切换分支

-  git checkout -b < branch >



## 2、git stash

可用来暂存当前正在进行的工作

- 先git stash 暂存代码
- 再pull新代码或切换分支或其他
- 再git stash pop，继续开发



## 3、仓库没有master分支

执行 git clone -b dev xxx，使用-b dev 表明要clone的分支

git clone默认clone master分支，如果仓库没有master分支，则会拉取空项目。



## 4、本地创建分支推送至远程

**git push** 命令用于从将本地的分支版本上传到远程并合并，大致分为两种情况。

(1) 本地分支名与远程分支名不同

- git push <远程主机名> <本地分支名>:<远程分支名>

(2) 本地分支名与远程分支名相同，则可以省略**冒号**：

- git push <远程主机名> <本地分支名>



**注意点：**

- <远程主机名> 一般为 **origin**；

- push的时候没有必要checkout至需要push的本地分支，在master分支直接执行上述语句即可。



## 5、命令行push代码(origin)

- git add.
- git commit -m ""
- git push **origin** branch_name



## 6、feature 落后于 master

- 先checkout到**master** 拉取最新代码
- git merge master
- git push



## 7、回退至上一版本

- 本地回退

  git reset --hard HEAD^

- 强制到远程

  git push origin HEAD --force



## 8、撤销merge

- 直接本地回退即可 git reset --hard HEAD^



## 9、[撤销commit](https://blog.csdn.net/c46550/article/details/116574128)

- git reset --soft HEAD^