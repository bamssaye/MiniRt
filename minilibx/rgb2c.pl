#!/usr/bin/perl
#
## color2c.pl for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 16:33:46 2004 Olivier Crouzet
## Last update Tue Oct  5 16:36:11 2004 Olivier Crouzet
##


#
# Generate a .c file with encoded colors, from the XFree86 color.txt file.
#

open(color, "/usr/X11/lib/X11/color.txt");


printf("/*\n** This is a generated file with color2c.pl and color.txt from\n");
printf("** the XFree86 distribution.\n*/\n\n");
printf("struct s_col_name mlx_col_name[] =\n{\n");

while (<color>)
{
    @tab = split;
    if ($tab[0] ne "!")
    {
	$color = $tab[3];
	if ("$tab[4]" ne "")
	{
	    $color = "$tab[3] $tab[4]";
	}
	printf(" { \"%s\" , 0x%x },\n", $color, $tab[0]*65536+$tab[1]*256+$tab[2]);
    }
}

printf(" { 0, 0 }\n};\n");
