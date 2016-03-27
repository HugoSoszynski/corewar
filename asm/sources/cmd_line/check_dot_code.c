#include		"parser.h"
#include		"asm.h"

int			is_hexa(char c)
{
  if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'))
    return (0);
  return (-1);
}

int			check_dot_code(char *line)
{
  int			cpt;
  int			val_of_cara;

  cpt = 5;
  val_of_cara = 0;
  while (line[++cpt] != '\0')
    {
      if (val_of_cara == 2)
	{
	  if (line[cpt] != ' ')
	    return (error_message_parser1
		    ("you have error in .code at caracter ", cpt));
	  val_of_cara -= 2;
	}
      else
	{
	  if (is_hexa(line[cpt]) != 0)
	    return (error_message_parser1
		    ("you have error in .code at caracter ", cpt));
	  val_of_cara++;
	}
    }
  return (0);
}
