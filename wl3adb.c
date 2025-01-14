#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;

	i = 0;
	d = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (d[i] == '\0')
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (strdup(""));
	if (s1 == NULL && s2)
		return (strdup(s2));
	else if (s2 == NULL && s1)
		return (strdup(s1));
	p = (char *)malloc(sizeof(char) * strlen(s1) + strlen(s2) + 1);
	if (!p)
		return (NULL);
	while (s1[i])
		p[j++] = s1[i++];
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = '\0';
	return (p);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}
int tchik(char *buffer , int by)
{
	int	i;

	i = 0;
	
	while(by > i)
	{
		//printf("%s",buffer);
		if(buffer[i] == '\0' || buffer[i] == '\n')	
			return (0);	
		i++;
		//printf("....%d",i);
	}
	
	return(i);
}
int	chlin( char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i])
		i++;
	return (i);
}
#define BUFFER_SIZE 21474836480

char *get_next_line(int fd)
{
	char *buffer;
    // int 	BUFFER_SIZE = 2147483647;
    char    *str = NULL;
	char    *str1 = NULL;
	static char *stati;
	int i = 1;
	int by = 0 ;
	buffer = malloc(BUFFER_SIZE + 1);
	if(stati == 0)
	{
		while(i != 0)
	{
		by = read(fd,buffer,BUFFER_SIZE);
		buffer[by] = '\0';
		i = tchik(buffer,by);
		str = ft_strjoin(str,buffer);
		
	}
	i = chlin(str);
		// if (str[i])
		// 	i++;
	str1 = ft_substr(str,0,i);
	//printf("str1 = %s...\n",str1);
	stati = ft_substr(str,i,ft_strlen(str) - i);
	//printf("1 %s 1",str1);
	}
	else
	{
	 	//printf("11111111111111111");
			str = ft_strjoin(str,stati);
			//printf(">>%s...>",str);
			if(tchik(str,ft_strlen(str)) == 0)
			{
				i = chlin(stati);
				str1 = ft_substr(str,0,i);
				stati = ft_substr(str,i,ft_strlen(str) - i);
			}
			else
			{
				while(i != 0)
				{
				by = read(fd,buffer,BUFFER_SIZE);
				buffer[by] = '\0';
				i = tchik(buffer,by);
				str = ft_strjoin(str,buffer);
		
				}
				i = chlin(str);
				// if (str[i])
				// 	i++;
				str1 = ft_substr(str,0,i);
				//printf("str1 = %s...\n",str1);
				stati = ft_substr(str,i,ft_strlen(str) - i);
				//printf("1 %s 1",stati);
			}
		}

	return(str1);
}
int main()
{
	int fd = open("abdo.txt",O_RDONLY);
	char *line;
	if(fd == -1)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
	}
	printf("%s", line);
	
	close(fd);
}