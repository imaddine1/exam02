#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

// count the length of string
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}
// copy of string
char	*ft_strdup(char	*str)
{
	int		i;
	char	*cpy;

	cpy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!cpy)
		return (0);
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}
// find line inside string
int	findline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
// join two strings
char	*ft_strjoin(char *f, char *s)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = malloc (sizeof(char) * (ft_strlen(f) + ft_strlen(s) + 1));
	while (f[i])
	{
		join[i] = f[i];
		i++;
	}
	while (s[j])
	{
		join[i] = s[j];
		j++;
		i++;
	}
	join[i] = 0;
	free (f);
	return (join);
}
// take what is befor \n
char	*bf_line(char *str)
{
	int		i;
	int		j;
	char	*before;

	i = 0;
	j = 0;
	while(str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	before = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		before[j] = str[j];
		j++;
	}
	before[j] = 0;
	return (before);
}
// take what is after \n
char	*af_line(char *str)
{
	int		i;
	int		j;
	char	*after;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	if (str[i] == '\0')
	{
		free (str);
		return (0);
	}
	after = malloc(sizeof(char) * (ft_strlen(&str[i]) + 1));
	while (str[i])
	{
		after[j] = str[i];
		j++;
		i++;	
	}
	after[j] = 0;
	free (str);
	return (after);
}

// this the main function
char	*get_next_line(int fd)
{
	static char	*buff;
	char		*old;
	char		*new;
	int			i;

	i = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	new = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!new)
		return (0);
	if (!buff)
	{
		i = read (fd, new, BUFFER_SIZE);
		if (i == 0 || i == -1)
		{
			free (new);
			return (0);
		}
		new[i] = 0;
		buff = ft_strdup(new);
	}
	while (findline(buff) && i)
	{
		i = read(fd, new, BUFFER_SIZE);
		new[i] = 0;
		buff = ft_strjoin(buff, new);
	}
	free (new);
	old = bf_line(buff);
	buff = af_line(buff);
	return (old);
}


// this is main

int	main()
{
	int	fd;

	fd = open("try.txt", 0);
	printf ("%s",get_next_line(fd));
	printf ("%s",get_next_line(fd));
	printf ("%s",get_next_line(fd));
	printf ("%s",get_next_line(fd));
	printf ("%s",get_next_line(fd));
	printf ("%s",get_next_line(fd));
	return (0);
}

