# fdf
#### It is a project to learn about 3d programming. The program takes a map as parameter and creates its 3d representation. MiniLibX library required.

> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;In this project you will discover the basics of graphic programming, and in particular how
to place points in space, how to join them with segments and most importantly how to
observe the scene from a particular viewpoint.

> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;You will also discover your first graphic library: [minilibx](https://harm-smits.github.io/42docs/libs/minilibx). This library was developed
internally and includes the minimum necessary to open a window, light a pixel and deal
with events linked to this window: keyboard and mouse. This project introduces you to
“events” programming. -pedago@42.fr
#
![fdf](https://github.com/osmosx/fdf/blob/master/img/fdf.png)
#
### Usage
Running `make` to generate the fdf executable. You can run the program with `./fdf [valid_fdf_file]`.

A valid fdf file will consist of a matrix of number delimited by spaces. Each number's position represents an (x , y) coordinate with the value of the number itself representing a height (z).

Valid fdf files will always have the same number of elements per row.

Example:
```
$> cat -e 42.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0$
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0$
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0$
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0$
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0$
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0$
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0$
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0$
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0$
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0$
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0$
$>
```
