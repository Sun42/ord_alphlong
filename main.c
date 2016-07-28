#include <stdlib.h>
#include <stdio.h>

void	ord_alph_long(char *str);
char	**str_to_wordtab(char *str);
void	my_aff_tab(char **tab);
int	count_len(char *str);
int	count_words(char *str);
void	my_strncpy(char *dest, char *src, int nb);
int	is_printable(char c);
void	my_putstr(char *str);
void	my_putchar(char c);
void	ord_tab(char **tab);
int	count_tab(char **tab);
int	my_strlen(char *str);
int	my_strcasecmp(char *str1, char *str2);
int	is_lower(char c);
char	*to_upper(char *str);


int	main(int argc, char **argv)
{
  if (argc != 2)
    exit(-1);
  else
    ord_alph_long(argv[1]);
}

void	ord_alph_long(char *str)
{
  char		**tab;

  tab = str_to_wordtab(str);
  ord_tab(tab);
}

void	ord_tab(char **tab)
{
  int	max; 
  int	i;
  int	j;
  int	t1;
  int	t2;
  char	*swap;

  max = count_tab(tab);
  for (j = (max - 1); j >= 0; j--)
    {
      for (i = 0; i < j; i++)
	{
	  t1 = my_strlen(tab[i]);
	  t2 = my_strlen(tab[i + 1]);
	  if (t1 > t2)
	    {
	      swap = tab[i];
	      tab[i] = tab[i + 1];
	      tab[i + 1] = swap;
	    }
	  else if (t1 == t2)
	    {
	      if (my_strcasecmp(tab[i], tab[i + 1]) > 0)
		{
		  swap = tab[i];
		  tab[i] = tab[i + 1];
		  tab[i + 1] = swap;
		}
	    }
	}
    }
  my_aff_tab(tab);
}

int	my_strcasecmp(char *str1, char *str2)
{
  int	len;
  int	i; 
  char	*strup1;
  char	*strup2;


  strup1 = to_upper(str1);
  strup2 = to_upper(str2);
   i = 0;
  len = my_strlen(str1);
    while (i < len)
    {
      if (strup1[i] > strup2[i])
	{
	  return (1);
	}
      if (strup1[i] < strup2[i])
	{
          return (-1);
        }
      i++;
    }
    return (0);
}	

char	*to_upper(char *str)
{
  int	len;
  char	*new_str;
  int	i;

  i = 0;
  len = my_strlen(str);
  new_str = malloc(sizeof(*str) * (len +1));
  new_str[len] = '\0'; 
  while (i < len)
    {
      if (is_lower(str[i]))
	{
	  new_str[i] = str[i] - 32;
	}
      else			
	{
	  new_str[i] = str[i];
	}
      i++;
    }
  return (new_str);
}


int	is_lower(char c)
{
  if ((c >= 97) && (c <= 122))
    {
      return (1);
    }
  return (0);
}


int my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}

int count_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      i++;
    }
  return (i);
}

void	my_aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      if ( i  < (count_tab(tab) - 1))
	{
	  if (my_strlen(tab[i]) != my_strlen(tab[i + 1]))
	    {
	      my_putchar('\n'); 
	    }
	  else			
	    {
	      my_putchar(' ');
	    }
	}
      else
	{
	  my_putstr("\n");
	}
      i++;
    }
}

char	**str_to_wordtab(char *str)
{
  char	**tab;
  int	nb_words;
  int	i;
  int	word_len;

  i = 0;
  nb_words = count_words(str);
  tab = malloc(sizeof(*tab) * nb_words + 1);  
  while (i < nb_words)
    {
      word_len = count_len(str);
      tab[i] = malloc(sizeof(**tab) * word_len + 1);
      my_strncpy(tab[i], str, word_len);
      str += word_len;
      while (!is_printable(*str) && *str != '\0')
	str++;
      i++;
    }
  tab[nb_words] = 0; 
    return (tab);
}

void	my_strncpy(char *dest, char *src, int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      dest[i] = src[i]; 
      i++;
    }
  dest[i] = '\0';
}

int	count_len(char *str)
{
  int	i;
  
  i = 0;
  while (is_printable(*str))
    {
      i++;
      str++;
    }
  return (i);
}

int	count_words(char *str)
{
  int	cpt;
  int	flag;

  cpt = 0;
  flag  = 0;
  while (*str)
    {
      if (is_printable(*str))
	{
	  if (!flag)
	    {
	      cpt++;
	      flag = 1;
	    }
	}
      else
	{
	  flag = 0;
	}
      str++;
    }
  return (cpt);
}

int	is_printable(char c)
{
  if ((c < '!') || (c > '~'))
    return (0);
  return (1);
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}
